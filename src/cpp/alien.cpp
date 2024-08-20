#include "alien.h"

Alien::Alien() : speed(50.0f, 20.0f), health(3), maxHealth(3) {
    shape.setSize(sf::Vector2f(40.0f, 30.0f));
    shape.setFillColor(sf::Color::Red);
}

Alien::Alien(sf::Vector2f position) : speed(50.0f, 20.0f), health(3), maxHealth(3) {
    shape.setSize(sf::Vector2f(40.0f, 30.0f));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
}

void Alien::setTexture(const sf::Texture& texture) {
    shape.setTexture(&texture);
}

void Alien::update() {
    shape.move(speed * 0.016f);

    if (shape.getPosition().x <= 0 || shape.getPosition().x + shape.getSize().x >= 800) {
        speed.x = -speed.x;
        shape.move(speed.x * 0.016f, speed.y * 0.016f);
    }
}

void Alien::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Alien::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        shape.setFillColor(sf::Color(0, 0, 0, 0));
    }
}

bool Alien::isAlive() const {
    return health > 0;
}

const sf::RectangleShape& Alien::getShape() const {
    return shape;
}

void Alien::setSpeed(sf::Vector2f newSpeed) {
    speed = newSpeed;
}

int Alien::getHealth() const {
    return health;
}

int Alien::getMaxHealth() const {  // Nuovo: restituisce la salute massima dell'alieno
    return maxHealth;
}
