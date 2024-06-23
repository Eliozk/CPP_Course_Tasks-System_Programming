#include "Catan.hpp"
#include <iostream>
#include "Card.hpp"
#include <random>
#include <algorithm>

using namespace ariel;

Catan::Catan(Player &p1, Player &p2, Player &p3) : player1(p1), player2(p2), player3(p3)
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
        std::cout << "Enter index of close vertex to an settlement to place road in the middle: ";
        std::cin >> vertexIndex2;
        std::cout << "Checking initial placement..." << std::endl;
        bool toDistribute = catanBoard.checkInitialPlacement(player1, vertexIndex1, vertexIndex2);
        cout << "boolean value toDistribute is: " << toDistribute << std::endl;

        if (toDistribute)
        {

            
            player1.addRoad(catanBoard.getEdge(vertexIndex1, vertexIndex2));
            std::cout << player1.getName() << " succeed place an initial settlement on vertex " << vertexIndex1
                      << " and a road between vertices " << vertexIndex1 << " and " << vertexIndex2 << std::endl;
        }
        else
        {
            std::cout << player1.getName() << " cannot place an initial settlement on vertex " << vertexIndex1
                      << " and a road between vertices " << vertexIndex1 << " and " << vertexIndex2 << std::endl;
        }
    }
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
    vector<Tile> &allTiles = board.getBoardTiles();
    for (int i = 0; i < 19; i++)
    {
        if (allTiles[i].getNumber() == diceRoll)
        {
            cout << "Plot " << i << " has number: " << allTiles[i].getNumber() << endl;
            const vector<Vertex *> &vertices = allTiles[i].getVertices();
            for (Vertex *vertex : vertices)
            {
                if (vertex->getOwner() != -1 && vertex->getSettlement() == -1)
                {
                    if (allTiles[i].getResource() == "Mountains")
                    {
                        // give the player who owns the vertex a mountain resource
                        int playerId = vertex->getOwner();
                        players[playerId - 1]->addResource("Ore", 1);
                    }
                    else if (allTiles[i].getResource() == "Pasture")
                    {
                        // give the player who owns the vertex a pasture resource
                        int playerId = vertex->getOwner();
                        players[playerId - 1]->addResource("Wool", 1);
                    }
                    else if (allTiles[i].getResource() == "Forest")
                    {
                        // give the player who owns the vertex a forest resource
                        int playerId = vertex->getOwner();
                        players[playerId - 1]->addResource("Wood", 1);
                    }
                    else if (allTiles[i].getResource() == "Agricultural")
                    {
                        // give the player who owns the vertex an agricultural resource
                        int playerId = vertex->getOwner();
                        players[playerId - 1]->addResource("Wheat", 1);
                    }
                    else if (allTiles[i].getResource() == "Hills")
                    {
                        // give the player who owns the vertex a hills resource
                        int playerId = vertex->getOwner();
                        players[playerId - 1]->addResource("Brick", 1);
                    }
                }
                else if (vertex->getOwner() != -1 && vertex->getSettlement() == 1)
                {
                    if (allTiles[i].getResource() == "Mountains")
                    {
                        // give the player who owns the vertex a mountain resource
                        int playerId = vertex->getOwner();
                        players[playerId - 1]->addResource("Ore", 2);
                    }
                    else if (allTiles[i].getResource() == "Pasture")
                    {
                        // give the player who owns the vertex a pasture resource
                        int playerId = vertex->getOwner();
                        players[playerId - 1]->addResource("Wool", 2);
                    }
                    else if (allTiles[i].getResource() == "Forest")
                    {
                        // give the player who owns the vertex a forest resource
                        int playerId = vertex->getOwner();
                        players[playerId - 1]->addResource("Wood", 2);
                    }
                    else if (allTiles[i].getResource() == "Agricultural")
                    {
                        // give the player who owns the vertex an agricultural resource
                        int playerId = vertex->getOwner();
                        players[playerId - 1]->addResource("Wheat", 2);
                    }
                    else if (allTiles[i].getResource() == "Hills")
                    {
                        // give the player who owns the vertex a hills resource
                        int playerId = vertex->getOwner();
                        players[playerId - 1]->addResource("Brick", 2);
                    }
                }
            }
        }
    }
    cout << "\n"
         << endl;
}

void Catan::printWinner() const
{
    std::cout << "None" << std::endl; // Placeholder for determining the winner
}
