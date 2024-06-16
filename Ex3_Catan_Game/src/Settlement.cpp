#include "Settlement.hpp"
#include <iostream>

using namespace ariel;
using namespace std;


Settlement::Settlement(Player* owner) : owner(owner) {}

void Settlement::construct() {
    // Implementation for constructing a settlement
    cout << "Constructing a settlement for player: " << owner->getName() << endl;
}

void Settlement::upgrade() {
    // Implementation for upgrading a settlement
    std::cout << "Upgrading the settlement to City for player: " << owner->getName() << endl;
}

Player* Settlement::getOwner() const {
    return owner;
}
City::City(Player* owner) : Settlement(owner) {}

void City::construct() {
    // Implementation for constructing a city
    std::cout << "Constructing a city for player: " << owner->getName() << endl;
}

bool Settlement::isAdjacentTo(const Tile& tile) const
{
    // Implementation to check adjacency with the tile
    // This is just a placeholder, you need to implement the logic
    return true; // Or false, based on actual adjacency logic
}

Road::Road(Player* owner) : Road(owner) {}

void Road::construct() {
 // Implementation for constructing a road
    cout << "Constructing a road for player: " << owner->getName() << endl;
}






