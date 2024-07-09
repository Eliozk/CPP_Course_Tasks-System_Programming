#include "GamePlay.hpp"
#include <iostream>
#include <cstdlib> // For std::rand()
#include <ctime>   // Include the header for time functions
#include <cstdlib> // Include the header for random number functions
#include "Edge.hpp"
#include <limits>
using namespace std;
using namespace ariel;

// Constructor initializing players and a reference to Catan
GamePlay::GamePlay(vector<Player *> &players, Catan &catan, Board &board) : players(players), catan(catan), board(board), currentPlayerIndex(0) {}

void GamePlay::startGame()
{
    catan.initializePlayers();
    catan.ChooseStartingPlayer();
    cards = catan.createAndShuffleCards();
    catan.placeInitialSettlementsAndRoads(board);

    while (true)
    {
        nextTurn();
    }
}

void GamePlay::nextTurn()
{
    Player &currentPlayer = *players[currentPlayerIndex];
    std::cout << "\nIt's " << currentPlayer.getName() << "'s turn." << std::endl;
    rollDiceAndDistributeResources();
    playerTurn(currentPlayer);
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    // After player's action, check if they've won
    checkWinnerAndEndGame();
}

void GamePlay::rollDiceAndDistributeResources()
{
    // Generate random dice roll
    int diceRoll = rollDice();

    cout << "Rolled a " << diceRoll << "! here need to change back resoursces and dice roll in game play 43 and Player" << std::endl;
    if (diceRoll == 7)
    {
        handleDiceRollEquals7();
    }
    else
    {
    // Normal resource distribution based on dice roll
    board.distribution(players, diceRoll);
    }
    // After player's action, check if they've won
    checkWinnerAndEndGame();
}

void GamePlay::playerTurn(Player &player)
{
    bool continueTurn = true;
    while (continueTurn)
    {
        std::cout << "\n"
                  << player.getName() << ", choose an action:\n"
                  << "1. Show your info\n"
                  << "2. Buy Settlement\n"
                  << "3. Buy Road\n"
                  << "4. Buy City\n"
                  << "5. Play Card\n"
                  << "6. Buy Development Card\n"
                  << "7. Trade with Player\n"
                  << "8. End Turn\n"
                  << "9. Exit game\n";
        int choice;
        std::cout << "choice: ";
        
        // Input validation loop
        while (!(std::cin >> choice)) {
            std::cin.clear();  // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard incorrect input
            std::cout << "Invalid input. Please enter a number from the list: ";
        }

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
            playerBuyRoad(player);
            // player.checkLargestRoad(players, board);
            break;
        case 4:
            playerBuyCity(player);
            break;
        case 5:
            player.displayHand();
            if (player.getPlayerCards().size() != 0)
            {
                std::cout << "Choose a card to play (by index): ";
                int cardIndex;
                if (std::cin >> cardIndex)
                {
                    cardIndex -= 1;
                    if (cardIndex >= 0 && cardIndex < player.getPlayerCards().size())
                    {
                        const vector<Card *> specificCard = player.getPlayerCards();
                        player.playCard(board, *specificCard[cardIndex], players);
                    }
                    else
                    {
                        std::cout << "Invalid card index." << std::endl;
                    }
                }
                else
                {
                    std::cout << "Invalid input. Please enter a valid card index." << std::endl;
                    std::cin.clear();  // Clear error state
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard incorrect input
                }
                // After playing a card, continue to the next turn
                continueTurn = false;
            }
            break;
        case 6:
            player.buyDevelopmentCard(cards, players);
            break;
        case 7:
            tradeResources(player);
            break;
        case 8:
            continueTurn = false;
            break;
        case 9:
            catan.cleanup();
            exit(0);
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
}


void GamePlay::tradeResources(Player &currentPlayer)
{
    std::cout << "\nTrading resources with another player." << std::endl;
    int otherPlayerIndex;
    std::string resource1, resource2;
    int amount1, amount2;

    for (int i = 0; i < players.size(); i++)
    {
        std::cout << i + 1 << "." << players[i]->getName() << " ";
    }
    std::cout << "\nEnter player index to trade with (1-" << players.size() << "): ";

    std::cin >> otherPlayerIndex;

    if (otherPlayerIndex < 1 || otherPlayerIndex > players.size() || currentPlayer.getPlayerNumber() == otherPlayerIndex - 1)
    {
        if (currentPlayer.getPlayerNumber() == otherPlayerIndex - 1)
        {
            std::cout << "Choose another player to trade with and stop play with yourself!" << std::endl;
        }
        else
        {
            std::cout << "Invalid player index." << std::endl;
        }
        return;
    }

    std::string otherPlayerName = players[otherPlayerIndex - 1]->getName();
    std::string currentPlayerName = currentPlayer.getName();
    std::cout << currentPlayerName << ":\n";

    // Prompt for resources to trade
    std::cout << "Enter resource and amount you want to give to " << otherPlayerName << " (e.g., 'Wood 2'): ";
    std::cin >> resource1 >> amount1;

    std::cout << "Enter resource and amount you want to get from " << otherPlayerName << " in return (e.g., 'Brick 1'): ";
    std::cin >> resource2 >> amount2;

    currentPlayer.tradeResources(*players[otherPlayerIndex - 1], resource1, amount1, resource2, amount2);
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

void GamePlay::playerBuyRoad(Player &player)
{
    // Check if the player has enough resources to buy a road
    if (!player.canBuyRoad())
    {
        cout << "Not enough resources to buy a Road." << endl;
        return;
    }
    int vertexIndex1, vertexIndex2;
    cout << "Enter two vertex indices to place the road between: ";
    cin >> vertexIndex1 >> vertexIndex2;

    vector<Vertex> boardVertices1 = board.getBoardVertices();

    // Check if the vertex indices are valid
    if (!(vertexIndex1 >= 0 && vertexIndex1 < boardVertices1.size() &&
          vertexIndex2 >= 0 && vertexIndex2 < boardVertices1.size()))
    {
        cout << "Invalid vertex indices." << endl;
    }
    Vertex &vertex1 = boardVertices1[vertexIndex1];
    Vertex &vertex2 = boardVertices1[vertexIndex2];

    // Ensure vertices are neighbors
    if (!vertex1.isNeighbor(vertex2))
    {
        cout << "Vertices are not neighbors." << endl;
        return;
    }

    // Ensure there is an edge between these vertices
    int edgeIndex = board.getEdge(vertexIndex1, vertexIndex2);
    if (edgeIndex == -1)
    {
        cout << "No edge between these vertices." << endl;
        return;
    }

    // Check if the road is already owned
    if (board.isEdgeOwned(edgeIndex))
    {
        cout << "Road is already owned by a player." << endl;
        return;
    }
    // Check if the vertices are adjacent and if the player can build a road there
    if (board.hasAdjacentSettlementOrRoad(vertex1, vertex2, player.getPlayerNumber(), player))
    {
        board.buildRoad(vertexIndex1, vertexIndex2, player);
        player.checkLargestRoad(players, board);

        return;
    }
    else
    {
        cout << "Invalid placement. Please choose adjacent vertices with a settlement or road belonging to you." << endl;
        return;
    }
}

void GamePlay::playerBuyCity(Player &player)
{
    // Check if the player has enough resources to buy a city
    if (!player.canBuyCity())
    {
        cout << "Not enough resources to buy a city." << endl;
        return;
    }

    int vertexIndex;
    cout << "Enter vertex index to upgrade the settlement to a city: ";
    cin >> vertexIndex;

    // Get the vertex at the specified index
    vector<Vertex> boardVertices = board.getBoardVertices();

    // Check if the vertex index is valid
    if (!(vertexIndex >= 0 && vertexIndex < boardVertices.size()))
    {
        cout << "Invalid vertex index." << endl;
        return;
    }

    Vertex &vertex = boardVertices[vertexIndex];

    // Check if the player owns a settlement at the specified vertex
    if (!(vertex.getSettlement() == 1) || vertex.getOwner() != player.getPlayerNumber())
    {
        cout << "You do not own a settlement at this vertex." << endl;
        return;
    }

    // Upgrade the settlement to a city
    board.upgradeSettlementToCity(vertexIndex, player);
    player.removeSettlement(vertexIndex);
    cout << "Settlement upgraded to a city at vertex " << vertexIndex << "." << endl;
}

// This function return number of rolled 2 dices.
int GamePlay::rollDice() const
{

    // Generate a random number between 1 and 6 for the first die
    int die1 = rand() % 6 + 1;

    // Generate a random number between 1 and 6 for the second die
    int die2 = rand() % 6 + 1;

    int rollResult = die1 + die2;

    return rollResult;
}

void GamePlay::handleDiceRollEquals7()
{
    for (auto &player : players)
    {
        if (player->totalResourceCards() > 7)
        {
            player->discardHalfCards();
        }
    }
}

void GamePlay::checkWinnerAndEndGame()
{
    for (auto player : players)
    {
        if (player->getPoints() >= 10)
        {
            cout << "Player " << player->getName() << " has reached 10 points and he is the winner!" << endl;
            cout << "Game Over!" << std::endl;
            catan.cleanup();
            exit(0); // Exit the program
        }
    }
}