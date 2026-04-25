//
// Created by Alexandra on 4/15/2026.
//
#include "Laser.h"
#include "Constants.h"

Laser::Laser(sf::Vector2f pos, float speed)
    : Entity(pos.x, pos.y), speed(speed), active(true) {

    shape.setSize({4.f, 15.f}); // Dimensiunea laserului
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(position);
}

void Laser::doUpdate() {
    position.y += speed; // Se mișcă pe verticală
    shape.setPosition(position);

    // Verificăm dacă a ieșit din ecran (ca în codul tău de referință)
    if (position.y < 0 || position.y > Config::SCREEN_HEIGHT) {
        active = false;
    }
}

void Laser::doDraw(sf::RenderWindow& window) {
    if (active) {
        window.draw(shape);
    }
}

void Laser::reactToCollision(Entity& other) {
    active = false; // Laserul dispare când lovește ceva
}

std::shared_ptr<Entity> Laser::clone() const {
    return std::make_shared<Laser>(*this);
}