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

    public:
        // Constructor
        Board(Player &player1, Player &player2, Player &player3);
        void initializeBoard();
        // Public member functions
        bool checkInitialPlacement(Player &player, size_t vertexIndex, size_t vertexIndex2);
        bool checkRoadPlacement(int playerId, size_t vertexIndex1, size_t vertexIndex2);
        bool checkSettlementPlacement(int playerId, size_t vertexIndex);
        bool checkCityPlacement(int playerId, size_t vertexIndex);
        int randomNum();
        void setSettlement(int row, int col, const string &player);
        void setTile(int row, int col, const std::string &type);
        void setRoad(int row, int col, const string &player);
        void placeRoad(const vector<string> &places, const vector<int> &placesNum, char playerID);
        void rollDice();
        int getEdge(size_t vertexIndex1, size_t vertexIndex2);
        void printBoard() const;
        bool isSettlementEmpty(int row, int col) const;
        bool isRoadEmpty(int row, int col) const;
    };
}

#endif // BOARD_HPP
