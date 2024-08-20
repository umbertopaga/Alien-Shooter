#ifndef PHYSICS_H
#define PHYSICS_H

#include <SFML/Graphics.hpp>

class Physics {
public:
    static bool checkCollision(sf::RectangleShape& shape1, sf::RectangleShape& shape2);
    static sf::Vector2f calculateMovement(float angle, float speed);
};

#endif // PHYSICS_H
