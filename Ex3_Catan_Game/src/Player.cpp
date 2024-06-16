// Player.cpp

#include "Player.hpp"
#include "Settlement.hpp"
#include "Tile.hpp"
#include <iostream>
#include <stdexcept>
#include <Board.hpp>
#include <algorithm>
#include <ctime>

using namespace std;
using namespace ariel;

// Constructor
Player::Player(const string &playerName) : name(playerName), points(0)
{
    // init resources
}
// Getters
string Player::getName() const
{
    return name;
}

int Player::getPoints() const
{
    return points;
}

void Player::placeSettlement(const vector<string> &places, const vector<int> &placesNum, Board &board)
{
    // Implementation to place settlement on the board
    // Update player's points
    points += 1;
}

void Player::placeRoad(const vector<string> &places, const vector<int> &placesNum, Board &board)
{
    // Implementation to place road on the board
    numberOfRoads++;
}

void Player::upgradeSettlementToCity(const Settlement &settlement)
{
    auto it = find(settlements.begin(), settlements.end(), settlement);
    if (it != settlements.end())
    {
        settlements.erase(it);
        cities.push_back(City(settlement.getOwner()));
        points += 1; // Increment points for upgrading to a city
    }
}
//This function return number of rolled 2 dices.
int Player::rollDice() const
{
   
    srand(time(0)); // Initialize the random number generator with the current time as a seed
   
    int die1 = rand() % 6 + 1;// Generate a random number between 1 and 6 for the first die
    int die2 = rand() % 6 + 1;// Generate a random number between 1 and 6 for the second die
    
    int rollResult = die1 + die2;
    cout << name << " rolled a " << rollResult << endl;
    return rollResult;
}

void Player::resourcesFromRolledDice(int rollResult, const vector<Tile>& tiles)
{
    for (const Tile &tile : tiles)
    {
        if (tile.getNumber() == rollResult)
        {
            string resource = tile.getResource();
            for (Settlement &settlement : settlements)
            {
                if (settlement.isAdjacentTo(tile))
                {
                    addResource(resource, 1);
                }
            }
            for (City &city : cities)
            {
                if (city.isAdjacentTo(tile))
                {
                    addResource(resource, 1);
                }
            }
        }
    }
}


// void Player::trade(Player& otherPlayer, const string& giveResource, const string& getResource, int giveAmount, int getAmount) {
//     // Implementation for trading resources
//     if (resources[giveResource] >= giveAmount) {
//         resources[giveResource] -= giveAmount;
//         resources[getResource] += getAmount;
//         otherPlayer.resources[giveResource] += giveAmount;
//         otherPlayer.resources[getResource] -= getAmount;
//     } else {
//         throw std::runtime_error("Insufficient resources for trade");
//     }
// }

// void Player::buyDevelopmentCard() {
//     // Implementation to buy development card
// }

/**
 * void playDevelopmentCard(const DevelopmentCard& card) {
        // Implementation for playing a development card
    }
 */

void Player::printPoints() const {
    std::cout << name << " has " << points << " points." << std::endl;
}

// void Player::endTurn() {
//     // Implementation to end turn
// }


 // Methods to manage resources to each player.
    void Player::addResource(string &resource, int quantity) {
        resources[resource] += quantity;
    }
 

   void Player::removeResource(string resource, int quantity) {
        if (resources[resource] >= quantity) {
            resources[resource] -= quantity;
        }
    }
 
