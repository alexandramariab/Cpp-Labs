#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <memory>

class Entity {
protected:
    sf::Vector2f position;
    static int entityCount;
    virtual void print(std::ostream& os) const {
        os << "Entitate la pozitia [" << position.x << ", " << position.y << "]";
    }

public:
    Entity(float x, float y);
    virtual ~Entity(); 

    // DOAR DECLARAȚIILE (Respectăm cerința 1.a)
    void update();
    void draw(sf::RenderWindow& window);

    virtual void reactToCollision(Entity& other) = 0;
    virtual std::shared_ptr<Entity> clone() const = 0;
    virtual sf::FloatRect getBounds() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Entity& e) {
        e.print(os);
        return os;
    }
    static int getEntityCount();

private:
    virtual void doUpdate() = 0;
    virtual void doDraw(sf::RenderWindow& window) = 0;
};

#endif //ENTITY_H