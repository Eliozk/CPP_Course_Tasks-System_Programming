#include "GamePlay.hpp"
#include <iostream>
#include <cstdlib> // For std::rand()
#include <ctime>   // Include the header for time functions
#include <cstdlib> // Include the header for random number functions
#include "Edge.hpp"
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
    // displayGameState();

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
}

void GamePlay::rollDiceAndDistributeResources()
{
    // Generate random dice roll
    int diceRoll = rollDice();

    cout << "Rolled a " << diceRoll << "!" << std::endl;
    board.distribution(players, diceRoll);
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
                  << "7. End Turn\n"
                  << "8. Exit game\n";
        int choice;
        std::cout << "choice: ";
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
            playerBuyRoad(player);
            break;
        case 4:
            playerBuyCity(player);
            break;
        case 5:
            player.displayHand();
            std::cout << "Choose a card to play (by index): ";
            int cardIndex;
            std::cin >> cardIndex;
            if (cardIndex >= 0 && cardIndex < player.getPlayerCards().size())
            {
                const vector<Card *> specificCard = player.getPlayerCards();
                player.playCard(*specificCard[cardIndex]);
            }
            else
            {
                std::cout << "Invalid card index." << std::endl;
            }
            break;
        case 6:
            if (player.buyDevelopmentCard(cards, players))
            {
              //  cout <<"get here?"<<endl;
            //    player.playCard(*cards[0]);
            }

            break;
        case 7:
            continueTurn = false;
            break;
        case 8:
            catan.deleteMemory();
            exit(0);
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
    Edge edge = Edge(edgeIndex);
    if (!edgeIndex)
    {
        cout << "No edge between these vertices." << endl;
        return;
    }
    // Check if the road is already owned
    if (edge.getOwner() != -1)
    {
        cout << "Road is already owned by a player." << endl;
        return;
    }
    // Check if the vertices are adjacent and if the player can build a road there
    if (board.hasAdjacentSettlementOrRoad(vertex1, vertex2, player.getPlayerNumber(), player))
    {
        board.buildRoad(vertexIndex1, vertexIndex2, player);
        return;
    }
    else
    {
        cout << "Invalid placement. Please choose adjacent vertices with a settlement or road belonging to you." << endl;
        return;
    }

    cout << "Road successfully built between vertices " << vertexIndex1 << " and " << vertexIndex2 << "." << endl;
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

    cout << "Settlement upgraded to a city at vertex " << vertexIndex << "." << endl;
}

// void GamePlay::displayGameState() {
//     std::cout << "Current Game State:" << std::endl;
//     for (const auto &player : players) {
//         player.displayResources();
//     }
//     // Display board state if necessary
// }

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
