#include "Tile.hpp"

using namespace std;
using namespace ariel;

/**
 * @brief Constructor to create a Tile.
 * Initializes the Tile object with the given number.
 * @param number The number associated with the tile.
 */
Tile::Tile(int number) : number(number) {}

/**
 * @brief Gets the number associated with the tile.
 * @return The tile number.
 */
int Tile::getNumber() const {
    return number;
}

/**
 * @brief Constructor to create a Forest tile.
 * Initializes the Forest object with the given number, inheriting from Tile.
 * @param number The number associated with the forest tile.
 */
Forest::Forest(int number) : Tile(number) {}

/**
 * @brief Gets the resource type of the forest tile.
 * Returns the resource type of the forest tile as "Wood".
 * @return The resource type as a string ("Wood").
 */
string Forest::getResource() const {
    return "Wood";
}

/**
 * @brief Constructor to create a Hills tile.
 * Initializes the Hills object with the given number, inheriting from Tile.
 * @param number The number associated with the hills tile.
 */
Hills::Hills(int number) : Tile(number) {}

/**
 * @brief Gets the resource type of the hills tile.
 * Returns the resource type of the hills tile as "Brick".
 * @return The resource type as a string ("Brick").
 */
string Hills::getResource() const {
    return "Brick";
}

/**
 * @brief Gets the resource type of the Pasture tile.
 * Returns the resource type of the Pasture tile as "Sheep".
 * @return The resource type as a string ("Sheep").
 */
//אדמת מרעה מחזיר צמר
Pasture::Pasture(int number) : Tile(number) {}

string Pasture::getResource() const {
    return "Sheep";
}
/**
 * @brief Gets the resource type of the Field tile.
 * Returns the resource type of the Field tile as "Wheat".
 * @return The resource type as a string ("Wheat").
 */
//אדמה חקלאית מחזיר שיבולת
Field::Field(int number) : Tile(number) {}

string Field::getResource() const {
    return "Wheat";
}
/**
 * @brief Gets the resource type of the Mountain tile.
 * Returns the resource type of the Mountain tile as "Ore".
 * @return The resource type as a string ("Ore").
 */
//הרים מחזיר ברזל
Mountain::Mountain(int number) : Tile(number) {}

string Mountain::getResource() const {
    return "Ore";//עופרת ואו ברזל
}
//dessert dont give nothing but he is in the middle of the board always.
Dessert::Dessert(int number) : Tile(number) {}

