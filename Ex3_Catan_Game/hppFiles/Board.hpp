#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Tile.hpp"

using namespace std;

namespace ariel {

    const int ROWS = 5;
    const int COLS = 5;
    /**
     * @brief Represents the game board for Catan.
     * The Board class manages the game board, including tiles, cities, settlements, and roads.
     */
    class Board {
    private:
        int hexagonsPerRow[5];
        vector<vector<Tile>> tiles; /**< 2D vector to store tiles on the board. */
        vector<vector<char>> settlements; /**< 2D vector to store settlements and cities on the board. */
        vector<vector<char>> roads; /**< 2D vector to store roads on the board. */

    public:
        /**
         * @brief Default constructor for the Board class.
         * Initializes the board with empty tiles, cities, settlements, and roads.
         */
        Board();

        /**
         * @brief Sets a tile at the specified position on the board.
         * 
         * @param row The row index of the tile.
         * @param col The column index of the tile.
         * @param type The type of the tile.
         * @param number The number associated with the tile.
         */
        void setTile(int row, int col, const string& type);

        /**
         * @brief Places settlements or cities at specified positions on the board.
         * 
         * @param places A vector of strings representing the names of locations where structures are to be placed.
         * @param placesNum A vector of integers representing the numbers of locations where structures are to be placed.
         * @param structureType A character representing the type of structure to place ('c' for city, 's' for settlement).
         * @param board The Board object on which structures are to be placed.
         */
        void placeSettlement(const vector<string>& places, const vector<int>& placesNum, char structureType, Board& board);

        /**
         * @brief Places roads at specified positions on the board.
         * 
         * @param places A vector of strings representing the names of locations where roads are to be placed.
         * @param placesNum A vector of integers representing the numbers of locations where roads are to be placed.
         * @param board The Board object on which roads are to be placed.
         */
        void placeRoad(const vector<string>& places, const vector<int>& placesNum, Board& board);

        /**
         * @brief Simulates rolling dice and assigns numbers to tiles on the board.
         * 
         * Randomly assigns numbers to tiles based on dice roll probabilities.
         */
        void rollDice();

        /**
         * @brief Prints the current state of the board.
         * 
         * Prints the tiles, cities, settlements, and roads on the board.
         */
        void printBoard() const;
    };
}

#endif // BOARD_HPP
