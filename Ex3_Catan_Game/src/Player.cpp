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
Player::Player() {}
Player::Player(int num, const string &name) : playerNumber(num), playerName(name), points(0)
{
    // init resources
    resources["Ore"] = 0;//ברזל
    resources["Wool"] = 0;//צמר
    resources["Lumber"] = 0;//עץ לבנייה
    resources["Grain"] = 0;//תבואה
    resources["Brick"] = 0;//לבנים
}
Player &Player::operator=(const Player &other)
{
    if (this != &other)
    {
        playerNumber = other.playerNumber;
        playerName = other.playerName;
        points = other.points;
        settlements = other.settlements;
        numberOfRoads = other.numberOfRoads;
        cities = other.cities;
        roads = other.roads;
        tiles = other.tiles;
        playerCards = other.playerCards;
        resources = other.resources;
    }
    return *this;
}
Player::Player(const Player &other)
    : playerNumber(other.playerNumber), playerName(other.playerName), points(other.points),
      settlements(other.settlements), numberOfRoads(other.numberOfRoads),
      cities(other.cities), roads(other.roads), tiles(other.tiles),
      playerCards(other.playerCards), resources(other.resources) {}

      // Destructor
Player::~Player() {
    for (Card* card : playerCards) {
        delete card;  // Free memory for each card
    }
}
void Player::setName(const string &name){
    playerName = name;
}


 

// Getters
string Player::getName() const
{
    return playerName;
}
int Player::getPlayerNumber() const
{
    return playerNumber;
}

int Player::getPoints() const
{
    return points;
}
vector<int> Player::getRoads() const {
    return roads;
} 

void Player::add1point()
{
    points += 1;
}
void Player::add2point()
{
    points += 2;
}
bool Player::canBuySettlement()
{
    // Check if the player has enough resources for a settlement
    return (resources["Lumber"] >= 1 && resources["Brick"] >= 1 &&
            resources["Grain"] >= 1 && resources["Wool"] >= 1);
}

bool Player::canBuyCity()
{
    // Check if the player has enough resources for a city
    return (resources["Ore"] >= 3 && resources["Grain"] >= 2);
}

bool Player::canBuyRoad()
{
    // Check if the player has enough resources for a road
    return (resources["Brick"] >= 1 && resources["Lumber"] >= 1);
}



void Player::placeRoad(const vector<string> &places, const vector<int> &placesNum, Board &board)
{
    // Implementation to place road on the board
    numberOfRoads++;
}

void Player::addSettlement(int vertexIndex) {
    settlements.push_back(vertexIndex);
    cout << this->getName() << " added Settlement at Vertex " << vertexIndex <<endl;
}

void Player::addRoad(int edgeIndex) {
    roads.push_back(edgeIndex);
    cout << this->getName() << " added Road on Edge " << edgeIndex <<endl;
}

// void Player::upgradeSettlementToCity(const Settlement &settlement)
// {
//     auto it = find(settlements.begin(), settlements.end(), settlement);
//     if (it != settlements.end())
//     {
//         settlements.erase(it);
//         cities.push_back(City(settlement.getOwner()));
//         points += 1; // Increment points for upgrading to a city
//     }
// }
// This function return number of rolled 2 dices.
int Player::rollDice() const
{

    srand(time(0)); // Initialize the random number generator with the current time as a seed

    int die1 = rand() % 6 + 1; // Generate a random number between 1 and 6 for the first die
    int die2 = rand() % 6 + 1; // Generate a random number between 1 and 6 for the second die

    int rollResult = die1 + die2;
    cout << playerName << " rolled a " << rollResult << endl;
    return rollResult;
}

// Display player's resources
void Player::displayResources() const {
    cout << playerName << "'s Resources:" << endl;
    for (const auto &resource : resources) {
        cout << resource.first << ": " << resource.second << endl;
    }
}

// Display player's roads
void Player::displayRoads() const {
    cout << playerName << "'s Roads:" << endl;
    for (int road : roads) {
        cout << "Has Road at edge index: " << road << endl;
    }
}

// Display player's settlements
void Player::displaySettlements() const {
    cout << playerName << "'s Settlements:" << endl;
    for (int settlement : settlements) {
        cout << "Settlement at vertex index: " << settlement << endl;
    }
}

// Display all player information
void Player::displayAll() const {
    cout << "Player " << playerNumber+1 << ": " << playerName << endl;
    cout << playerName <<" Points: " << points << endl;
    displayResources();
    displayHand();
    displayRoads();
    displaySettlements();
}

// void Player::resourcesFromRolledDice(int rollResult, const vector<Tile> &tiles)
// {
//     for (const Tile &tile : tiles)
//     {
//         if (tile.getNumber() == rollResult)
//         {
//             string resource = tile.getResource();
//             for (Settlement &settlement : settlements)
//             {
//                 if (settlement.isAdjacentTo(tile))
//                 {
//                     addResource(resource, 1);
//                 }
//             }
//             for (City &city : cities)
//             {
//                 if (city.isAdjacentTo(tile))
//                 {
//                     addResource(resource, 1);
//                 }
//             }
//         }
//     }
// }

// void Player::promptAndSetSettlement(Board& board, const Player& player) {
//     int row, col;
//     cout << player.name << ", enter the row and column to place your settlement: ";
//     cin >> row >> col;
//     board.setSettlement(row, col, player.name);
//     //cout << "Invalid position or position already occupied. Try again." << endl;
// }

// void Player::promptAndSetRoad(Board& board, const Player& player) {
//     int row, col;
//     cout << player.name << ", enter the row and column to place your road: ";
//     cin >> row >> col;
//     board.setRoad(row, col, player.name);
//     //cout << "Invalid position or position already occupied. Try again." << endl;
// }

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

void Player::printPoints() const
{
    std::cout << playerName << " has " << points << " points." << std::endl;
}

// void Player::endTurn() {
//     // Implementation to end turn
// }

// Methods to manage resources to each player.
void Player::addResource(const string &resource, int quantity)
{
    resources[resource] += quantity;
}

void Player::removeResource(string resource, int quantity)
{
    if (resources[resource] >= quantity)
    {
        resources[resource] -= quantity;
    }
}
// Add card to player's hand
void Player::addCard(Card* card) {
    playerCards.push_back(card);
}

vector<int> Player::getPlayerSettlements() const {
    return settlements;
}
// Display player's hand
void Player::displayHand() const {
    cout << playerName << "'s Hand:" << endl;
    for (Card* card : playerCards) {
        cout << "Type: " << card->getType() << endl;
    }
}