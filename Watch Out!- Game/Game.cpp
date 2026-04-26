#include "Game.h"
#include "Constants.h"
#include <iostream>
#include "Exceptions.h"
#include <algorithm>
#include "PowerUp.h"
#include <random>

// 1. Constructorul devine simplu, fără 'window(...)'
Game::Game() : run(true) {
    initAliens();
}

Game::~Game() {}

// 2. Funcția Draw folosește fereastra primită din main
void Game::Draw(sf::RenderWindow& window) {
    spaceship.draw(window);
    for (auto& entity : allEntities) {
        entity->draw(window);
    }
    for (auto& laser : spaceship.getLasers()) laser->draw(window);
    for (auto& laser : alienLasers) laser->draw(window);
}

void Game::HandleInput() {

    if (!run) return; // Blocăm controlul navei dacă jocul s-a terminat

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        spaceship.MoveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        spaceship.MoveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        spaceship.fire();
    }
}

void Game::Update() {
    if (!run) return;

    spaceship.update();
    spaceship.updatePowerUps();

    // 2. Generare aleatorie Power-Ups (șansă mică pe fiecare frame)
    if (rand() % 1000 == 0) {
        float spawnX = static_cast<float>(rand() % (Config::SCREEN_WIDTH - 50) + 25);
        auto isClone = (rand() % 2 == 0);

        if (isClone) {
            auto pUp = std::make_shared<ClonePowerUp>(spawnX, -30.f);
            allEntities.push_back(pUp);
        } else {
            auto pUp = std::make_shared<SpeedPowerUp>(spawnX, -30.f);
            allEntities.push_back(pUp);
        }
    }

    bool hitEdge = false;

    // DOWNCASTING pentru a verifica marginile alienilor
    // 2. Update și Management Entități (Alieni și Power-Ups)
    for (auto it = allEntities.begin(); it != allEntities.end(); ) {
        auto entity = *it;
        entity->update();

        auto pUp = std::dynamic_pointer_cast<PowerUp>(entity);
        auto alien = std::dynamic_pointer_cast<Alien>(entity);

        if (pUp) {
            auto shipBounds = spaceship.getBounds();
            auto pUpBounds = pUp->getBounds();
            auto isCollected = shipBounds.findIntersection(pUpBounds);
            auto isOut = pUp->isExpired();

            if (isCollected) {
                pUp->applyEffect(spaceship);
                it = allEntities.erase(it);
                continue;
            }

            if (isOut) {
                it = allEntities.erase(it);
                continue;
            }
        }

        if (alien) {
            auto right = alien->getRightEdge();
            auto left = alien->getLeftEdge();

            if (right > Config::SCREEN_WIDTH || left < 0) {
                hitEdge = true;
            }
        }
        ++it;
    }

    if (hitEdge) {
        Alien::changeDirection(); // Static
        for (auto& entity : allEntities) {
            if (auto a = std::dynamic_pointer_cast<Alien>(entity))
                a->moveDown(20.f);
        }
    }

    /// 4. Tragere Alien
    auto timeElapsed = alienFireClock.getElapsedTime().asSeconds();
    if (timeElapsed > fireInterval && !allEntities.empty()) {
        std::vector<std::shared_ptr<Alien>> aliensOnly;
        for (auto& e : allEntities) {
            auto a = std::dynamic_pointer_cast<Alien>(e);
            if (a) aliensOnly.push_back(a);
        }

        if (!aliensOnly.empty()) {
            int randomIndex = rand() % aliensOnly.size();
            auto shooter = aliensOnly[randomIndex];
            auto firePos = shooter->getCenter();
            auto newLaser = std::make_shared<Laser>(firePos, 5.f);
            alienLasers.push_back(newLaser);
        }
        alienFireClock.restart();
    }


    auto& lasers = spaceship.getLasers();
    lasers.erase(std::remove_if(lasers.begin(), lasers.end(), [](const std::shared_ptr<Laser>& l) {
        l->update();
        return !l->isActive();
    }), lasers.end());

    alienLasers.erase(std::remove_if(alienLasers.begin(), alienLasers.end(), [](auto& l) {
        l->update();
        return !l->isActive();
    }), alienLasers.end());

    CheckForCollisions();

    // 5. CONDIȚIE VICTORIE
    if (allEntities.empty()) {
        run = false;
        std::cout << "FELICITARI! Ai castigat!" << std::endl;
    }
}

void Game::initAliens() {
    allEntities.clear(); // Folosim numele corect din clasa ta
    for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 10; column++) {
            float x = 75.f + column * 55.f;
            float y = 110.f + row * 55.f;

            int alienType;
            if (row == 0) alienType = 3;
            else if (row <= 2) alienType = 2;
            else alienType = 1;

            // Adăugăm în allEntities
            allEntities.push_back(std::make_shared<Alien>(x, y, alienType));
        }
    }
}


void Game::CheckForCollisions() {
    auto& sLasers = spaceship.getLasers();

    // Laserele navei lovesc alienii
    // 1. Laserele navei vs Alieni
    for (auto lIt = sLasers.begin(); lIt != sLasers.end(); ) {
        auto laser = *lIt;
        bool hitSomething = false;

        for (auto eIt = allEntities.begin(); eIt != allEntities.end(); ) {
            auto entity = *eIt;
            auto alienTarget = std::dynamic_pointer_cast<Alien>(entity);

            // Verificăm DACĂ e alien (dacă e Power-Up, ignorăm)
            if (alienTarget) {
                auto lBounds = laser->getBounds();
                auto aBounds = alienTarget->getBounds();
                auto isHit = lBounds.findIntersection(aBounds);

                if (isHit) {
                    eIt = allEntities.erase(eIt);
                    hitSomething = true;
                    break;
                } else {
                    ++eIt;
                }
            } else {
                ++eIt;
            }
        }
        if (hitSomething) lIt = sLasers.erase(lIt);
        else ++lIt;
    }

    // 2. Laserele alienilor vs Nava
    for (auto& laser : alienLasers) {
        auto lBounds = laser->getBounds();
        auto sBounds = spaceship.getBounds();
        auto hitShip = lBounds.findIntersection(sBounds);

        if (hitShip) {
            run = false;
            std::cout << "GAME OVER: Ai fost impuscat!" << std::endl;
            return;
        }
    }

    // Alienii ating nava direct sau trec de ea (GAME OVER)
    for (auto& entity : allEntities) {
        auto alien = std::dynamic_pointer_cast<Alien>(entity);

        // VERIFICARE CRITICĂ: Mai întâi vedem dacă e alien, apoi îi cerem datele
        if (alien) {
            auto aBounds = alien->getBounds();
            auto sBounds = spaceship.getBounds();

            auto collisionWithShip = aBounds.findIntersection(sBounds);
            // Verificăm dacă partea de jos a alienului a trecut de nava (folosind poziția)
            auto passedLimit = (aBounds.position.y + aBounds.size.y >= sBounds.position.y);

            if (collisionWithShip || passedLimit) {
                run = false;
                std::cout << "GAME OVER: Invazia a reusit!" << std::endl;
                return;
            }
        }
    }
}