
# Alien Shooter

Alien Shooter is a simple arcade-style game developed using SFML and C++. The player controls a spaceship and must shoot down approaching aliens. The game includes multiple levels with increasing difficulty.

## Features

- Player control via keyboard.
- Bullets that hit and destroy aliens.
- Aliens move and attack in formation.
- Multiple levels with escalating difficulty.
- Simple and clean 2D graphics.

## Requirements

To run the game, ensure you have the following installed on your system:

- [SFML 2.5.1](https://www.sfml-dev.org/download.php): A simple and fast multimedia library for C++.
- A C++ compiler that supports C++17.
- CMake for building the project.

## Setup and Installation

Follow these steps to set up and run the game:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/umbertopaga/Alien_Shooter.git
   cd alien-shooter
   ```

2. **Build the Project:**

   First, ensure that SFML is installed and properly set up on your machine. Then, configure and build the project using CMake:

   ```bash
   cd src/cpp/build
   cmake .. -DSFML_DIR="path/to/SFML"
   cmake --build .
   ```

   Replace `"path/to/SFML"` with the actual path to your SFML installation directory.

3. **Run the Game:**

   Navigate to the build directory and execute the game:

   ```bash
   .\Debug\alien_shooter.exe
   ```

## Gameplay

- **Controls:**
  - Use the **Left Arrow** and **Right Arrow** keys to move the spaceship.
  - Press **Space** to shoot bullets at the aliens.

- **Objective:**
  - Destroy all aliens in each level to progress to the next.
  - Avoid getting hit by the aliens.

- **Levels:**
  - The game features multiple levels with increasing numbers of aliens and faster movement speeds.

## Project Structure

Here's an overview of the project's structure:

```
alien-shooter/
│
├── assets/
│   ├── images/
│   │   ├── player_ship.png
│   │   └── alien.png
│   └── fonts/
│       └── game_font.ttf
│
├── src/
│   ├── cpp/
│   │   ├── CMakeLists.txt
│   │   ├── engine.cpp
│   │   ├── engine.h
│   │   ├── player.cpp
│   │   ├── player.h
│   │   ├── bullet.cpp
│   │   ├── bullet.h
│   │   ├── alien.cpp
│   │   ├── alien.h
│   │   └── main.cpp
│
└── build/
    ├── Debug/
    └── CMakeCache.txt
```

## Contributing

If you'd like to contribute to the project, feel free to fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

