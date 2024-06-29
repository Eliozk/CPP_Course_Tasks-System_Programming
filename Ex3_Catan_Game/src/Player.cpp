// Player.cpp

#include "Player.hpp"
#include "Settlement.hpp"
#include "Catan.hpp"
#include "Tile.hpp"
#include <iostream>
#include <stdexcept>
#include <Board.hpp>
#include <algorithm>
#include <ctime>

using namespace std;
using namespace ariel;

int Player::maxKnights = 0;
bool Player::occupiedLargestArmy = 0;
// Constructor
Player::Player() {}
Player::Player(int num, const string &name) : playerNumber(num), playerName(name), points(0)
{
    // init resources
    resources["Ore"] = 0;    // ברזל
    resources["Wool"] = 0;   // צמר
    resources["Lumber"] = 0; // עץ לבנייה
    resources["Grain"] = 0;  // תבואה
    resources["Brick"] = 0;  // לבנים
    playerKnights = 0;
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
Player::~Player()
{
    for (Card *card : playerCards)
    {
        delete card; // Free memory for each card
    }
}
void Player::setName(const string &name)
{
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
vector<int> Player::getRoads() const
{
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

void Player::addSettlement(int vertexIndex)
{
    settlements.push_back(vertexIndex);
    cout << this->getName() << " added Settlement at Vertex " << vertexIndex << endl;
}

void Player::addRoad(int edgeIndex)
{
    roads.push_back(edgeIndex);
    cout << this->getName() << " added Road on Edge " << edgeIndex << endl;
}
void Player::addCity(int cityIndex)
{
    cities.push_back(cityIndex);
}

// Display player's resources
void Player::displayResources() const
{
    cout << playerName << "'s Resources:" << endl;
    for (const auto &resource : resources)
    {
        cout << resource.first << ": " << resource.second << " ";
    }
    cout << endl;
}

// Display player's roads
void Player::displayRoads() const
{
    cout << playerName << "'s Roads:" << endl;
    for (int road : roads)
    {
        cout << "Has Road at edge index: " << road << endl;
    }
}

// Display player's settlements
void Player::displaySettlements() const
{
    cout << playerName << "'s Settlements:" << endl;
    for (int settlement : settlements)
    {
        cout << "Settlement at vertex index: " << settlement << endl;
    }
}
// Display player's cities
void Player::displayCities() const
{
    cout << playerName << "'s Cities:" << endl;
    for (int city : cities)
    {
        cout << "City at vertex index: " << city << endl;
    }
    if (cities.empty())
    {
        cout << playerName << "'s have not build yet cities." << endl;
    }
}

// Display all player information
void Player::displayAll() const
{
    cout << "\nPlayer " << playerNumber + 1 << ", " << playerName << ": " << endl;
    cout << "Points: " << points << endl;
    displayResources();
    displayHand();
    displaySettlements();
    displayRoads();
    displayCities();
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

void playDevelopmentCard(const DevelopmentCard &card)
{
    // Implementation for playing a development card
    // this->playCard(card);
}

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
// Assuming Player class structure with necessary includes and definitions

// Method to find the last player who holds the "Largest Army" card and transfer it
Player *Player::findLastPlayerWithLargestArmy(vector<Player *> &players)
{
    Player *lastPlayerWithLargestArmy = nullptr;

    for (Player *player : players)
    {
        if (player->hasSpecialCard("Special: Largest Army"))
        {
                lastPlayerWithLargestArmy = player;
        }
    }

    return lastPlayerWithLargestArmy;
}

// add knight to player list of knights also update player points and handle special card largest army.
void Player::addKnight(vector<Player *> &players)
{
    bool HaveLargestArmy = 0;
    ++playerKnights;

    if (playerKnights >= 3 && playerKnights > maxKnights)
    {
        maxKnights = playerKnights;
        //check if has the special largest card.
        for (Card *card : getSpecialCards())
        {
            if (card->getType() == "Special: Largest Army")
            {
                HaveLargestArmy = 1;//true
                break;
            }
        }
        //if player doesnt have the Largestarmy card but other player has it and need to replace owner.
        if (!HaveLargestArmy && occupiedLargestArmy)
        {
            this->add2point(); // Award 2 victory points for Largest Army
            cout << playerName << " has earned the Largest Army card!" << std::endl;
            for(Player *playerToremoveSpecial : players){

              //  if-->Transfer the Largest Army card from last player who had it to new largest army of knights.
                if(playerToremoveSpecial->hasSpecialCard("Special: Largest Army")){
                    playerToremoveSpecial->transferSpecialCard(*this,"Special: Largest Army" );
                     std::cout << "Largest Army card transferred from " << playerToremoveSpecial->getName()
                          << " to " << this->getName() << std::endl;
                    break;
                }
            }
        }
        //if no one had the largest army card.
        else if(!occupiedLargestArmy){         
           vector<Card*>  specialCards = Catan::getMainSpecialCards();
            addSpecialCard(specialCards[1]);
            this->add2point();
            //now it is occupied by a player.
            occupiedLargestArmy =1;
            cout << playerName << " has earned the Largest Army card!" << endl;
        }

    }
}

// Add a special card to the player's collection
void Player::addSpecialCard(Card *card)
{
    specialCards.push_back(card);
}

// Check if the player has a specific type of special card
bool Player::hasSpecialCard(const string &type) const
{
    for (Card *card : specialCards)
    {
        if (card->getType() == type)
        {
            return true;
        }
    }
    return false;
}

// Transfer a specific type of special card to another player
void Player::transferSpecialCard(Player &playerToadd, const string &type)
{
    auto it = std::find_if(specialCards.begin(), specialCards.end(), [&](Card *card)
                           { return card->getType() == type; });

    if (it != specialCards.end())
    {
        // Transfer the card to the other player
        playerToadd.addSpecialCard(*it);
        this->specialCards.erase(it); // Remove the card from current player's collection
        this->points -= 2;  //remove his 2 points.
    }
}

// Add card to player's hand
void Player::addCard(Card *card)
{
    playerCards.push_back(card);
}

void Player::playCard(Board &board, Card &card)
{
   // card.play(*this);
  cout << "Executing DevelopmentCardStrategy for player: " << this->getName() << " with card: " << card.getType() << std::endl;

        string cardType = card.getType();

        if (cardType == "Victory Point")
        {
            // Example implementation for Victory Point card
            this->add1point();
        }
        else if (cardType == "Road Building")
        {
            // Example implementation for Road Building card
            // player can build 2 roads for free
             board.buildRoadFree(*this);
             board.buildRoadFree(*this);
        }
        else if (cardType == "Year Of Plenty")
        {
            // Example implementation for Year Of Plenty card
            // player gets 2 resources of their choice from the bank
            this->addResource("choice1", 1);
            this->addResource("choice2", 1);
        }
        else if (cardType == "Monopoly")
        {
            // Example implementation for Monopoly card
            // player chooses a resource, all other players must give all their resources of that type to this player
            // std::string chosenResource = player.chooseResource();
            // std::unordered_map<std::string, int> totalResources = player.collectResourceFromOthers(chosenResource);
            // player.addResources(totalResources);
        }
        else
        {
            std::cerr << "Unknown card type: " << cardType << std::endl;
        }
    // Find the card pointer in playerCards and remove it
    auto it = std::find_if(playerCards.begin(), playerCards.end(), [&](Card *c)
                           {
                               return (c == &card); // Compare addresses of pointers
                           });

    if (it != playerCards.end())
    {
        playerCards.erase(it); // Erase the card pointer from the vector
    }
    else
    {
        // Handle case where card is not found (should not normally happen if managed properly)
        std::cerr << "Card to play not found in player's hand." << std::endl;
    }
}

bool Player::canBuyDevelopmentCard() const
{

    // Check if player has enough resources: 1 ore, 1 wool, and 1 grain
    return resources.at("Ore") >= 1 && resources.at("Wool") >= 1 && resources.at("Grain") >= 1;
}

/**
 * bool Player::buyDevelopmentCard(std::vector<Card *> &developmentCards) {



    std::cout << name << " bought a " << card->getType() << " card." << std::endl;
    return true;
}
 */

// dev card price is Ore 1, Wool 1, grain 1
bool Player::buyDevelopmentCard(vector<Card *> &cards, vector<Player *> &players)
{
    if (cards.empty())
    {
        cout << "There are no more development cards left." << std::endl;
        return false;
    }

    if (canBuyDevelopmentCard())
    {
        resources["Ore"] -= 1;   // ברזל נחושת
        resources["Wool"] -= 1;  // צמר
        resources["Grain"] -= 1; // תבואה

        // Take the top card from the deck
        Card *card = cards.back();
        cards.pop_back();
        playerCards.push_back(card);
        if (card->getType() == "Knight")
        {
           
            this->addKnight(players);

            cout << this->getName() << " have new " << card->getType() << " card." << endl;
        }
        else
        {
            cout << this->getName() << " have new Development card - " << card->getType() << " card." << endl;
        }
        // Logic to draw a development card and add it to the player's hand
        return true;
    }
    else
    {
        cout << "Not enough resources to buy a development card." << std::endl;
    }
    return false;
}

vector<int> Player::getPlayerSettlements() const
{
    return settlements;
}
vector<Card *> Player::getPlayerCards() const
{
    return playerCards;
}

vector<Card *> Player::getSpecialCards() const
{
    return specialCards;
}
// Display player's hand
void Player::displayHand() const
{
    cout << playerName << "'s Hand:" << std::endl;
    if (playerCards.empty())
    {
        cout << playerName << " has no cards yet." << std::endl;
    }
    else
    {
        for (size_t i = 0; i < playerCards.size(); ++i)
        {
            std::cout << playerCards[i]->getType();
            if (i != playerCards.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
}



// void Player::useYearOfPlenty(string resource1, string resource2)
// {
//     // check if the player has a year of plenty card
//     for (int i = 0; i < developmentCardCount; i++)
//     {
//         if (developmentCards[i] == "Year of Plenty")
//         {
//             // check if the player can get the resources
//             addResource(resource1, 1);
//             addResource(resource2, 1);
//             // delete the year of plenty card from the player's deck
//             developmentCards.erase(developmentCards.begin() + i);
//             developmentCardCount--;
//             return;
//         }
//     }
//     cout << "Player " << this->getName() << " does not have a year of plenty card" << endl;
// }

// void Player::useMonopoly(Board &board, string resource)
// {
//     // check if the player has a monopoly card
//     for (int i = 0; i < developmentCardCount; i++)
//     {
//         if (developmentCards[i] == "Monopoly")
//         {
//             // check if the player can get the resources
//             for (int j = 0; j < 3; j++)
//             {
//                 if (board.players[j]->getId() != this->getId())
//                 {
//                     for (int k = 0; (long unsigned int)k < board.players[j]->resources.size(); k++)
//                     {
//                         if (board.players[j]->resources[k].first == resource)
//                         {
//                             addResource(resource, board.players[j]->resources[k].second);
//                             board.players[j]->resources[k].second = 0;
//                         }
//                     }
//                 }
//             }
//             // delete the monopoly card from the player's deck
//             developmentCards.erase(developmentCards.begin() + i);
//             developmentCardCount--;
//             return;
//         }
//     }
//     cout << "Player " << this->getName() << " does not have a monopoly card" << endl;
// }

// // A function that allows the player to trade resources with other players
// // resorce1 is the resource that the player wants to get from the other player
// void Player::tradeResources(Board &board, int player, string resource1, int amount, string resource2, int amount2)
// {
//     // check if the player has the resources
//     for (int i = 0; i < 5; i++)
//     {
//         if (resources[i].first == resource2 && resources[i].second >= amount2)
//         {
//             // check if the other player has the resources
//             for (int j = 0; j < 5; j++)
//             {
//                 if (board.players[player - 1]->resources[j].first == resource1 && board.players[player - 1]->resources[j].second >= amount)
//                 {
//                     // trade the resources
//                     resources[j].second += amount2;
//                     resources[i].second -= amount2;
//                     board.players[player - 1]->resources[i].second += amount;
//                     board.players[player - 1]->resources[j].second -= amount;
//                     cout << "Player " << this->getName() << " traded " << amount << " " << resource1 << " with player " << board.players[player - 1]->getName() << " for " << amount2 << " " << resource2 << endl;
//                     // print the resources that the player has after trading
//                     cout << "Player " << this->getName() << " now has resources: Wood: " << resources[0].second << ", Brick: " << resources[1].second << ", Wool: " << resources[2].second << ", Wheat: " << resources[3].second << ", Ore: " << resources[4].second << endl;
//                     // print the resources that the other player has after trading
//                     cout << "Player " << board.players[player - 1]->getName() << " now has resources: Wood: " << board.players[player - 1]->resources[0].second << ", Brick: " << board.players[player - 1]->resources[1].second << ", Wool: " << board.players[player - 1]->resources[2].second << ", Wheat: " << board.players[player - 1]->resources[3].second << ", Ore: " << board.players[player - 1]->resources[4].second << endl;
//                     return;
//                 }
//             }
//         }
//     }
//     // print that the trade was not successful
//     cout << "Player " << this->getName() << " cannot trade " << amount << " " << resource1 << " with player " << board.players[player - 1]->getName() << " for " << amount2 << " " << resource2 << endl;
// }