#ifndef TILE_HPP
#define TILE_HPP

#include <string>

namespace ariel
{

    using namespace std;

    class Player; // Forward declaration if Tile uses Player
    /**
     * @class Tile
     * @brief Represents a generic tile in the game.
     */
    class Tile
    {

    public:
        int number;  ///< The number associated with the tile.
        string name; ///< The name/type of the tile.

        Tile() : number(0), name("") {} // Default constructor

        /**
         * @brief Constructor to create a Tile.
         * @param number The number associated with the tile.
         * @param name The name/type of the tile.
         */
        Tile(int number, const string &name);

        /**
         * @brief Gets the number associated with the tile.
         * @return The tile number.
         */
        int getNumber() const;

        /**
         * @brief Gets the name/type of the tile.
         * @return The tile name/type.
         */
        string getName() const;

        /**
         * @brief Pure virtual function to get the resource type of the tile.
         * @return The resource type as a string.
         */
        virtual string getResource() const
        {
            return ""; // Default implementation for tiles that don't yield resources
        }
    };

    /**
     * @class Forest
     * @brief Represents a forest tile in the game.
     */
    class Forest : public Tile
    {
    public:
        /**
         * @brief Constructor to create a Forest tile.
         * @param number The number associated with the forest tile.
         */
        Forest(int number);

        /**
         * @brief Gets the resource type of the forest tile.
         * @return The resource type as a string ("Wood").
         */
        string getResource() const override;
    };

    /**
     * @class Hill
     * @brief Represents a hills tile in the game.
     */
    class Hill : public Tile
    {
    public:
        /**
         * @brief Constructor to create a Hills tile.
         * @param number The number associated with the hills tile.
         */
        Hill(int number);

        /**
         * @brief Gets the resource type of the hills tile.
         * @return The resource type as a string ("Brick").
         */
        string getResource() const override;
    };

    /**
     * @class Pasture
     * @brief Represents a pasture tile in the game.
     */
    class Pasture : public Tile
    {
    public:
        /**
         * @brief Constructor to create a Pasture tile.
         * @param number The number associated with the pasture tile.
         */
        Pasture(int number);

        /**
         * @brief Gets the resource type of the pasture tile.
         * @return The resource type as a string ("Sheep").
         */
        string getResource() const override;
    };

    /**
     * @class Field
     * @brief Represents a field tile in the game.
     */
    class Field : public Tile
    {
    public:
        /**
         * @brief Constructor to create a Field tile.
         * @param number The number associated with the field tile.
         */
        Field(int number);

        /**
         * @brief Gets the resource type of the field tile.
         * @return The resource type as a string ("Wheat").
         */
        string getResource() const override;
    };

    /**
     * @class Mountain
     * @brief Represents a mountain tile in the game.
     */
    class Mountain : public Tile
    {
    public:
        /**
         * @brief Constructor to create a Mountain tile.
         * @param number The number associated with the mountain tile.
         */
        Mountain(int number);

        /**
         * @brief Gets the resource type of the mountain tile.
         * @return The resource type as a string ("Ore").
         */
        string getResource() const override;
    };

    /**
     * @class Desert
     * @brief Represents a desert tile in the game.
     */
    class Desert : public Tile
    {
    public:
        /**
         * @brief Constructor to create a Desert tile.
         * @param number The number associated with the desert tile.
         */
        Desert(int number);
        // Implementation for Desert
        string getResource() const override;
    };

} // namespace ariel

#endif // TILE_HPP
