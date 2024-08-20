#include "ui.h"

UI::UI(sf::Font& font) {
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.0f, 10.0f);

    livesText.setFont(font);
    livesText.setCharacterSize(24);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(700.0f, 10.0f);
}

void UI::update(int score, int lives) {
    scoreText.setString("Score: " + std::to_string(score));
    livesText.setString("Lives: " + std::to_string(lives));
}

void UI::draw(sf::RenderWindow& window) {
    window.draw(scoreText);
    window.draw(livesText);
}
