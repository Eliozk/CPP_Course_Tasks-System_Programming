#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include "Player.hpp"
/**
 * This is Header file for Settlement
 */
namespace ariel{
/**
 * @class Settlement
 * @brief Represents a settlement owned by a player in the game.
 */
class Settlement {
public:
    /**
     * @brief Constructor to create a Settlement.
     * @param owner Pointer to the player who owns the settlement.
     */
    Settlement(Player* owner);

    /**
     * @brief Constructs the settlement.
     */
    virtual void construct();

    /**
     * @brief Upgrades the settlement, potentially to a city.
     */
    virtual void upgrade();

protected:
    Player* owner; ///< Pointer to the player who owns the settlement.
};

/**
 * @class City
 * @brief Represents a city, which is an upgraded settlement owned by a player.
 */
class City : public Settlement {
public:
    /**
     * @brief Constructor to create a City.
     * @param owner Pointer to the player who owns the city.
     */
    City(Player* owner);

    /**
     * @brief Constructs the city.
     */
    void construct() override;

    /**
     * @brief Further upgrades the city.
     */
    void upgrade() override;
};
}
#endif // SETTLEMENT_HPP
