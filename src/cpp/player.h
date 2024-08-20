#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.h"  // Assicurati che questo sia corretto

class Player {
public:
    Player(sf::Vector2f position);

    void setTexture(const sf::Texture& texture);
    void handleInput(sf::Event event, std::vector<Bullet>& bullets);
    void update(std::vector<Bullet>& bullets);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
    sf::Vector2f speed;
    sf::Vector2f movement;

    void shoot(std::vector<Bullet>& bullets);
};

#endif // PLAYER_H
