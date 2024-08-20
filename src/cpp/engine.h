#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "player.h"
#include "bullet.h"
#include "alien.h"

class Engine {
public:
    Engine();
    void run();

private:
    void loadAssets();
    void processEvents();
    void update();
    void render();
    void spawnAliens(int level);
    void startGame();
    void resetGame();
    void drawUI();  // Nuovo: Disegna l'interfaccia utente

    sf::RenderWindow window;
    Player player;
    sf::Texture playerTexture;
    sf::Texture alienTexture;
    sf::Texture bossTexture;  // Nuovo: Texture per il boss
    sf::Font gameFont;
    sf::Text startText;
    sf::Text levelText;
    sf::Text scoreText;  // Testo per il punteggio
    sf::Text livesText;  // Testo per le vite
    sf::Text pauseText;  // Nuovo: Testo per la pausa
    sf::Text gameOverText;  // Nuovo: Testo per il game over

    sf::RectangleShape playerHealthBar;  // Nuovo: Barra della salute del giocatore
    sf::RectangleShape bossHealthBar;  // Nuovo: Barra della salute del boss

    std::vector<Bullet> bullets;
    std::vector<Alien> aliens;
    Alien boss;  // Boss alieno
    bool bossActive;  // Stato del boss

    int level;
    int score;  // Punteggio
    int lives;  // Vite
    bool isPlaying;
    bool isPaused;  // Nuovo: Stato di pausa
};

#endif // ENGINE_H
