#include "bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f velocity)
    : velocity(velocity), toBeRemoved(false) {  // Inizializza il flag a false
    shape.setSize(sf::Vector2f(5.0f, 10.0f));  // Dimensione del proiettile
    shape.setFillColor(sf::Color::Yellow);  // Colore del proiettile
    shape.setPosition(position);
}

void Bullet::update() {
    shape.move(velocity * 0.016f);  // Muove il proiettile

    // Segna il proiettile per la rimozione se è fuori dallo schermo
    if (isOffScreen()) {
        toBeRemoved = true;
    }
}

void Bullet::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Bullet::isOffScreen() const {
    // Ritorna true se il proiettile è fuori dallo schermo
    return shape.getPosition().y + shape.getSize().y < 0;
}

bool Bullet::shouldRemove() const {
    // Ritorna true se il proiettile deve essere rimosso
    return toBeRemoved;
}

void Bullet::markForRemoval() {
    toBeRemoved = true;  // Segna il proiettile per la rimozione
}

const sf::RectangleShape& Bullet::getShape() const {
    return shape;
}
