#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(sf::Vector2f position, sf::Vector2f velocity);

    void update();
    void draw(sf::RenderWindow& window);
    
    bool isOffScreen() const;
    bool shouldRemove() const;
    void markForRemoval();
    const sf::RectangleShape& getShape() const;

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    bool toBeRemoved;
};

#endif // BULLET_H
