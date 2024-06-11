#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Represents a tile in a board game.
 * 
 * The Tile struct stores information about a tile, including its type and a number associated with it.
 */
struct Tile {
    string type = "";  ///< The type of resource or element the tile represents (e.g., "Brick", "Lumber").
    int number;   ///< A number associated with the tile, often used in game mechanics.

    /**
     * @brief Constructs a Tile object.
     * 
     * @param type The type of the tile (default is an empty string).
     * @param num The number associated with the tile (default is 0).
     */
    Tile(string type = "", int num = 0) : type(type), number(num) {}
};
    /*
      **Example usage
        Tile brickTile("Brick", 5);  // Creates a Tile object representing a brick tile with the number 5
        Tile defaultTile;            // Creates a default Tile object with empty type and number 0
    
    */