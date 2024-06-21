#ifndef INITGAME_HPP
#define INITGAME_HPP

#include "Card.hpp"   // Include the necessary card classes header file
#include "Player.hpp" // Include Player class
#include "Tile.hpp"   // Include Tile class
#include <vector>     // Include vector for managing cards
#include <string>
#include <iostream> // For std::cin and std::cout

namespace ariel
{

    class InitGame
    {
    private:
        vector<string> tileTypes;
        vector<int> tileNumbers;
        vector<Player> players;

    public:
        vector<Tile> createTiles(); // Updated function declaration
        // Function to initialize players
        void initializePlayers(vector<Player> &players);
    

        // Function to place initial settlements and roads
        void placeInitialSettlementsAndRoads(vector<Player>& players, Board& board);

        // Function to create and shuffle development cards
        vector<Card *> createAndShuffleCards();

        // Function to distribute initial resources to players
        void distributeInitialResources(vector<Player> &players, const Board &board);
        void buildBoard(Board& board);
       // void setupBoard(vector<Hexagon> &board);
    };

} // namespace ariel

#endif // INITGAME_HPP
