#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Tile.hpp"

namespace ariel
{
    class Player;     // Forward declaration if used in Board
    class Settlement; // Forward declaration if used in Board

    class Board
    {
    public:
        static const int ROWS = 5;
        static const int COLS = 5;
        vector<vector<Tile>> tiles;
        vector<vector<char>> settlements;
        vector<vector<char>> roads;

        Board();

        void setTile(int row, int col, const string &type);
        void placeSettlement(const vector<string> &places, const vector<int> &placesNum, char structureType, Board &board);
        void placeRoad(const vector<string> &places, const vector<int> &placesNum, Board &board);
        void rollDice();
        int randomNum();
        void printBoard() const;
    };

} // namespace ariel

#endif // BOARD_HPP
