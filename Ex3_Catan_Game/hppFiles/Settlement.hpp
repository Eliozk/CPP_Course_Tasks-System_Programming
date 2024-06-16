#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include "Player.hpp"
/**
 * This is Header file for Settlement-ישוב
 */
namespace ariel
{
    /**
     * @class Settlement
     * @brief Represents a settlement owned by a player in the game.
     */
    class Settlement
    {
    public:
        /**
         * @brief Constructor to create a Settlement.
         * @param owner Pointer to the player who owns the settlement.
         */
        Settlement(Player *owner);

        /**
         * @brief Constructs the settlement.
         */
        virtual void construct();
      
        /**
         * @brief Gets the owner of the settlement.
         * @return Pointer to the player who owns the settlement.
         */
        Player* getOwner() const;

        /**
         * @brief Upgrades the settlement, potentially to a city.
         */
        void upgrade();

        
        virtual bool isAdjacentTo(const Tile& tile) const;

    protected:
        Player *owner; ///< Pointer to the player who owns the settlement.
    };

    /**
     * @class City
     * @brief Represents a city, which is an upgraded settlement owned by a player.
     */
    class City : public Settlement
    {
    public:
        /**
         * @brief Constructor to create a City.
         * @param owner Pointer to the player who owns the city.
         */
        City(Player *owner);

        /**
         * @brief Constructs the city.
         */
        void construct() override;
    };

    /**
     * @class Road
     * @brief Represents a road on board, road role is for construct cities and settlements.
     */
    class Road : public Settlement
    {
    public:
        /**
         * @brief Constructor to create a City.
         * @param owner Pointer to the player who owns the city.
         */
        Road(Player *owner);
        /**
         * @brief Constructs the road.
         */
        void construct() override;
    };
}
#endif // SETTLEMENT_HPP
