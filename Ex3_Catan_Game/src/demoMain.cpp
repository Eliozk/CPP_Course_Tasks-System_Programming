// demoMain.cpp file
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"
#include "GamePlay.hpp"
#include <Catan.hpp>
using namespace std;
using namespace ariel;

int main()
{
  // Board board();
  // InitGame initGame;
  //  initGame.buildBoard(board);
  vector<Player *> p;
  p.push_back(new Player(0, "Elioz"));
  p.push_back(new Player(1, "Ofek"));
  p.push_back(new Player(2, "Daniel"));
  // vector<Player> p; // players

  Board board(*p[0], *p[1], *p[2]); // Use indices 0, 1, 2 for array access
  board.initializeBoard();          // Call a separate function to initialize the board
  Catan catan(*p[0], *p[1], *p[2], board);
  // catan.initializePlayers();
  // catan.createAndShuffleCards();

  GamePlay game(p, catan, board);
  game.startGame();
  // initGame.placeInitialSettlementsAndRoads(p,board); to bring back

  return 0;
}
