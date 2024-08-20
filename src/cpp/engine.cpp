#include "engine.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

Engine::Engine()
    : player(sf::Vector2f(400.0f, 550.0f)), level(1), score(0), lives(3), isPlaying(false), bossActive(false), isPaused(false) {
    window.create(sf::VideoMode(800, 600), "Alien Shooter");
    window.setFramerateLimit(60);
    loadAssets();
    spawnAliens(level);

    startText.setFont(gameFont);
    startText.setCharacterSize(24);
    startText.setFillColor(sf::Color::White);
    startText.setString("Premi Invio per Iniziare");
    startText.setPosition(300.0f, 300.0f);

    levelText.setFont(gameFont);
    levelText.setCharacterSize(24);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(10.0f, 10.0f);
    levelText.setString("Livello: 1");

    scoreText.setFont(gameFont);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(650.0f, 10.0f);
    scoreText.setString("Punteggio: 0");

    livesText.setFont(gameFont);
    livesText.setCharacterSize(24);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(10.0f, 560.0f);
    livesText.setString("Vite: 3");

    pauseText.setFont(gameFont);
    pauseText.setCharacterSize(30);
    pauseText.setFillColor(sf::Color::Yellow);
    pauseText.setString("Gioco in Pausa\nPremi P per continuare");
    pauseText.setPosition(250.0f, 250.0f);

    gameOverText.setFont(gameFont);
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("Game Over\nPremi R per Ricominciare");
    gameOverText.setPosition(250.0f, 250.0f);

    // Barra della salute del giocatore
    playerHealthBar.setSize(sf::Vector2f(100.0f, 20.0f));
    playerHealthBar.setFillColor(sf::Color::Green);
    playerHealthBar.setPosition(650.0f, 40.0f);

    // Barra della salute del boss
    bossHealthBar.setSize(sf::Vector2f(200.0f, 20.0f));
    bossHealthBar.setFillColor(sf::Color::Red);
    bossHealthBar.setPosition(300.0f, 10.0f);

    srand(static_cast<unsigned>(time(0)));  // Inizializza il generatore di numeri casuali
}

void Engine::loadAssets() {
    if (!playerTexture.loadFromFile("C:/Users/upaganelli/Desktop/alien-shooter/assets/images/player_ship.png")) {
        throw std::runtime_error("Impossibile caricare player_ship.png");
    }
    player.setTexture(playerTexture);

    if (!alienTexture.loadFromFile("C:/Users/upaganelli/Desktop/alien-shooter/assets/images/alien.png")) {
        throw std::runtime_error("Impossibile caricare alien.png");
    }

    if (!bossTexture.loadFromFile("C:/Users/upaganelli/Desktop/alien-shooter/assets/images/boss.png")) {
        throw std::runtime_error("Impossibile caricare boss.png");
    }

    if (!gameFont.loadFromFile("C:/Users/upaganelli/Desktop/alien-shooter/assets/fonts/ARCADECLASSIC.ttf")) {
        throw std::runtime_error("Impossibile caricare il font di gioco");
    }
}

void Engine::run() {
    while (window.isOpen()) {
        processEvents();
        if (isPlaying && !isPaused) {
            update();
        }
        render();
    }
}

void Engine::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (isPlaying) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                isPaused = !isPaused;
            }
            if (!isPaused) {
                player.handleInput(event, bullets);
            }
        } else {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                startGame();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                resetGame();
            }
        }
    }
}

void Engine::update() {
    player.update(bullets);

    for (auto& bullet : bullets) {
        bullet.update();

        for (auto& alien : aliens) {
            if (alien.isAlive() && bullet.getShape().getGlobalBounds().intersects(alien.getShape().getGlobalBounds())) {
                alien.takeDamage(1);
                bullet.markForRemoval();
                score += 10;
                scoreText.setString("Punteggio: " + std::to_string(score));
                break;
            }
        }

        if (bossActive && bullet.getShape().getGlobalBounds().intersects(boss.getShape().getGlobalBounds())) {
            boss.takeDamage(1);
            bullet.markForRemoval();
            score += 50;
            scoreText.setString("Punteggio: " + std::to_string(score));
            bossHealthBar.setSize(sf::Vector2f(200.0f * (boss.getHealth() / static_cast<float>(boss.getMaxHealth())), 20.0f));
            if (!boss.isAlive()) {
                bossActive = false;
                level++;
                spawnAliens(level);
            }
        }
    }

    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
        [](const Bullet& bullet) { return bullet.shouldRemove(); }),
        bullets.end());

    for (auto& alien : aliens) {
        alien.update();

        if (alien.getShape().getPosition().y + alien.getShape().getSize().y >= 600) {
            lives--;
            livesText.setString("Vite: " + std::to_string(lives));
            alien.takeDamage(alien.getHealth());
            if (lives <= 0) {
                isPlaying = false;
            }
        }
    }

    aliens.erase(std::remove_if(aliens.begin(), aliens.end(),
        [](const Alien& alien) { return !alien.isAlive(); }),
        aliens.end());

    if (aliens.empty() && !bossActive) {
        if (level % 5 == 0) {
            boss = Alien(sf::Vector2f(300.0f, 50.0f));
            boss.setTexture(bossTexture);
            boss.setSpeed(sf::Vector2f(100.0f, 0.0f));
            bossActive = true;
            bossHealthBar.setSize(sf::Vector2f(200.0f, 20.0f));
        } else {
            level++;
            spawnAliens(level);
        }
        levelText.setString("Livello: " + std::to_string(level));
    }
}

void Engine::render() {
    window.clear();

    if (!isPlaying) {
        if (lives <= 0) {
            window.draw(gameOverText);
        } else {
            window.draw(startText);
        }
    } else {
        player.draw(window);
        for (auto& bullet : bullets) {
            bullet.draw(window);
        }
        for (auto& alien : aliens) {
            alien.draw(window);
        }
        if (bossActive) {
            boss.draw(window);
            window.draw(bossHealthBar);  // Disegna la barra della salute del boss
        }
        drawUI();  // Disegna l'interfaccia utente

        if (isPaused) {
            window.draw(pauseText);  // Disegna il testo di pausa
        }
    }

    window.display();
}

void Engine::spawnAliens(int level) {
    aliens.clear();
    int numPairs = 3 + level;
    float alienSpeed = 50.0f + (level - 1) * 20.0f;

    for (int i = 0; i < numPairs; ++i) {
        for (int j = 0; j < 2; ++j) {
            Alien alien(sf::Vector2f(100.0f + i * 100.0f, 50.0f + j * 50.0f));
            alien.setSpeed(sf::Vector2f(alienSpeed * ((rand() % 2) ? 1 : -1), 20.0f));
            alien.setTexture(alienTexture);
            aliens.push_back(alien);
        }
    }
}

void Engine::startGame() {
    resetGame();
    isPlaying = true;
}

void Engine::resetGame() {
    level = 1;
    score = 0;
    lives = 3;
    bossActive = false;
    levelText.setString("Livello: 1");
    scoreText.setString("Punteggio: 0");
    livesText.setString("Vite: 3");
    spawnAliens(level);
    bullets.clear();
}

void Engine::drawUI() {
    window.draw(scoreText);
    window.draw(livesText);
    window.draw(playerHealthBar);  // Disegna la barra della salute del giocatore
}
