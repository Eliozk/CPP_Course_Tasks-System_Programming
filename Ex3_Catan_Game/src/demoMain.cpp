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

  vector<Player *> p;
  p.push_back(new Player(0, "Elioz"));
  p.push_back(new Player(1, "Ofek"));
  p.push_back(new Player(2, "Daniel"));

  Board board(*p[0], *p[1], *p[2]); // Use indices 0, 1, 2 for array access
  board.initializeBoard();          // Call a separate function to initialize the board
  Catan catan(*p[0], *p[1], *p[2], board);
  // catan.initializePlayers();
  // catan.createAndShuffleCards();

  GamePlay game(p, catan, board);
  game.startGame();
  // initGame.placeInitialSettlementsAndRoads(p,board); to bring back
  //i can use destructor of player.
  for (Player *player : p)
  {
    delete player;
  }
  p.clear();

  return 0;
}
/**
 *  // Clean up dynamically allocated cards
    for (ariel::Card *card : developmentCards) {
        delete card;
    }

 */