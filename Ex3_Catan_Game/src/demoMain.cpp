// demoMain.cpp file
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"
#include "GamePlay.hpp"
#include "Catan.hpp"

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
  
  GamePlay game(p, catan, board);

    //start game
      game.startGame();


  return 0;
}
