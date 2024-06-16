#include "InitGame.hpp"
#include "Card.hpp"   // Include the necessary card classes header file
#include "Player.hpp" // Include Player class
#include "Tile.hpp"   // Include Tile class
#include "Board.hpp"  // Include Board class
#include <vector>     // Include vector for managing cards
#include <string>
#include <algorithm> // For shuffle
#include <random>    // For default_random_engine
#include <iostream>  // For cin and cout
#include <Hexagon.hpp>

using namespace std;
using namespace ariel;

// Function to create and shuffle development cards
// Function to create and shuffle development cards
vector<ariel::Tile> InitGame::createAndShuffleTiles()
{
    std::vector<std::string> tileTypes = {
        "Field", "Field", "Field", "Field",
        "Forest", "Forest", "Forest", "Forest",
        "Pasture", "Pasture", "Pasture", "Pasture",
        "Hill", "Hill", "Hill",
        "Mountain", "Mountain", "Mountain",
        "Desert"};

    std::vector<int> tileNumbers = {
        2, 3, 3, 4, 4, 5, 5, 6, 6,
        8, 8, 9, 9, 10, 10, 11, 11, 12, -1 // -1 for Desert
    };
    std::vector<ariel::Tile> tiles;

    // Create tiles with types and numbers
    for (size_t i = 0; i < tileTypes.size(); ++i)
    {
        tiles.emplace_back(tileTypes[i], tileNumbers[i]);
    }

    // Shuffle the tiles
   random_device rd;
    mt19937 g(rd());
    shuffle(tiles.begin(), tiles.end(), g);

    // Return the shuffled tiles
    return tiles;
}

    void InitGame::buildBoard()
    {
    }
    // Function to initialize players
    void InitGame::initializePlayers(vector<Player> &players) {}

    // Function to place initial settlements and roads
    void InitGame::placeInitialSettlementsAndRoads(vector<Player> &players, Board &board) {}

    
   

    // Function to distribute initial resources to players
    void InitGame::distributeInitialResources(vector<Player> &players, const Board &board) {}


    void InitGame::initializePlayers(vector<Player> &players)
    {
        string playerName;
        for (int i = 0; i < 3; ++i)
        {
            cout << "Enter name for player " << i + 1 << ": ";
            cin >> playerName;
            players.push_back(Player(playerName));
        }
    }

    void InitGame::placeInitialSettlementsAndRoads(vector<Player> &players, Board &board)
    {
        // Implement the logic to place initial settlements and roads
        // You may need to interact with the Board class to place settlements and roads
    }

    vector<Card *> InitGame::createAndShuffleCards()
    {
        /**
         * 14 קלפי אביר
         * 5 קלפי ניצחון
         * 2 בניית דרך
         * 2 year of plenty take 2 resources from bank
         * 2מונופול נשמר אצלינו וכשתמשתים כל השחקנים מעבירים לנו את כל המשאב שנבחר שקיים אצלם
         */
        vector<Card *> allCards;

        // Add Victory Point Cards קלפי ניצחון 5
        allCards.push_back(new VictoryPointCard("Governor's House", 1));
        allCards.push_back(new VictoryPointCard("Library", 1));
        allCards.push_back(new VictoryPointCard("Market", 1));
        allCards.push_back(new VictoryPointCard("Chapel", 1));
        allCards.push_back(new VictoryPointCard("Universuty of Catan", 1));

        // Add Development Cards 6 קלפי התפתחות
        for (int i = 0; i < 2; i++)
        {
            allCards.push_back(new ProgressCard("Road Building"));
            allCards.push_back(new ProgressCard("Year of Plenty"));
            allCards.push_back(new ProgressCard("Monopoly"));
        }
        // 2 special cards 2
        allCards.push_back(new ProgressCard("Largest Army"));
        allCards.push_back(new ProgressCard("Longest Road"));

        // Add 14 Knight Cards 14 קלפי אביר
        for (int i = 0; i < 14; i++)
        {
            allCards.push_back(new KnightCard());
        }

        // Shuffle the vector
        random_device random;
        mt19937 g(random());
        shuffle(allCards.begin(), allCards.end(), g);

        return allCards;
    }

    void InitGame::setupBoard(vector<Hexagon> &board)
    {
        // Create 19 hexagons with specific tiles and numbers as in game
        vector<string> tileTypes = {
            "Field", "Field", "Field", "Field",
            "Forest", "Forest", "Forest", "Forest",
            "Pasture", "Pasture", "Pasture", "Pasture",
            "Hill", "Hill", "Hill",
            "Mountain", "Mountain", "Mountain",
            "Desert"};

        vector<int> numberTiles = {
            2, 3, 3, 4, 4, 5, 5, 6, 6,
            8, 8, 9, 9, 10, 10, 11, 11, 12, -1 // -1 for Desert
        };

        // Shuffle the resources and numbers, except the Desert
        random_device rd;
        mt19937 g(rd());
        shuffle(tileTypes.begin(), tileTypes.end() - 1, g);     // Exclude last element (Desert)
        shuffle(numberTiles.begin(), numberTiles.end() - 1, g); // Exclude last element (Desert number)

        // Insert Desert at the center position (index 9)
        tileTypes.insert(tileTypes.begin() + 9, "Desert");
        numberTiles.insert(numberTiles.begin() + 9, -1);

        // Initialize board with hexagons
        for (int i = 0; i < 19; ++i)
        {
            board.emplace_back(numberTiles[i], tileTypes[i]);
        }
    }

