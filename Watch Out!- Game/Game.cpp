#include "Game.h"
#include "Constants.h"
#include <iostream>
#include "Exceptions.h"
#include <algorithm>

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
    bool hitEdge = false;

    // DOWNCASTING pentru a verifica marginile alienilor
    for (auto& entity : allEntities) {
        entity->update();
        auto alienPtr = std::dynamic_pointer_cast<Alien>(entity); // Cerința 2.e.2
        if (alienPtr) {
            if (alienPtr->getRightEdge() > Config::SCREEN_WIDTH || alienPtr->getLeftEdge() < 0) {
                hitEdge = true;
            }
        }
    }

    if (hitEdge) {
        Alien::changeDirection(); // Static
        for (auto& entity : allEntities) {
            if (auto a = std::dynamic_pointer_cast<Alien>(entity))
                a->moveDown(20.f);
        }
    }

    // 2. Logică Tragere Alien (Aici era lipsa)
    if (alienFireClock.getElapsedTime().asSeconds() > fireInterval && !allEntities.empty()) {
        int randomIndex = rand() % allEntities.size();
        auto shooter = allEntities[randomIndex];
        auto bounds = shooter->getBounds();
        sf::Vector2f firePos(
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y
    );

        alienLasers.push_back(std::make_shared<Laser>(firePos, 5.f));
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
    for (auto lIt = sLasers.begin(); lIt != sLasers.end(); ) {
        bool hit = false;
        for (auto eIt = allEntities.begin(); eIt != allEntities.end(); ) {
            if ((*lIt)->getBounds().findIntersection((*eIt)->getBounds())) {
                eIt = allEntities.erase(eIt);
                hit = true;
                break;
            } else ++eIt;
        }
        if (hit) lIt = sLasers.erase(lIt);
        else ++lIt;
    }

    // Laserele alienilor lovesc nava (GAME OVER)
    for (auto it = alienLasers.begin(); it != alienLasers.end(); ) {
        if ((*it)->getBounds().findIntersection(spaceship.getBounds())) {
            run = false;
            std::cout << "GAME OVER: Ai fost impuscat!" << std::endl;
            return;
        } else {
            ++it;
        }
    }

    // Alienii ating nava direct sau trec de ea (GAME OVER)
    for (auto& entity : allEntities) {
        auto bounds = entity->getBounds();
        if (bounds.findIntersection(spaceship.getBounds()) ||
            bounds.position.y + bounds.size.y > spaceship.getBounds().position.y) {
            run = false;
            std::cout << "GAME OVER: Alienii te-au invadat!" << std::endl;
            return;
            }
    }
}