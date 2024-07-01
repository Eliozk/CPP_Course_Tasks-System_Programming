# Catan Game Project

## Overview
This project is an implementation of the board game Catan for three players. It includes various components of the game such as tiles, settlements, roads, cards, and gameplay mechanics. The game is written in C++ and uses a Makefile to manage the build process.

## Files

### Source Files
- **src/demoMain.cpp**: The main file that runs the game.
- **src/Tile.cpp**: Contains the implementation of the Tile class.
- **src/Settlement.cpp**: Contains the implementation of the Settlement class.
- **src/Player.cpp**: Contains the implementation of the Player class.
- **src/Board.cpp**: Contains the implementation of the Board class.
- **src/Card.cpp**: Contains the implementation of the Card class.
- **src/Vertex.cpp**: Contains the implementation of the Vertex class.
- **src/Edge.cpp**: Contains the implementation of the Edge class.
- **src/Catan.cpp**: Contains the implementation of the Catan class.
- **src/GamePlay.cpp**: Contains the implementation of the GamePlay class.

### Makefile
The Makefile contains the rules to compile the project and manage the build process.

## How to Compile and Run the Game

### Compiling the Project
To compile the project, open a terminal in the project directory and run:
```sh
make all

#### Targets
- `all`: Compiles the entire project.
- `run`: Runs the executable.
- `catan`: Runs the executable without recompiling.
- `debug`: Runs the executable in gdb.
- `clean`: Removes the executable and object files.


