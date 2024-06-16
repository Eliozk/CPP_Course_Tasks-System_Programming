#include "Card.hpp"
#include "Player.hpp"

using namespace std;
using namespace ariel;

    // Implementation for DevelopmentCard
    DevelopmentCard::DevelopmentCard(const string& type) : type(type) {}

    string DevelopmentCard::getType() const {
        return type;
    }

    // Implementation for ResourceCard
    ResourceCard::ResourceCard(const string& resource) : resource(resource) {}

    string ResourceCard::getType() const {
        return resource;
    }

// Implementation for VictoryPointCard
VictoryPointCard::VictoryPointCard(const std::string& name, int points) : points(points), name(name) {}

std::string VictoryPointCard::getType() const {
    return name;
}

int VictoryPointCard::getPoints() const {
    return points;
}

// Implementation for ProgressCard
ProgressCard::ProgressCard(const string& action) : action(action) {}

string ProgressCard::getType() const {
    return action;
}

string ProgressCard::getAction() const {
    return action;
}

    // Implementation for KnightCard
    KnightCard::KnightCard() : ProgressCard("Knight") {}

    // Implementation for RoadBuildingCard
    RoadBuildingCard::RoadBuildingCard() : ProgressCard("RoadBuilding") {}

    // Implementation for YearOfPlentyCard
    YearOfPlentyCard::YearOfPlentyCard() : ProgressCard("YearOfPlenty") {}

    // Implementation for MonopolyCard
    MonopolyCard::MonopolyCard() : ProgressCard("Monopoly") {}

