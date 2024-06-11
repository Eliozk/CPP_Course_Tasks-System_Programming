// Player.hpp

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <map>
// #include "Board.hpp"
// #include "Settlement.hpp"
// #include "Road.hpp"
// #include "DevelopmentCard.hpp"

using namespace std;

namespace ariel
{
  class Player
  {
  private:
    string name;
    int points;
    // vector<Settlement> settlements;
    // vector<Road> roads;
    // vector<City> cities;
    // vector<DevelopmentCard> devCards;
    map<string, int> resources;

  public:
    Player(const string &playerName);

    // Methods to place settlements and roads
    // void placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    // void placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);

    // Method to roll dice
    // void rollDice();

    // Method to trade resources
    // void trade(Player& otherPlayer, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount);

    // Method to buy development cards
    // void buyDevelopmentCard();

    // Method to print points
    // void printPoints() const;

    // Method to end turn
    // void endTurn();

    // Get player's name
    string getName() const;
  };
}
#endif