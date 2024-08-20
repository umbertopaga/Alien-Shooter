#include <iostream> // Aggiungi questa linea per includere iostream
#include "engine.h"

int main() {
    try {
        Engine game;  // Inizializza il motore di gioco
        game.run();   // Esegui il gioco
    } catch (const std::exception& e) {
        std::cerr << "Errore durante l'esecuzione del gioco: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
