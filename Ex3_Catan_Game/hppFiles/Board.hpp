// Board.hpp

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include "Tile.hpp"
#include "Player.hpp"

namespace ariel
{

    class Player; // Forward declaration of Player class
    class Board
    {
    private:
        // Private member variables

        vector<vector<string>> settlements;
        vector<vector<string>> roads;
        vector<Player *> players;
        vector<Tile> boardTiles;
        vector<Edge> boardEdges;
        vector<Vertex> boardVertices;
        int round = 1;
    public:
        // Constructor
         Board(); // Default constructor
        Board(Player &player1, Player &player2, Player &player3);
        void initializeBoard();
        // Public member functions
        bool checkInitialPlacement(Player &player, size_t vertexIndex, size_t vertexIndex2);
        void checkRoadPlacementAndSet(int playerId, size_t vertexIndex1, size_t vertexIndex2);
        bool checkCityPlacement(int playerId, size_t vertexIndex);
        bool canPlaceRoad(Player &player, size_t vertexIndex);
        bool hasAdjacentSettlementOrRoad( Vertex &first,Vertex &second, int playerNumber,Player &player);
        // New method to check if the player has a road between two vertices
        bool hasRoad(size_t vertex1, size_t vertex2, int playerNumber,Player &player) const;
        bool checkHasAdjacentCityOrSettlement(const Vertex &vertex1, int playerNumber) const;
        void upgradeSettlementToCity(size_t vertexIndex,Player &player);

        int randomNum();
        //after init game and distribiution of 2 r and 2 s to players for the continuity of the game
        bool checkSettlementPlacement(int playerNumber, size_t vertexIndex);
        
      
        void buildSettlement(size_t vertexIndex, Player &player);
        void buildRoad(size_t vertex1, size_t vertex2, Player &player);
        void buildCity(size_t vertexIndex, Player &player);

        
        void rollDice();
        int getEdge(size_t vertexIndex1, size_t vertexIndex2) const ;
        const vector<Vertex>& getBoardVertices() const;
        bool canPlaceInitialSettlementAndRoad(Player &player, size_t vertexIndex, size_t vertexIndex2);
        //Function to get a reference to the board tiles
         vector<Tile>& getBoardTiles();
        void printBoard() const;
          void setSettlement(int row, int col, const string &player);//***************************************
        void setTile(int row, int col, const std::string &type);//***************************************
        void setRoad(int row, int col, const string &player);//***************************************
        bool isSettlementEmpty(int row, int col) const;//***************************************
        bool isRoadEmpty(int row, int col) const;//***************************************
    };
}

#endif // BOARD_HPP
