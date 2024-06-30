#include "Card.hpp"
#include "Player.hpp"
#include <iostream>

namespace ariel {

// Card copy constructor implementation
Card::Card(const Card& other) {
    // Since Card is abstract, there is no strategy to copy, subclasses handle copying
}

// Assignment operator
Card& Card::operator=(const Card& other) {
    if (this != &other) {
        // Since Card is abstract, there is no strategy to assign, subclasses handle copying
    }
    return *this;
}

// DevelopmentCard constructor implementation
DevelopmentCard::DevelopmentCard(const std::string &type) : type(type) {}

// DevelopmentCard copy constructor
DevelopmentCard::DevelopmentCard(const DevelopmentCard& other) : Card(other), type(other.type) {}

// DevelopmentCard assignment operator
DevelopmentCard& DevelopmentCard::operator=(const DevelopmentCard& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

// DevelopmentCard play implementation
void DevelopmentCard::play(Player& player) const {
    std::cout << "Playing Development Card: " << type << std::endl;
}

// DevelopmentCard getType implementation
std::string DevelopmentCard::getType() const {
    return type;
}

// DevelopmentCard clone implementation
Card* DevelopmentCard::clone() const {
    return new DevelopmentCard(*this);
}

// ResourceCard constructor implementation
ResourceCard::ResourceCard(const std::string &resource) : resource(resource) {}

// ResourceCard copy constructor
ResourceCard::ResourceCard(const ResourceCard& other) : Card(other), resource(other.resource) {}

// ResourceCard assignment operator
ResourceCard& ResourceCard::operator=(const ResourceCard& other) {
    if (this != &other) {
        resource = other.resource;
    }
    return *this;
}

// ResourceCard play implementation
void ResourceCard::play(Player& player) const {
    std::cout << "Playing Resource Card: " << resource << std::endl;
}

// ResourceCard getType implementation
std::string ResourceCard::getType() const {
    return resource;
}

// ResourceCard clone implementation
Card* ResourceCard::clone() const {
    return new ResourceCard(*this);
}

// VictoryPointCard constructor implementation
VictoryPointCard::VictoryPointCard(const std::string &name, int points) : name(name), points(points) {}

// VictoryPointCard copy constructor
VictoryPointCard::VictoryPointCard(const VictoryPointCard& other) : Card(other), name(other.name), points(other.points) {}

// VictoryPointCard assignment operator
VictoryPointCard& VictoryPointCard::operator=(const VictoryPointCard& other) {
    if (this != &other) {
        name = other.name;
        points = other.points;
    }
    return *this;
}

// VictoryPointCard play implementation
void VictoryPointCard::play(Player& player) const {
    std::cout << "Playing Victory Point Card: " << name << " with " << points << " points" << std::endl;
}

// VictoryPointCard getType implementation
std::string VictoryPointCard::getType() const {
    return name;
}

// VictoryPointCard clone implementation
Card* VictoryPointCard::clone() const {
    return new VictoryPointCard(*this);
}

// LongestRoadCard constructor
LongestRoadCard::LongestRoadCard() {}

// LongestRoadCard copy constructor
LongestRoadCard::LongestRoadCard(const LongestRoadCard& other) : Card(other) {}

// LongestRoadCard assignment operator
LongestRoadCard& LongestRoadCard::operator=(const LongestRoadCard& other) {
    if (this != &other) {
        // No specific members to assign
    }
    return *this;
}

// LongestRoadCard play implementation
void LongestRoadCard::play(Player& player) const {
    std::cout << "Playing Longest Road Card" << std::endl;
}

// LongestRoadCard getType implementation
std::string LongestRoadCard::getType() const {
    return "Special: Longest Road";
}

// LongestRoadCard clone implementation
Card* LongestRoadCard::clone() const {
    return new LongestRoadCard(*this);
}

// LargestArmyCard constructor
LargestArmyCard::LargestArmyCard() {}

// LargestArmyCard copy constructor
LargestArmyCard::LargestArmyCard(const LargestArmyCard& other) : Card(other) {}

// LargestArmyCard assignment operator
LargestArmyCard& LargestArmyCard::operator=(const LargestArmyCard& other) {
    if (this != &other) {
        // No specific members to assign
    }
    return *this;
}

// LargestArmyCard play implementation
void LargestArmyCard::play(Player& player) const {
    std::cout << "Playing Largest Army Card" << std::endl;
}

// LargestArmyCard getType implementation
std::string LargestArmyCard::getType() const {
    return "Special: Largest Army";
}

// LargestArmyCard clone implementation
Card* LargestArmyCard::clone() const {
    return new LargestArmyCard(*this);
}

} // namespace ariel
