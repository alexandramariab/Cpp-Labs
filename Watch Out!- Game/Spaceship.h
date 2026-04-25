#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Laser.h"
#include <vector>
#include <memory>

// Cerința 2.a: Moștenire
class Spaceship : public Entity {
public:
    Spaceship();
    ~Spaceship() override;
    Spaceship(const Spaceship& other);
    Spaceship& operator=(Spaceship other);
    friend void swap(Spaceship& first, Spaceship& second) noexcept;
    // Funcții specifice navei (butoanele de control)
    void MoveLeft();
    void MoveRight();

    // Cerința 2.c.1: Implementarea funcțiilor virtuale pure
    void reactToCollision(Entity& other) override;
    void fire();
    std::vector<std::shared_ptr<Laser>>& getLasers() { return lasers; }

    // Cerința 2.e.4: Clone cu Smart Pointers
    std::shared_ptr<Entity> clone() const override;
    sf::FloatRect getBounds() const override { return sprite.getGlobalBounds(); }

private:
    sf::Texture image;
    sf::Sprite sprite;
    std::vector<std::shared_ptr<Laser>> lasers;
    sf::Clock fireClock; // Pentru a limita viteza de tragere
    // Cerința 2.c.2: Implementarea NVI (partea privată)
    void doUpdate() override;
    void doDraw(sf::RenderWindow& window) override;
};

#endif//SPACESHIP_H