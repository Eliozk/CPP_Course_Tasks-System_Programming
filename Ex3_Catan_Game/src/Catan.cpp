#include "Catan.hpp"
#include <iostream>
#include "Card.hpp"
#include <random>
#include <algorithm>
#include <stdexcept>
#include <limits> // for std::numeric_limits

using namespace ariel;
using namespace std;

// static member
std::vector<Card *> Catan::specialCards;
// defualt constructor to initialize an object of Catan.
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

std::vector<Card *> Catan::createAndShuffleCards()
{
    // Clear any existing cards in the vector before populating
    cards.clear();
    specialCards.clear();

    // Create and add development cards
    // knights 3,Victory pt 4 - as requested in Git of Benjamin.
    for (int i = 0; i < 3; ++i)
    {
        cards.push_back(new DevelopmentCard("Knight"));
    }
    for (int i = 0; i < 4; ++i)
    {
        cards.push_back(new DevelopmentCard("Victory Point"));
    }
    for (int i = 0; i < 2; ++i)
    {
        cards.push_back(new DevelopmentCard("Road Building"));
    }
    for (int i = 0; i < 2; ++i)
    {
        cards.push_back(new DevelopmentCard("Year Of Plenty"));
    }
    for (int i = 0; i < 2; ++i)
    {
        cards.push_back(new DevelopmentCard("Monopoly"));
    }

    // Shuffle cards using std::shuffle and std::default_random_engine
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(cards.begin(), cards.end(), rng);

    // Add special cards
    specialCards.push_back(new LongestRoadCard());
    specialCards.push_back(new LargestArmyCard());

    return cards;
}
vector<Card *> Catan::getMainSpecialCards()
{
    return specialCards;
}

void Catan::placeInitialSettlementsAndRoads(Board &catanBoard)
{
    for (auto &player : players)
    {
        int round = 0;
        std::cout << "\n" << player->getName() << ", place your first settlement and road:" << std::endl;

        while (round < 2)
        {
            int vertexIndex1;
            int vertexIndex2;

            // Input validation loop for vertexIndex1
            while (true)
            {
                std::cout << "Enter index of a vertex to place Settlement on: ";
                if (std::cin >> vertexIndex1)
                {
                    // Check if the input was an integer
                    if (std::cin.peek() == '\n')
                    {
                        break; // Valid input, break out of loop
                    }
                    else
                    {
                        std::cout << "Invalid input. Please enter a valid integer.\n";
                        std::cin.clear(); // Clear error flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                    }
                }
                else
                {
                    std::cout << "Invalid input. Please enter a valid integer.\n";
                    std::cin.clear(); // Clear error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                }
            }

            // Input validation loop for vertexIndex2
            while (true)
            {
                std::cout << "Enter index of a vertex to place road on an edge in the middle of a settlement vertex and this vertex: ";
                if (std::cin >> vertexIndex2)
                {
                    // Check if the input was an integer
                    if (std::cin.peek() == '\n')
                    {
                        break; // Valid input, break out of loop
                    }
                    else
                    {
                        std::cout << "Invalid input. Please enter a valid integer.\n";
                        std::cin.clear(); // Clear error flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                    }
                }
                else
                {
                    std::cout << "Invalid input. Please enter a valid integer.\n";
                    std::cin.clear(); // Clear error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                }
            }

            std::cout << "\nChecking initial placement...\n" << std::endl;
            bool toDistribute = catanBoard.checkInitialPlacement(*player, vertexIndex1, vertexIndex2);

            if (toDistribute)
            {
                round++; // Increment round only if placement was successful
                if (round < 2)
                {
                    std::cout << "\n" << player->getName() << ", place your next settlement and road:" << std::endl;
                }
            }
            else
            {
                std::cout << player->getName() << " cannot place an initial settlement on vertex " << vertexIndex1
                          << " and a road between vertices " << vertexIndex1 << " and " << vertexIndex2 << std::endl;
            }
        }
    }
}


// Clean up dynamically allocated cards and players.
void Catan::deleteMemory()
{
    // Delete cards
    for (Card* card : cards) {
        delete card;
    }
    cards.clear();

    // Delete special cards
    for (Card* specialCard : specialCards) {
        delete specialCard;
    }
    specialCards.clear();
    
}
void Catan::cleanup()
{
    
    player1.~Player();
    player2.~Player();
    player3.~Player();
    deleteMemory();
    board.~Board();
    //players.clear();
}
