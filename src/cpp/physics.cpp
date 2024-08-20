#include "physics.h"
#include <cmath>

bool Physics::checkCollision(sf::RectangleShape& shape1, sf::RectangleShape& shape2) {
    return shape1.getGlobalBounds().intersects(shape2.getGlobalBounds());
}

sf::Vector2f Physics::calculateMovement(float angle, float speed) {
    float radianAngle = angle * (3.14159265f / 180.0f);
    return sf::Vector2f(std::cos(radianAngle) * speed, std::sin(radianAngle) * speed);
}
