#include "renderer.h"

Renderer::Renderer(sf::RenderWindow& win) : window(win) {}

void Renderer::draw(sf::Drawable& drawable) {
    window.draw(drawable);
}

void Renderer::display() {
    window.display();
}

void Renderer::clear() {
    window.clear(sf::Color::Black);
}
