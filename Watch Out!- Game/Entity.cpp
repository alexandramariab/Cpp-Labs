//
// Created by Alexandra on 4/14/2026.
//
#include "Entity.h"

// 1. Inițializarea variabilei statice (Cerința 4)
// ATENȚIE: Aceasta se face O SINGURĂ DATĂ, în afara oricărei funcții.
int Entity::entityCount = 0;

// 2. Constructorul
Entity::Entity(float x, float y) : position(x, y) {
    // De fiecare dată când se creează o entitate (navă, inamic), creștem contorul
    entityCount++;
}

// 3. Destructorul
Entity::~Entity() {
    // Când un obiect este distrus (ex: un inamic moare), scădem contorul
    entityCount--;
}

// 4. Implementarea metodelor statice
int Entity::getEntityCount() {
    return entityCount;
}

// 5. NVI (Non-Virtual Interface)
// Aceste funcții sunt publice și apelează implementările private ale derivatelor
void Entity::update() {
    doUpdate(); // Aceasta va fi implementată în Spaceship, Alien etc.
}

void Entity::draw(sf::RenderWindow& window) {
    doDraw(window); // La fel și aici
} 