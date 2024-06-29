#include "Card.hpp"
#include "CardStrategy.hpp"
#include "Player.hpp"

namespace ariel {

// Card constructor implementation
Card::Card(std::unique_ptr<CardStrategy> strategy) : strategy(std::move(strategy)) {}

// Card copy constructor implementation
Card::Card(const Card& other) : strategy(other.strategy->clone()) {}

// Assignment operator
Card& Card::operator=(const Card& other) {
    if (this != &other) {
        strategy = std::unique_ptr<CardStrategy>(other.strategy->clone());
    }
    return *this;
}

// Play function implementation
void Card::play(Player& player) const {
    strategy->execute(player, *this);
}

// DevelopmentCard constructor implementation
DevelopmentCard::DevelopmentCard(const std::string &type) : Card(std::make_unique<DevelopmentCardStrategy>()), type(type) {}

// DevelopmentCard getType implementation
std::string DevelopmentCard::getType() const {
    return type;
}

// DevelopmentCard clone implementation
Card* DevelopmentCard::clone() const {
    return new DevelopmentCard(*this);
}

// ResourceCard constructor implementation
ResourceCard::ResourceCard(const std::string &resource) : Card(std::make_unique<ResourceCardStrategy>()), resource(resource) {}

// ResourceCard getType implementation
std::string ResourceCard::getType() const {
    return resource;
}

// ResourceCard clone implementation
Card* ResourceCard::clone() const {
    return new ResourceCard(*this);
}

// VictoryPointCard constructor implementation
VictoryPointCard::VictoryPointCard(const std::string &name, int points) : Card(std::make_unique<VictoryPointCardStrategy>()), name(name), points(points) {}

// VictoryPointCard getType implementation
std::string VictoryPointCard::getType() const {
    return name;
}

// VictoryPointCard clone implementation
Card* VictoryPointCard::clone() const {
    return new VictoryPointCard(*this);
}

// LongestRoadCard constructor
LongestRoadCard::LongestRoadCard() : Card(nullptr) {}

// LongestRoadCard getType implementation
std::string LongestRoadCard::getType() const {
    return "Special: Longest Road";
}

// LongestRoadCard clone implementation
Card* LongestRoadCard::clone() const {
    return new LongestRoadCard(*this);
}

// LargestArmyCard constructor
LargestArmyCard::LargestArmyCard() : Card(nullptr) {}

// LargestArmyCard getType implementation
std::string LargestArmyCard::getType() const {
    return "Special: Largest Army";
}

// LargestArmyCard clone implementation
Card* LargestArmyCard::clone() const {
    return new LargestArmyCard(*this);
}

} // namespace ariel
