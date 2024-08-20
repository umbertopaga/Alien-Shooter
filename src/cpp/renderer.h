#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

class Renderer {
public:
    Renderer(sf::RenderWindow& win);
    void draw(sf::Drawable& drawable);
    void display();
    void clear();

private:
    sf::RenderWindow& window;
};

#endif // RENDERER_H
