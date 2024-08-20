#include "player.h"

Player::Player(sf::Vector2f position) {
    shape.setSize(sf::Vector2f(50.0f, 30.0f));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(position);
    speed = sf::Vector2f(200.0f, 0.0f);  // Inizializza la velocità come vettore
    movement = sf::Vector2f(0.f, 0.f);
}

void Player::setTexture(const sf::Texture& texture) {
    shape.setTexture(&texture);
}

void Player::handleInput(sf::Event event, std::vector<Bullet>& bullets) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            movement.x = -speed.x;
        } else if (event.key.code == sf::Keyboard::Right) {
            movement.x = speed.x;
        } else if (event.key.code == sf::Keyboard::Space) {
            shoot(bullets);  // Spara un proiettile
        }
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right) {
            movement.x = 0.0f;
        }
    }
}

void Player::update(std::vector<Bullet>& bullets) {
    shape.move(movement * 0.016f);  // Supponendo un frame time di ~60 FPS

    // Mantieni il giocatore all'interno della finestra
    if (shape.getPosition().x < 0) {
        shape.setPosition(0, shape.getPosition().y);
    }
    if (shape.getPosition().x + shape.getSize().x > 800) {
        shape.setPosition(800 - shape.getSize().x, shape.getPosition().y);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Player::shoot(std::vector<Bullet>& bullets) {
    Bullet newBullet(shape.getPosition() + sf::Vector2f(shape.getSize().x / 2 - 2.5f, 0.0f), sf::Vector2f(0.0f, -400.0f));
    bullets.push_back(newBullet);
}
