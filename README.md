# Snake Game

A minimalist implementation of the classic Snake game in C++, using **SFML**.

[![snake-game.png](https://i.postimg.cc/zB4P9hMM/snake-game.png)](https://postimg.cc/gXqDhxGq)

## Features

- Classic snake gameplay
- 
- Keyboard controls (ZQSD or Arrow keys)
- Growing snake and food spawning
- Game over on collision with walls or self
- Customizable settings (screen size, pixel unit size, game speed)

## Execution

To compile and run the game:

```bash
make
./snake-game
```

## Controls

- **Arrow Keys/ZQSD**: Move the snake

## Dependencies

- `gcc` (C++ compiler)
- `make`
- `SFML` (Simple and Fast Multimedia Library)

### Installing SFML on Linux (Debian/Ubuntu)

```bash
sudo apt-get install libsfml-dev
```

### Installing SFML on Arch Linux

```bash
sudo pacman -S sfml
```

## Project Structure

- `main.cpp` — entry point with game loop & rendering
- `Snake.hpp/cpp` — snake logic
- `Food.hpp/cpp` - food spawning logic
- `Makefile` — build instructions


