#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include <vector>
#include <memory>
#include "Alien.h"
#include "Laser.h"

class Game {
public:
    Game();
    ~Game();
    void Draw(sf::RenderWindow& window); // Primește fereastra din main
    void Update();
    void HandleInput();

private:
    Spaceship spaceship;
    std::vector<std::shared_ptr<Entity>> allEntities;
    std::vector<std::shared_ptr<Laser>> alienLasers;  // Laserele trase de inamici
    sf::Clock alienFireClock;
    float fireInterval = 1.2f;
    void initAliens(); // Funcție internă de populare a nivelului
    void CheckForCollisions();
    bool run;
};
#endif//GAME_H