#include "GamePlay.hpp"
#include <iostream>
#include <cstdlib> // For std::rand()
#include <ctime>   // Include the header for time functions
#include <cstdlib> // Include the header for random number functions

using namespace std;
using namespace ariel;

// Constructor initializing players and a reference to Catan
GamePlay::GamePlay(vector<Player *> &players, Catan &catan, Board &board) : players(players), catan(catan), board(board), currentPlayerIndex(0) {}

void GamePlay::startGame()
{
    catan.initializePlayers();
    catan.ChooseStartingPlayer();
    catan.createAndShuffleCards();
    catan.placeInitialSettlementsAndRoads(board);
    // displayGameState();

    while (true)
    {
        nextTurn();
    }
}

void GamePlay::nextTurn()
{
    Player &currentPlayer = *players[currentPlayerIndex];
    std::cout << "It's " << currentPlayer.getName() << "'s turn." << std::endl;
    rollDiceAndDistributeResources();
    playerTurn(currentPlayer);
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

void GamePlay::rollDiceAndDistributeResources()
{

    // Seed the random number generator using the current time
    srand(static_cast<unsigned int>(std::time(nullptr)));
    // Generate random dice roll
    int diceRoll = (std::rand() % 6 + 1) + (std::rand() % 6 + 1);
    std::cout << "Rolled a " << diceRoll << "!" << std::endl;
    catan.distribution(players, diceRoll);
}

void GamePlay::playerTurn(Player &player)
{
    bool continueTurn = true;
    while (continueTurn)
    {
        cout << player.getName() << ", choose an action:\n1. Show your info? \n2. Buy Settlement\n3. Buy Road\n4. Buy City\n5. End Turn\n";
        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            player.displayAll();
            break;
        case 2:
            if (!playerBuySettlement(player))
            {
                std::cout << "Not enough resources to buy a settlement." << std::endl;
            }
            break;
        case 3:
            if (!playerBuyRoad(player)) {
                std::cout << "Not enough resources to buy a road." << std::endl;
            }
            break;
        case 4:

        case 5:
            continueTurn = false;
            break;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
}
// buy settlement
bool GamePlay::playerBuySettlement(Player &player)
{
    // Check if the player has enough resources
    if (player.canBuySettlement())
    {

        int vertexIndex;
        cout << "Enter vertex index to place the settlement: ";
        cin >> vertexIndex;
        // check if can place there there settlement
        if (board.checkSettlementPlacement(player.getPlayerNumber(), vertexIndex))
        {
            board.buildSettlement(vertexIndex, player); // no checks here except of resources and delete here and build.
            return true;
        }
        else
        {
            std::cout << "Invalid placement. Please try again." << std::endl;
        }
    }
    return false;
}

bool GamePlay::playerBuyRoad(Player &player) {
    // Check if the player has enough resources to buy a road
    if (player.canBuyRoad()) {
        int vertexIndex1, vertexIndex2;
        cout << "Enter two vertex indices to place the road between: ";
        cin >> vertexIndex1 >> vertexIndex2;
        vector<Vertex> boardVertices1 = board.getBoardVertices();

        // Check if the vertex indices are valid
        if (vertexIndex1 >= 0 && vertexIndex1 < boardVertices1.size() &&
            vertexIndex2 >= 0 && vertexIndex2 < boardVertices1.size()) {
            Vertex vertex1 = boardVertices1[vertexIndex1];
            Vertex vertex2 = boardVertices1[vertexIndex2];

            // Check if the vertices are adjacent and if the player can build a road there
            if (board.hasAdjacentSettlementOrRoad(vertex1, vertex2, player.getPlayerNumber(), player)) {
                board.buildRoad(vertexIndex1, vertexIndex2, player);
                return true;
            } else {
                cout << "Invalid placement. Please choose adjacent vertices with a settlement or road belonging to you." << endl;
                return false;
            }
        } else {
            cout << "Invalid vertex indices. Please try again." << endl;
            return false;
        }
    } 
        return false;    
}


// void GamePlay::displayGameState() {
//     std::cout << "Current Game State:" << std::endl;
//     for (const auto &player : players) {
//         player.displayResources();
//     }
//     // Display board state if necessary
// }
