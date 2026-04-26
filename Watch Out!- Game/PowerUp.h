#ifndef POWERUP_H
#define POWERUP_H

#include "Entity.h"
#include "Spaceship.h"

class PowerUp : public Entity {
public:
    // Constructorul primește culoarea pentru a configura atributul privat shape
    PowerUp(float x, float y, sf::Color color);
    virtual ~PowerUp() override = default;
    
    // Funcția virtuală specifică (Cerința 2.c.1)
    virtual void applyEffect(Spaceship& ship) = 0;
    
    // Suprascrieri obligatorii din Entity
    void reactToCollision(Entity& other) override;
    sf::FloatRect getBounds() const override;
    bool isExpired() const;

private:
    sf::RectangleShape shape; // PRIVAT - derivatele nu au acces la el
    bool active;              // PRIVAT
    
    void doUpdate() override;
    void doDraw(sf::RenderWindow& window) override;
};

// --- SpeedPowerUp ---
class SpeedPowerUp : public PowerUp {
public:
    // Pasăm culoarea către baza prin lista de inițializare a constructorului
    SpeedPowerUp(float x, float y) : PowerUp(x, y, sf::Color::Cyan) {}
    
    void applyEffect(Spaceship& ship) override;
    std::shared_ptr<Entity> clone() const override;
};

// --- ClonePowerUp ---
class ClonePowerUp : public PowerUp {
public:
    ClonePowerUp(float x, float y) : PowerUp(x, y, sf::Color::Magenta) {}
    
    void applyEffect(Spaceship& ship) override;
    std::shared_ptr<Entity> clone() const override;
};

#endif//POWERUP_H