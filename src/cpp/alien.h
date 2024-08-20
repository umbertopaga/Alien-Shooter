#ifndef ALIEN_H
#define ALIEN_H

#include <SFML/Graphics.hpp>

class Alien {
public:
    Alien();
    Alien(sf::Vector2f position);

    void setTexture(const sf::Texture& texture);
    void update();
    void draw(sf::RenderWindow& window);
    void takeDamage(int damage);
    bool isAlive() const;
    const sf::RectangleShape& getShape() const;
    void setSpeed(sf::Vector2f newSpeed);
    int getHealth() const;        // Esistente: Ottiene la salute corrente dell'alieno
    int getMaxHealth() const;     // Nuovo: Ottiene la salute massima dell'alieno

private:
    sf::RectangleShape shape;
    sf::Vector2f speed;
    int health;
    int maxHealth;
};

#endif // ALIEN_H
