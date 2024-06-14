#include "Settlement.hpp"
#include <iostream>

using namespace ariel;
using namespace std;


Settlement::Settlement(Player* owner) : owner(owner) {}

void Settlement::construct() {
    // Implementation for constructing a settlement
    std::cout << "Constructing a settlement for player: " << owner->getName() << std::endl;
}

void Settlement::upgrade() {
    // Implementation for upgrading a settlement
    std::cout << "Upgrading the settlement for player: " << owner->getName() << std::endl;
}

City::City(Player* owner) : Settlement(owner) {}

void City::construct() {
    // Implementation for constructing a city
    std::cout << "Constructing a city for player: " << owner->getName() << std::endl;
}

void City::upgrade() {
    // Implementation for upgrading a city
    std::cout << "Upgrading the city for player: " << owner->getName() << std::endl;
}
