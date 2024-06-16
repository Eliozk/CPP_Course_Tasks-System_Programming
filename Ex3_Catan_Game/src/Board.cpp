#include "Board.hpp"
#include "Tile.hpp"
#include <iomanip>
#include <random>
#include <iostream>


using namespace ariel;
using namespace std;

Board::Board()
{
    int hexagonsPerRow[5] = {3, 4, 5, 4, 3};

    tiles.resize(5); // Initialize tiles with 5 rows
    // Resize each row to the correct number of columns
    for (int i = 0; i < 5; ++i)
    {
        tiles[i].resize(hexagonsPerRow[i]);
        settlements.resize(5); // Initialize settlements with 5 rows
        roads.resize(5);       // Initialize roads with 5 rows

        for (int i = 0; i < 5; ++i)
        {
            tiles[i].resize(hexagonsPerRow[i]);            // Resize each row to the correct number of hexagons
            settlements[i].resize(hexagonsPerRow[i], ' '); // Initialize settlements vector for each row
            roads[i].resize(hexagonsPerRow[i], ' ');       // Initialize roads vector for each row
        }
    }
}
    // random number beteen 1-->12 including them.
    int Board::randomNum()
    {
        vector<int> numbers = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, numbers.size() - 1);
        int index = dist(gen);
        int num = numbers[index];
        numbers.erase(numbers.begin() + index); // Remove the selected number from the vector
        return num;
    }

    void Board::setTile(int row, int col, const string &type) {
    if (row >= 0 && row < ROWS && col >= 0 && col < tiles[row].size()) {
        int number = randomNum();
        tiles[row][col].number = number; // Access the number member directly
        tiles[row][col].name = type;     // Access the name member directly
    } else {
        throw out_of_range("Tile position out of range");
    }
}

    void Board::placeSettlement(const vector<string> &places, const vector<int> &placesNum, char structureType, Board &board)
    {
        for (size_t i = 0; i < places.size(); ++i)
        {
            int row = placesNum[i] / COLS;
            int col = placesNum[i] % COLS;
            if (row >= 0 && row < ROWS && col >= 0 && col < board.settlements[row].size())
            {
                if (structureType == 'c')
                {
                    board.settlements[row][col] = 'C'; // Use 'C' for city
                }
                else if (structureType == 's')
                {
                    board.settlements[row][col] = 'S'; // Use 'S' for settlement
                }
            }
        }
    }

    void Board::placeRoad(const vector<string> &places, const vector<int> &placesNum, Board &board)
    {
        for (size_t i = 0; i < places.size(); ++i)
        {
            int row = placesNum[i] / COLS;
            int col = placesNum[i] % COLS;
            if (row >= 0 && row < ROWS && col >= 0 && col < board.roads[row].size())
            {
                board.roads[row][col] = 'D'; // Use 'D' for road
            }
        }
    }

    void Board::rollDice()
    {
        // Initialize random number generator
        random_device rd;
        mt19937 gen(rd());

        // Define probabilities for each dice roll result
        vector<int> diceProbabilities = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1}; // Example probabilities

        // Distribute random numbers according to probabilities
        discrete_distribution<int> diceDistribution(diceProbabilities.begin(), diceProbabilities.end());

        // Assign random numbers to tiles
        for (auto &row : tiles)
        {
            for (auto &tile : row)
            {
                int roll = diceDistribution(gen) + 2; // Add 2 to get numbers from 2 to 12
                tile.number = roll;
            }
        }
    }

    void Board::printBoard() const
    {
        // Number of hexagons in each row
        int hexagonsPerRow[5] = {3, 4, 5, 4, 3};

        for (int i = 0; i < 5; ++i)
        {
            // Print empty line above hexagons

            int spaces = 8 - hexagonsPerRow[i]; // Ensure spaces is non-negative and Calculate leading spaces

            // Print cities or settlements ("city") above hexagons labeled as "C"
            cout << string(spaces * 4, ' '); // Adjust the spacing as needed
            for (int j = 0; j < hexagonsPerRow[i]; ++j)
            {
                cout << "    " << settlements[i][j] << "    "; // Adjust the spacing as needed
            }
            cout << endl;

            // Print top line of hexagons with additional spaces
            cout << string(spaces * 4, ' '); // Adjust the spacing as needed
            for (int j = 0; j < hexagonsPerRow[i]; ++j)
            {
                cout << " /" << (!tiles[i][j].name.empty() ? tiles[i][j].name[0] : ' ') << "  \\    ";
            }
            cout << endl;

            // Print middle part of hexagons (roads) labeled as "R" with additional spaces
            cout << string(spaces * 4, ' '); // Adjust the spacing as needed
            for (int j = 0; j < hexagonsPerRow[i]; ++j)
            {

                // char road = (i < roads.size() && j < roads[i].size()) ? 'R' : ' ';
                cout << "| " << tiles[i][j].number << "   |  ";
            }
            cout << endl;

            // Print bottom sides of hexagons with additional spaces
            cout << string(spaces * 4, ' '); // Adjust the spacing as needed
            for (int j = 0; j < hexagonsPerRow[i]; ++j)
            {
                cout << " \\___/    ";
            }
            cout << endl;
        }
    }

    /**
     * void Board::printBoard() const {
        // Number of hexagons in each row
        int hexagonsPerRow[5] = {3, 4, 5, 4, 3};

        for (int i = 0; i < 5; ++i) {
            // Print empty line above hexagons
            cout << endl;
            int spaces = max(0, 4 - hexagonsPerRow[i]); // Ensure spaces is non-negative and Calculate leading spaces
            // Print top line of hexagons
            cout << string(spaces * 4, ' ');
            // Print cities or settlements above hexagons
            for (int j = 0; j < hexagonsPerRow[i]; ++j) {
                cout << "\t" << (i < cities.size() && j < cities[i].size() ? cities[i][j] : ' ') << " ";
            }
            cout << endl;

            // Print top line of hexagons
            for (int j = 0; j < hexagonsPerRow[i]; ++j) {
                cout << " /" << (!tiles[i][j].type.empty() ? tiles[i][j].type[0] : ' ') << "  \\  ";
            }
            cout << endl;

            // Print middle part of hexagons (roads)
            for (int j = 0; j < hexagonsPerRow[i]; ++j) {
                char road = (i < roads.size() && j < roads[i].size()) ? roads[i][j] : ' ';
                cout << "|" << road << "road| ";
            }
            cout << endl;

            // Print bottom sides of hexagons
            for (int j = 0; j < hexagonsPerRow[i]; ++j) {
                cout << " \\___/ ";
            }
            cout << endl;
        }
    }
     */
