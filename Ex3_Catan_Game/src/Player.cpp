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
#include <limits>

using namespace std;
using namespace ariel;
int Player::longestRoad = 5;

int Player::maxKnights = 0;
bool Player::occupiedLargestRoad = 0;
bool Player::occupiedBiggesttArmy = 0;
// Constructor
Player::Player() {}
Player::Player(int num, const string &name) : playerNumber(num), playerName(name), points(0)
{
    // init resources
    resources["Ore"] = 100;    // ברזל
    resources["Wool"] = 100;   // צמר
    resources["Lumber"] = 100; // עץ לבנייה
    resources["Grain"] = 100;  // תבואה
    resources["Brick"] = 100;  // לבנים
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

void Player::removeSettlement(int vertexIndex)
{
    // Find the settlement in the vector
    auto it = std::find(settlements.begin(), settlements.end(), vertexIndex);
    
    // If the settlement is found, remove it
    if (it != settlements.end())
    {
        settlements.erase(it);
    }
    else
    {
        cerr << "Settlement not found at vertex index: " << vertexIndex << endl;
    }
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
Player *Player::findLastPlayerWithSpecialCard(vector<Player *> &players, const string& type)
{
    Player *lastPlayerWithLargestArmy = nullptr;

    for (Player *player : players)
    {
        if (player->hasSpecialCard(type))
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
        // check if has the special largest card.
        for (Card *card : getSpecialCards())
        {
            if (card->getType() == "Special: Largest Army")
            {
                HaveLargestArmy = 1; // true
                break;
            }
        }
        // if player doesnt have the Largestarmy card but other player has it and need to replace owner.
        if (!HaveLargestArmy && occupiedBiggesttArmy)
        {
            this->add2point(); // Award 2 victory points for Largest Army
            cout << playerName << " has earned the Largest Army card!" << std::endl;
            for (Player *playerToremoveSpecial : players)
            {

                //  if-->Transfer the Largest Army card from last player who had it to new largest army of knights.
                if (playerToremoveSpecial->hasSpecialCard("Special: Largest Army"))
                {
                    playerToremoveSpecial->transferSpecialCard(*this, "Special: Largest Army");
                    std::cout << "Largest Army card transferred from " << playerToremoveSpecial->getName()
                              << " to " << this->getName() << std::endl;
                    break;
                }
            }
        }
        // if no one had the largest army card.
        else if (!occupiedBiggesttArmy)
        {
            vector<Card *> specialCards = Catan::getMainSpecialCards();
            addSpecialCard(specialCards[1]);
            this->add2point();
            // now it is occupied by a player.
            occupiedBiggesttArmy = 1;
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
void Player::transferSpecialCard(Player &playerToAdd, const string &type)
{    
    bool cardFound = false; // To check if any card is found and transferred

    auto it = specialCards.begin();
    while (it != specialCards.end())
    {
        if ((*it)->getType() == type)
        {
            // Transfer the card to the other player
            playerToAdd.addSpecialCard(*it);
            it = specialCards.erase(it); // Remove the card from the current player's collection
            points -= 2; // Remove 2 points for each card
            cardFound = true;
        }
        else
        {
            ++it; // Move to the next card
        }
    }
}


// Add card to player's hand
void Player::addCard(Card *card)
{
    playerCards.push_back(card);
}

void Player::playCard(Board &board, Card &card,vector<Player *> &players)
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
        checkLargestRoad(players, board);
    }
    else if (cardType == "Year Of Plenty")
    {
        // Print available resources with indices
        vector<string> availableResources = {"Brick", "Lumber", "Wool", "Grain", "Ore"};
        cout << "Available resources:" << endl;
        for (int i = 0; i < availableResources.size(); ++i)
        {
            cout << i + 1 << ". " << availableResources[i] << " ";
        }
        cout << endl;

        string toADD;
        string toADD2;

        int choice,choice2;
        cout << "Choose a resource by entering its index: ";
        cin >> choice;
        cout << "\nChoose second resource by entering its index: ";
        cin >> choice2;

        // Validate input to ensure it's within valid range
        while (choice < 1 || choice > resources.size() || choice2 < 1 || choice2 > resources.size())
        {
            cout << "Invalid choice. Please enter a valid index: ";
            cin.clear();                                         // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            cin >> choice;
            cin >> choice2;
            // Example implementation for Year Of Plenty card
            // player gets 2 resources of their choice from the bank
        }
        toADD = availableResources[choice-1];
        toADD2 = availableResources[choice2-1];

            this->addResource(toADD, 1);
            this->addResource(toADD2, 1);
        
    }
    // player chooses a resource, all other players must give all their resources of that type to this player
    else if (cardType == "Monopoly")
{
    // Print available resources with indices
    vector<string> availableResources = {"Brick", "Lumber", "Wool", "Grain", "Ore"};
    cout << "Available resources:" << endl;
    for (int i = 0; i < availableResources.size(); ++i)
    {
        cout << i + 1 << ". " << availableResources[i] << " ";
    }
    cout << endl;

    int choice;
    cout << "Choose a resource by entering its index: ";
    cin >> choice;

    // Validate input to ensure it's within valid range
    while (choice < 1 || choice > availableResources.size())
    {
        cout << "Invalid choice. Please enter a valid index: ";
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cin >> choice;
    }

    string chosenResource = availableResources[choice - 1];

    int totalCollected = 0;

    // Collect resources from other players
    for (size_t i = 0; i < players.size(); ++i) 
    {
        // Skip the current player
        if (players[i] == this) 
            continue;
        map<string, int> &resources = players[i]->getResources();
      //  If it is not equal, it means the chosen resource was found in the map.
        if (resources.find(chosenResource) != resources.end())
        {
            totalCollected += resources[chosenResource];
            resources.erase(chosenResource); // Remove all resources of this type from the player
        }
    }

    // Add collected resources to the current player
    this->addResource(chosenResource, totalCollected);

    cout << "Collected " << totalCollected << " " << chosenResource << " from other players." << endl;
    cout << "Current player now has " << this->getResources()[chosenResource] << " " << chosenResource << "." << endl;
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


    map<string, int>& Player::getResources(){
        return resources;
    }


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
            std::cout << i + 1 << ". " << playerCards[i]->getType();
            if (i != playerCards.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void Player::checkLargestRoad(vector<Player*> &players, Board &board) {
    Player *currentHolder = nullptr;
    

    // Find the player with the longest road
    for (Player *player : players) {
        vector<int> roads = player->getRoads();
        int roadLength = board.pathOfRoads(player->getPlayerNumber(), *player); // Assuming a method to calculate the longest road
        cout << "Player " << player->getPlayerNumber() << " path is " << roadLength << " longest road: " << longestRoad << endl;

        // Check if the current player already holds the "Special: Largest Road" card
        bool alreadyHasCard = player->hasSpecialCard("Special: Largest Road");


         // Case 1: Find the player with the current longest road who doesn't already have the card
        if (roadLength > longestRoad && !alreadyHasCard) {
            longestRoad = roadLength;
            currentHolder = player;
        }
        // Case 2: First player to achieve a path of 5 roads and the card is not occupied
        if (roadLength >= 5 && !occupiedLargestRoad) {
            cout << player->getName() << " achieves the longest road for the first time." << endl;
            vector<Card *> specialCards = Catan::getMainSpecialCards();
            player->addSpecialCard(specialCards[0]); // Assuming specialCards[0] is "Special: Largest Road"
            player->add2point(); // Award 2 victory points
            occupiedLargestRoad = true;
            longestRoad = roadLength;
            //currentHolder = player;
            cout << player->getName() << " has earned the Largest Road card and 2 victory points!" << endl;
            return;
        }

       
    }

    // Case 3: Transfer the card if a new player has a longer road than the current holder
    for (Player *playerWithTheCard : players) {
        bool alreadyHasCard = playerWithTheCard->hasSpecialCard("Special: Longest Road");
        //if someone has this card, player is not the same as current
        if (alreadyHasCard && playerWithTheCard != currentHolder && currentHolder) {
            cout << "Transferring the Largest Road card from " << playerWithTheCard->getName() << " to " << currentHolder->getName() << endl;
            playerWithTheCard->transferSpecialCard(*currentHolder, "Special: Longest Road");
            currentHolder->add2point();
            //playerWithTheCard->points -= 2;
        }
    }
}

// // Transfer a specific type of special card to another player
// void Player::transferSpecialCard(Player &playerToAdd, const string &type) {
//     auto it = std::find_if(specialCards.begin(), specialCards.end(), [&](Card *card) {
//         return card->getType() == type;
//     });

//     if (it != specialCards.end()) {
//         // Transfer the card to the other player
//         playerToAdd.addSpecialCard(*it);
//         specialCards.erase(it); // Remove the card from current player's collection
//         points -= 2; // Remove 2 points from the current player
//     }
// }






void Player::tradeResources(Board &board, vector<Player *> &players, int playerIndex, string resource1, int amount, string resource2, int amount2)
{
    // Check if the player who play the turn has the resources to trade
    auto it1 = resources.find(resource1); // Find resource1 (e.g., "Brick") in the current player's resources
    auto it2 = resources.find(resource2); // Find resource2 (e.g., "Grain") in the current player's resources

    if (it1 != resources.end() && it2 != resources.end() && it1->second >= amount && it2->second >= amount2)
    {
        // Check if the other player has the resources to trade
        auto otherPlayerResources = players[playerIndex]->resources; // Get the resources of the other player
        auto it3 = otherPlayerResources.find(resource1); // Find resource1 (e.g., "Brick") in the other player's resources
        auto it4 = otherPlayerResources.find(resource2); // Find resource2 (e.g., "Grain") in the other player's resources

        if (it3 != otherPlayerResources.end() && it4 != otherPlayerResources.end() && it3->second >= amount && it4->second >= amount2)
        {
            // Trade the resources
            it1->second -= amount; // Decrease resource1 (e.g., "Brick") by amount in the current player's resources
            it2->second += amount2; // Increase resource2 (e.g., "Grain") by amount2 in the current player's resources
            it3->second -= amount; // Decrease resource1 (e.g., "Brick") by amount in the other player's resources
            it4->second += amount2; // Increase resource2 (e.g., "Grain") by amount2 in the other player's resources

            cout << "Player " << this->getName() << " traded " << amount << " " << resource1 << " with player " << players[playerIndex]->getName() << " for " << amount2 << " " << resource2 << endl;

            // Print the resources that the player has after trading
            cout << "Player " << this->getName() << " now has resources: ";
            for (auto& res : resources) {
                cout << res.first << ": " << res.second << ", "; // Print each resource type and amount in the current player's resources
            }
            cout << endl;

            // Print the resources that the other player has after trading
            cout << "Player " << players[playerIndex]->getName() << " now has resources: ";
            for (auto& res : players[playerIndex]->resources) {
                cout << res.first << ": " << res.second << ", "; // Print each resource type and amount in the other player's resources
            }
            cout << endl;

            return; // Exit the function after successful trading
        }
    }

    // Print that the trade was not successful
    cout << "Player " << this->getName() << " cannot trade " << amount << " " << resource1 << " with player " << players[playerIndex]->getName() << " for " << amount2 << " " << resource2 << endl;
}

// Method to calculate total number of resource cards
    int Player::totalResourceCards() const {
        int total = 0;
        for (const auto& pair : resources) {
            total += pair.second; // Add the count of each resource type
        }
        return total;
    }

 // Method to discard specific amount of resource cards
    void Player::discardCards(const string& resource, int amount) {
        auto it = resources.find(resource);
        if (it != resources.end()) {
            if (it->second >= amount) {
                it->second -= amount;
                std::cout << "Discarded " << amount << " " << resource << " cards." << std::endl;
            } else {
                std::cout << "Not enough " << resource << " cards to discard." << std::endl;
            }
        } else {
            cout << "You do not have " << resource << " cards to discard." << std::endl;
        }
    }

    // Method to discard half of the resource cards
    void Player::discardHalfCards() {
        int totalCards = totalResourceCards();
        if (totalCards <= 7) {
            std::cout << "You have 7 or fewer resource cards. No need to discard." << std::endl;
            return;
        }

        int cardsToDiscard = totalCards / 2;
        std::cout << "You have more than 7 resource cards (" << totalCards << "). You must discard " << cardsToDiscard << " cards." << std::endl;

        while (cardsToDiscard > 0) {
            std::cout << "Your current resources: ";
            displayResources(); // Implement this method to display current resources

            std::string resource;
            int amount;
            std::cout << "Enter resource and amount to discard (e.g., 'Wood 2'): ";
            std::cin >> resource >> amount;

            discardCards(resource, amount);
            cardsToDiscard -= amount;
        }

        std::cout << "Discard phase completed." << std::endl;
    }