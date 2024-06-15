#ifndef TILE_HPP
#define TILE_HPP

#include <string>

using namespace std;

namespace ariel {

    /**
     * @class Tile
     * @brief Represents a generic tile in the game.
     */
    class Tile {
    public:
        /**
         * @brief Virtual function to get the resource type of the tile.
         * @return The resource type as a string.
         */
        virtual string getResource() const = 0;

        /**
         * @brief Gets the number associated with the tile.
         * @return The tile number.
         */
        int getNumber() const;

    protected:
        /**
         * @brief Constructor to create a Tile.
         * @param number The number associated with the tile.
         */
        Tile(int number);

        int number; ///< The number associated with the tile.
    };

    /**
     * @class Forest
     * @brief Represents a forest tile in the game.
     */
    class Forest : public Tile {
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
     * @class Hills
     * @brief Represents a hills tile in the game.
     */
    class Hill : public Tile {
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
    //אדמת מרעה מניבה - צמר
    class Pasture : public Tile {
    public:
        Pasture(int number);

        string getResource() const override;
    };

    class Field : public Tile {
    public:
        Field(int number);

        string getResource() const override;
    };

    class Mountain : public Tile {
    public:
        Mountain(int number);

        string getResource() const override;
    };

    class Dessert : public Tile {
        //should be in the middle always.
    public:
        Dessert(int number);
    };


} // namespace ariel

#endif // TILE_HPP
