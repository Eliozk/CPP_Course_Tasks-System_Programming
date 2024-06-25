// Player.hpp

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Settlement.hpp"
#include "Board.hpp"
#include "Settlement.hpp"
#include "Tile.hpp"
#include "Card.hpp"
#include <string>
#include <vector>
#include <map>
using namespace std;
// #include "Resource.hpp"
// #include "DevelopmentCard.hpp"

namespace ariel
{

  // Forward declaration
  class Board;
  class Settlement; // Forward declaration
  class City;       // Forward declaration
  class Road;       // Forward declaration

  class Player
  {
  private:
    int playerNumber;
    string playerName;               ///< The name of the player.
    int points;                      ///< The player's points.
    vector<int> settlements;         ///< The player's settlements.
    int numberOfRoads;               ///< The number of roads the player has built.
    vector<int> cities;              ///< The player's cities.
    vector<int> roads;               ///< The player's roads.
    vector<Tile> tiles;              ///< The player's tiles.
    std::vector<Card *> playerCards; ///< The player's cards.
    map<string, int> resources;      ///< The player's resources.

  public:
    // Default constructor
    Player();
    Player(int num, const string &name);
    Player(const Player &other);            // Copy constructor
    Player &operator=(const Player &other); // Assignment operator
    // Destructor
    ~Player();
    void setName(const string &name);
    int getPoints() const;
    // Methods to place settlements and roads

    void addSettlement(int vertexIndex);
    void addRoad(int edgeIndex);
    void add1point();
    void add2point();
    
    int getPlayerNumber() const;
    vector<int> getRoads() const;
    vector<int> getPlayerSettlements() const;
    void placeRoad(const vector<string> &places, const vector<int> &placesNum, Board &board);
   
    void upgradeSettlementToCity(const Settlement &settlement);
    // Method to roll dice
    int rollDice() const;

    /**
     * @brief Distributes resources based on the dice roll result.
     * @param rollResult The result of the dice roll.
     * @param tiles The list of game tiles.
     */
    void resourcesFromRolledDice(int rollResult, const vector<Tile> &tiles);

    // Method to print points
    void printPoints() const;

    /**
     * @brief Adds resources to the player's inventory.
     * @param resource The type of resource to add.
     * @param quantity The quantity of the resource to add.
     */
    void addResource(const string &resource, int quantity);
    /**
     * @brief Removes resources from the player's inventory.
     * @param resource The type of resource to remove.
     * @param quantity The quantity of the resource to remove.
     */
    void removeResource(string resource, int quantity);

    // Get player's name
    string getName() const;

    // Add card to player's hand
    void addCard(Card *card);

  // Method to end turn
  // void endTurn();
 
   bool canBuySettlement();
   bool canBuyCity();
   bool canBuyRoad();
  // Method to trade resources
   void trade(Player& otherPlayer, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount);



    // Display player's hand
    void displayHand() const;
    void displayResources() const;
    void displayRoads() const;
    void displaySettlements() const;
    void displayAll() const;
  };


  // Method to buy development cards
  // void buyDevelopmentCard();

}
#endif