#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <Catan.hpp>
using namespace ariel;

Game::Game(const string& playerName1, const string& playerName2, const string& playerName3) :
    p1(playerName1),
    p2(playerName2),
    p3(playerName3){}
    


void Game::start() {
    ChooseStartingPlayer();
    board = Board(); // Assuming Board has a default constructor
    // Other initialization or setup logic can go here
}

void Game::ChooseStartingPlayer() {
    std::cout << "Starting player: " << p1.getName() << std::endl;
}


    // Place settlements and roads
    // placeInitialBuildings(){

    // }

    // Simulate turns and actions
  //  simulateTurns();

//     // Print points and determine winner
//     printPoints();
//     printWinner();
// }

// void Game::placeInitialBuildings() {
//     p1.placeSettlement({"Forest", "Hills"}, {5, 6}, board);
//     p1.placeRoad({"Forest", "Hills"}, {5, 6}, board);
//     p1.placeSettlement({"Agricultural Land", "Desert"}, {3, 4}, board);
//     p1.placeRoad({"Agricultural Land", "Desert"}, {3, 4}, board);

//     p2.placeSettlement({"Mountains", "Pasture Land"}, {4, 9}, "ישוב", board);
//     p2.placeRoad({"Mountains", "Pasture Land"}, {4, 9}, board);
//     p2.placeSettlement({"Forest", "Pasture Land"}, {5, 9}, "ישוב", board);
//     p2.placeRoad({"Forest", "Pasture Land"}, {5, 9}, board);

//     p3.placeSettlement({"Mountains", "Pasture Land"}, {3, 8}, "ישוב", board);
//     p3.placeRoad({"Mountains", "Pasture Land"}, {3, 8}, board);
//     p3.placeSettlement({"Agricultural Land", "Pasture Land"}, {3, 9}, "ישוב", board);
//     p3.placeRoad({"Agricultural Land", "Pasture Land"}, {3, 9}, board);
// }

// void Game::simulateTurns() {
//     p1.rollDice();
//     p1.placeRoad({"Forest", "Hills"}, {5, 6}, board);
//     p1.endTurn();

//     p2.rollDice();
//     p2.endTurn();

//     p3.rollDice();
//     p3.endTurn();

//     // Attempt to roll dice out of turn
//     try {
//         p2.rollDice();
//     } catch (const std::exception& e) {
//         std::cout << e.what() << std::endl;
//     }

//     p1.rollDice();
//     p1.trade(p2, "wood", "brick", 1, 1);
//     p1.endTurn();

//     p2.rollDice();
//     p2.buyDevelopmentCard();
//     p2.endTurn();
// }

void Game::printPoints() const {
    p1.printPoints();
    p2.printPoints();
    p3.printPoints();
}

void Game::printWinner() const {
    std::cout << "None" << std::endl; // Placeholder for determining the winner
}
