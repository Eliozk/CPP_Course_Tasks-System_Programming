//demoMain.cpp file
#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"

using namespace ariel;

#include "Board.hpp"

int main() {
    ariel::Board board;

    // Set a tile at row 2, column 3 with the name "Forest"
    try {
        // Set tiles with different numbers and names
    board.setTile(0, 0, "Forest");
    board.setTile(0, 1, "Hills");
    board.setTile(1, 0, "Fields");
    board.setTile(1, 1, "Pasture");
    board.setTile(2, 2, "Mountains");

    // Set settlements and cities
    vector<string> places = {"Forest", "Hills"};
    vector<int> placesNum = {0, 1};
    board.placeSettlement(places, placesNum, 'c', board); // Place city in Forest, settlement in Hills
    board.placeRoad(places, placesNum, board); // Place road in Hills

    places = {"Fields", "Pasture"};
    placesNum = {5, 6};
    board.placeSettlement(places, placesNum, 's', board); // Place settlement in Fields, city in Pasture
    board.placeRoad(places, placesNum, board); // Place road in Pasture
    } catch (const std::out_of_range &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return 1;
    }

    // Print the board to see the updated tile
    board.printBoard();

    return 0;
}










// int main() {
//     Board board;

//     // Example setup
//     board.setTile(0, 0, "Forest");
//     board.setTile(0, 1, "Hills");
//     board.setTile(1, 0, "Fields");
//     board.setTile(1, 1, "Pasture");
//     board.setTile(2, 2, "Mountains");


//     vector<string> places = {"Forest", "Hills"};
//     vector<int> placesNum = {0, 1};
//    board.placeSettlement(places, placesNum, 'c', board); // Place city in Forest, settlement in Hills
//     board.placeRoad(places, placesNum, board); // Place road in Hills

//     places = {"Fields", "Pasture"};
//     placesNum = {5, 6};
//     board.placeSettlement(places, placesNum, 's', board); // Place settlement in Fields, city in Pasture
//     board.placeRoad(places, placesNum, board); // Place road in Pasture

//     board.printBoard();

//     return 0;
// }
