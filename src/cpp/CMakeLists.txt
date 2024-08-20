cmake_minimum_required(VERSION 3.10)
project(AlienShooter)

set(CMAKE_CXX_STANDARD 17)

# Imposta la directory di SFML
set(SFML_DIR "C:/Users/upaganelli/SFML-2.5.1-windows-vc15-64-bit/SFML-2.5.1/lib/cmake/SFML")

# Trova i pacchetti SFML richiesti
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# File sorgenti del progetto
set(SOURCES
    main.cpp
    engine.cpp
    player.cpp
    bullet.cpp
    alien.cpp
    physics.cpp
    renderer.cpp
    ui.cpp
)

# Creazione dell'eseguibile
add_executable(alien_shooter ${SOURCES})

# Collegamento delle librerie SFML
target_link_libraries(alien_shooter sfml-graphics sfml-window sfml-system)

# Aggiungi la directory include di SFML al percorso di inclusione
target_include_directories(alien_shooter PRIVATE ${SFML_INCLUDE_DIR})
