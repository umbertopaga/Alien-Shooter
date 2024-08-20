#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

class UI {
public:
    UI(sf::Font& font);

    void update(int score, int lives);
    void draw(sf::RenderWindow& window);

private:
    sf::Text scoreText;
    sf::Text livesText;
};

#endif // UI_H
