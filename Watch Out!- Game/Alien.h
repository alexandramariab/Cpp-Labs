//
// Created by Alexandra on 4/16/2026.
//

#ifndef ALIEN_H
#define ALIEN_H

#include "Entity.h"

class Alien : public Entity {
public:
    Alien(float x, float y, int type);
    ~Alien() override = default;

    void reactToCollision(Entity& other) override;
    std::shared_ptr<Entity> clone() const override;

    bool isAlive() const { return alive; }
    void moveDown(float distance);
    float getRightEdge() const; // Înlocuiește accesul direct la textură
    float getLeftEdge() const;
    sf::Vector2f getCenter() const;

    static void changeDirection();
    // Metodă de nivel înalt: Schimbă direcția pentru TOȚI alienii
    sf::FloatRect getBounds() const override { return sprite.getGlobalBounds(); }

private:
    int type;
    bool alive;
    sf::Texture texture;
    sf::Sprite sprite;

    static float speed; // Viteza comună
    static int direction; // 1 pentru dreapta, -1 pentru stânga

    void doUpdate() override;
    void doDraw(sf::RenderWindow& window) override;
};

#endif//ALIEN_H
