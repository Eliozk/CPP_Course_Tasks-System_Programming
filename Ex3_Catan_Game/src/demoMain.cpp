// demoMain.cpp file
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"
//#include <InitGame.hpp>
//#include <Catan.hpp>
using namespace std;
using namespace ariel;

int main()
{
   // Board board();
    //InitGame initGame;
  //  initGame.buildBoard(board);
   vector<Player> p = {Player(0,"Player1"), Player(1,"Player2"), Player(2,"Player3")};
   // vector<Player> p; // players
   // initGame.initializePlayers(p);
     Board board(p[0], p[1], p[2]); // Use indices 0, 1, 2 for array access
    board.initializeBoard(); // Call a separate function to initialize the board
    //Catan catan(p[0], p[1], p[2]);

   // initGame.placeInitialSettlementsAndRoads(p,board); to bring back

    return 0;
}


