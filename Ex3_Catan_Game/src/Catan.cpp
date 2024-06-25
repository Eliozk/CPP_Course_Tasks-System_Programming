#include "Catan.hpp"
#include <iostream>
#include "Card.hpp"
#include <random>
#include <algorithm>
#include <stdexcept>

using namespace ariel;

//defualt constructor to initialize an object of Catan.

Catan::Catan(Player &p1, Player &p2, Player &p3, Board &board) : player1(p1), player2(p2), player3(p3), board(board)
{
    players.emplace_back(&p1);
    players.emplace_back(&p2);
    players.emplace_back(&p3);
}

void Catan::ChooseStartingPlayer() const
{
    std::cout << "Starting player: " << player1.getName() << std::endl;
}

Board &Catan::getBoard()
{
    return board;
}

void Catan::initializePlayers()
{
    std::string name;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Enter name for player " << i + 1 << ": ";
        std::cin >> name;
        players[i]->setName(name);
    }
}
// initialize and shuffle 25 development cards: 14 knigths, 5 victory points, 2 road building,2 monopoly, 2 year of plenty.
// also add to  vector of special cards Longest road and biggest army cards.
vector<Card *> Catan::createAndShuffleCards()
{
    for (int i = 0; i < 14; i++)
    {
        cards.push_back(new DevelopmentCard("Knight"));
    }
    for (int i = 0; i < 5; i++)
    {
        cards.push_back(new DevelopmentCard("Victory Point"));
    }
    for (int i = 0; i < 2; i++)
    {
        cards.push_back(new DevelopmentCard("Road Placement"));
    }
    for (int i = 0; i < 2; i++)
    {
        cards.push_back(new DevelopmentCard("Year Of Plenty"));
    }
    for (int i = 0; i < 2; i++)
    {
        cards.push_back(new DevelopmentCard("Monopoly"));
    }
    // Shuffling cards using std::shuffle and std::default_random_engine
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(cards.begin(), cards.end(), rng);

    specialCards.push_back(new LongestRoadCard());
    specialCards.push_back(new LargestArmyCard());

    // for myself
    //  Print cards for debugging
    //  std::cout << "All cards:\n ";
    //  for (int i = 0 ; i < cards.size() ; i++)
    //  {
    //      std::cout << i+1<< ". "<< cards[i]->getType() <<endl;
    //  }
    //  std::cout << std::endl;
    //  cout << "special cards:"<<endl;
    //  cout << "1. " << specialCards[0]->getType() <<endl;
    //  cout << "2. " << specialCards[1]->getType() <<endl;

    return cards;
}

void Catan::placeInitialSettlementsAndRoads(Board &catanBoard)
{
    // for (auto &player : players)
    // {
    Player &player1 = *players[0]; // Dereference the pointer to get the Player object

    cout << "Player " << player1.getName() << ", place your first settlement and road:" << std::endl;
    for (int i = 0; i < 2; ++i)
    {
        int vertexIndex1;
        int vertexIndex2;

        int num;
        std::cout << "Enter index of a vertex to place Settlement on : ";
        std::cin >> vertexIndex1;
        std::cout << "Enter index of a vertex to place road on an edge in the middle of a settlement vertex and this vertex : ";
        std::cin >> vertexIndex2;
        std::cout << "Checking initial placement..." << std::endl;
        bool toDistribute = catanBoard.checkInitialPlacement(player1, vertexIndex1, vertexIndex2);
       // cout << "boolean value toDistribute is: " << toDistribute << std::endl;

        if (toDistribute)
        {
            distributeInitialResources();//not doing nothing for now.
            
            
        }
        else
        {
            std::cout << player1.getName() << " cannot place an initial settlement on vertex " << vertexIndex1
                      << " and a road between vertices " << vertexIndex1 << " and " << vertexIndex2 << std::endl;
        }
    }
    // cout << "\tfor check (catan.cpp 105)\n";
    //         player1.displayAll();
    // player.placeSettelemnt(places, placesNum, board);
    // player.placeRoad(places, placesNum, board);
    // }
}

void Catan::distributeInitialResources()
{
    // Distribute resources based on initial settlements and tiles
    for (auto &player : players)
    {
        // Custom logic to distribute resources
    }
}
void Catan::distribution(vector<Player *> &players, int diceRoll)
{
    // Only distribute resources if the dice roll is not 7
    if(diceRoll != 7)
    {
        vector<Tile> &allTiles = board.getBoardTiles();

        for (int i = 0; i < allTiles.size(); i++)
        {
            // Check if the tile number matches the dice roll
            if (allTiles[i].getNumber() == diceRoll)
            {
                const vector<Vertex *> &vertices = allTiles[i].getVertices();
                for (Vertex *vertex : vertices)
                {
                    // Check if the vertex has a settlement
                    if (vertex->getOwner() != -1 && vertex->getSettlement() == 1)
                    {
                        // Distribute resources for a settlement
                        distributeResources(allTiles[i].getResource(), players, vertex->getOwner(), 1);
                    }
                    // Check if the vertex has a city
                    else if (vertex->getOwner() != -1 && vertex->getSettlement() == 2)
                    {
                        // Distribute resources for a city
                        distributeResources(allTiles[i].getResource(), players, vertex->getOwner(), 2);
                    }
                }
            }
        }
    }
}

void Catan::distributeResources(const string &resource, vector<Player *> &players, int playerId, int quantity)
{
    // Distribute the given resource to the player
    if (resource == "Brick")
    {
        players[playerId - 1]->addResource("Brick", quantity);
    }
    else if (resource == "Grain")
    {
        players[playerId - 1]->addResource("Grain", quantity);
    }
    else if (resource == "Lumber")
    {
        players[playerId - 1]->addResource("Lumber", quantity);
    }
    else if (resource == "Ore")
    {
        players[playerId - 1]->addResource("Ore", quantity);
    }
    else if (resource == "Wool")
    {
        players[playerId - 1]->addResource("Wool", quantity);
    }
}



void Catan::printWinner() const
{
    std::cout << "None" << std::endl; // Placeholder for determining the winner
}
