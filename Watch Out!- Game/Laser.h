#ifndef LASER_H
#define LASER_H

#include "Entity.h"

class Laser : public Entity {
public:
    Laser(sf::Vector2f pos, float speed);
    ~Laser() override = default;

    bool isActive() const { return active; }
    void reactToCollision(Entity& other) override;
    std::shared_ptr<Entity> clone() const override;
    sf::FloatRect getBounds() const override { return shape.getGlobalBounds(); }

private:
    float speed;
    bool active;
    sf::RectangleShape shape;

    void doUpdate() override;
    void doDraw(sf::RenderWindow& window) override;
};

#endif//LASER_H