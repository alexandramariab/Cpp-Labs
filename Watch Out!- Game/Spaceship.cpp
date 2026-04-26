#include "Spaceship.h"
#include "Constants.h"
#include "Exceptions.h"
#include <iostream>

// Constructorul: Apelăm constructorul clasei de bază Entity
Spaceship::Spaceship() : Entity(0.f, 0.f), image(), sprite(image) {

    if (!image.loadFromFile("Graphics/spaceship.png")) {
        throw ResourceException("Graphics/spaceship.png"); // Cerința 3.b
    }

    sprite.setTexture(image, true);

    // Calculăm poziția folosind variabila 'position' moștenită din Entity
    position.x = (static_cast<float>(Config::SCREEN_WIDTH) - image.getSize().x) / 2.f;
    position.y = static_cast<float>(Config::SCREEN_HEIGHT) - image.getSize().y - 20.f;
    sprite.setPosition(position);
}

// Constructor de copiere
Spaceship::Spaceship(const Spaceship& other) : Entity(other), image(other.image), sprite(image) {
    sprite.setTexture(image, true);
    sprite.setPosition(position);
}

// Funcția swap (ajutătoare pentru operator=)
void swap(Spaceship& first, Spaceship& second) noexcept {
    using std::swap;
    swap(first.position, second.position);
    swap(first.image, second.image);
    first.sprite.setTexture(first.image, true);
    second.sprite.setTexture(second.image, true);
}

Spaceship& Spaceship::operator=(Spaceship other) {
    swap(*this, other);
    return *this;
}

Spaceship::~Spaceship() {
    // entityCount scade automat prin destructorul lui Entity!
}

void Spaceship::doDraw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Spaceship::doUpdate() {
    // Sincronizăm sprite-ul cu poziția logică
    sprite.setPosition(position);
}

void Spaceship::MoveLeft() {
    position.x -= 7;
    if (position.x < 0) {
        position.x = 0;
    }
}

void Spaceship::MoveRight() {
    position.x += 7;
    float limitaDreapta = static_cast<float>(Config::SCREEN_WIDTH) - image.getSize().x;
    if (position.x >= limitaDreapta) {
        position.x = limitaDreapta;
    }
}   

void Spaceship::reactToCollision(Entity& other) {
    // Aici vei pune logica mai târziu (ex: dacă e lovită de un laser inamic)
}

std::shared_ptr<Entity> Spaceship::clone() const {
    // Cerința 2.e: Virtual Constructor pattern folosind shared_ptr
    return std::make_shared<Spaceship>(*this);
}
void Spaceship::fire() {
    // Tragem doar o dată la 0.35 secunde
    if (fireClock.getElapsedTime().asSeconds() > fireInterval) {
        // Poziționăm laserul în vârful navei
        sf::Vector2f laserPos = { position.x + image.getSize().x / 2.f - 2.f, position.y };
        lasers.push_back(std::make_shared<Laser>(laserPos, -10.f));
        // Dacă avem clonă, trage și ea!
        if (cloneActive && shipClone) {
            lasers.push_back(std::make_shared<Laser>(sf::Vector2f(shipClone->position.x + 20, shipClone->position.y), -10.f));
        }
        fireClock.restart();
    }
}
void Spaceship::activateSpeedBoost() {
    speedBoostActive = true;
    fireInterval = 0.15f; // Trage mult mai rapid
    powerUpClock.restart();
}

void Spaceship::activateClone() {
    cloneActive = true;
    // CERINȚA 2.e: Aici folosim clone() cu un scop real
    auto duplicated = this->clone();
    shipClone = std::dynamic_pointer_cast<Spaceship>(duplicated);
    powerUpClock.restart();
}

void Spaceship::updatePowerUps() {
    if ((speedBoostActive || cloneActive) && powerUpClock.getElapsedTime().asSeconds() > 5.0f) {
        speedBoostActive = false;
        cloneActive = false;
        fireInterval = 0.5f;
        shipClone = nullptr; // Ștergem clona
    }

    if (cloneActive && shipClone) {
        // Clona urmărește nava la o distanță fixă (ex: 50 pixeli la dreapta)
        shipClone->position = sf::Vector2f(position.x + 50.f, position.y);
        shipClone->doUpdate();
    }
}
void Spaceship::draw(sf::RenderWindow& window) {
    // Mai întâi apelăm metoda din Entity ca să desenăm nava de bază
    Entity::draw(window);

    // Apoi, DACĂ avem o clonă, o punem și pe ea să se deseneze
    // Presupunând că ai variabilele acestea în .h:
    if (shipClone != nullptr) {
        shipClone->draw(window);
    }
}