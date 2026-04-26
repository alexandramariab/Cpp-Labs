#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <memory>

class Entity {
protected:
    sf::Vector2f position; //vector de pozitie pt toate entitatile (are aza Ox si Oy)
    static int entityCount;
    virtual void print(std::ostream& os) const {
        os << "Entitate la pozitia [" << position.x << ", " << position.y << "]";
    }

public:
    Entity(float x, float y);
    virtual ~Entity(); 

    //interfata non-virtuala. Entity controleaza tot procesul
    void update();
    void draw(sf::RenderWindow& window);

    virtual void reactToCollision(Entity& other) = 0; //virtual pura, obliga fiecare derivata sa specifice cum
    //reactioneaza la collision
    virtual std::shared_ptr<Entity> clone() const = 0;
    virtual sf::FloatRect getBounds() const = 0; //returneaza dreptunghiul care inconjoara obiectul
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