# Catan Game Project

## Overview
This project is an implementation of the board game Catan for three players. It includes various components of the game such as tiles, settlements, roads, cards, and gameplay mechanics. The game is written in C++ and uses a Makefile to manage the build process.
## Game Review
Catan is a popular strategy board game where players collect resources and build settlements, roads, and cities to earn victory points. The first player to reach a set number of victory points(10) wins the game. Players must strategically trade resources, build settlements, and use development cards to outmaneuver their opponents.

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

### Game Rules
#### Objective
The objective of Catan is to be the first player to reach a set number of victory points, typically 10. Players earn victory points by building settlements, cities, and roads, and by purchasing development cards.

### Setup
The game board is composed of hexagonal tiles representing different types of terrain (forest, field, hill, mountain, pasture, and desert).
Each terrain type, except the desert, produces a specific resource: wood, grain, brick, ore, and wool.
Players place their initial settlements and roads on the board.
Turn Sequence
Roll for Resources: At the beginning of each player's turn, two six-sided dice are rolled to determine which hexes produce resources.
Collect Resources: Players collect resources from hexes adjacent to their settlements and cities based on the dice roll.
Trade: Players can trade resources with each other or with the bank.
Build: Players can use their resources to build roads, settlements, cities, or buy development cards.
Building
Road: Costs 1 wood and 1 brick. Extends the player's network.
- Settlement: Costs 1 wood, 1 brick, 1 grain, and 1 wool. Placed at the intersection of three hexes.
- City: Upgrades a settlement, costs 2 grain and 3 ore. Produces more resources.
- Development Card: Costs 1 grain, 1 wool, and 1 ore. Can be a knight, a progress card, or a victory point.
- Special Rules
- Longest Road: The player with the longest continuous road of at least five segments gets 2 victory points.
- Largest Army: The player who uses the most knight cards gets 2 victory points.
- Robber: When a 7 is rolled, all players who have more than 7 resources need to return half of their resources.

#### Game Review

This C++ implementation captures the essence of the game, allowing three players to compete in a turn-based manner. It includes all the core components such as resource generation, trading, building, and using development cards. The game logic ensures a fair and competitive experience for all players.

#### Gameplay Mechanics
- Resource Generation: Resources are generated based on dice rolls and the placement of settlements.
- Trading: Players can trade resources with each other to acquire what they need to build.
- Building: Players can build roads, settlements, and cities to expand their reach and earn victory points.
- Development Cards: Players can purchase and use development cards to gain advantages.
 ##### Enjoy playing Catan and may the best strategist win!
