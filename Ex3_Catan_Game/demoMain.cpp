#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"

using namespace ariel;

int main() {
    Board board;

    // Example setup
    board.setTile(0, 0, "Forest", 5);
    board.setTile(0, 1, "Hills", 6);
    board.setTile(1, 0, "Fields", 8);
    board.setTile(1, 1, "Pasture", 9);
    board.setTile(2, 2, "Mountains", 3);


    vector<string> places = {"Forest", "Hills"};
    vector<int> placesNum = {0, 1};
   board.placeSettlement(places, placesNum, 'c', board); // Place city in Forest, settlement in Hills
    board.placeRoad(places, placesNum, board); // Place road in Hills

    places = {"Fields", "Pasture"};
   placesNum = {5, 6};
    board.placeSettlement(places, placesNum, 's', board); // Place settlement in Fields, city in Pasture
    board.placeRoad(places, placesNum, board); // Place road in Pasture

    board.printBoard();

    return 0;
}
