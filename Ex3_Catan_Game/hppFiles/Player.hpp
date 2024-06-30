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
    int playerKnights;
    static int maxKnights;  // Static variable to track max knights across all players
    static bool occupiedBiggesttArmy;
    static bool occupiedLargestRoad;
    static int longestRoad;

    bool hasMaxKnights;
    
    vector<int> settlements;         ///< The player's settlements.
    int numberOfRoads;               ///< The number of roads the player has built.
    vector<int> cities;              ///< The player's cities.
    vector<int> roads;               ///< The player's roads.
    vector<Tile> tiles;              ///< The player's tiles.
    vector<Card *> playerCards; ///< The player's cards.
     vector<Card *> specialCards; ///< The player's special cards.
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
    map<string, int>& getResources();
    // Methods to place settlements and roads

    void addSettlement(int vertexIndex);
    void removeSettlement(int vertexIndex);
    void addRoad(int edgeIndex);
    void addCity(int cityindex);
    void add1point();
    void add2point();
     
    void addKnight(vector<Player*>& players);
    // bool hasMaxKnights() const;  // Declaration of hasMaxKnights function
    void transferSpecialCard(Player& otherPlayer, const string& type);
    Player* findLastPlayerWithSpecialCard(vector<Player*>& players, const string& type );
    bool hasSpecialCard(const string& type) const;
    void addSpecialCard(Card* card);
     vector<Card *> getSpecialCards() const;
    int getPlayerNumber() const;
    
    vector<Card *> getPlayerCards() const;

    vector<int> getRoads() const;
    vector<int> getPlayerSettlements() const;
     void checkLargestRoad(vector<Player*>& players, Board& board);
   
 
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
    void playCard(Board &board, Card &card,vector<Player *> &players);
  // Method to end turn
  // void endTurn();
 
   bool canBuySettlement();
   bool canBuyCity();
   bool canBuyRoad();

   bool canBuyDevelopmentCard() const;
   bool buyDevelopmentCard(vector<Card *> &cards, vector<Player*>& players);
  // Method to trade resources
   void trade(Player& otherPlayer, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount);



    // Display player's hand
    void displayHand() const;
    void displayResources() const;
    void displayRoads() const;
    void displaySettlements() const;
    void displayCities() const;
    void displayAll() const;
  };


  // Method to buy development cards
  // void buyDevelopmentCard();

}
#endif