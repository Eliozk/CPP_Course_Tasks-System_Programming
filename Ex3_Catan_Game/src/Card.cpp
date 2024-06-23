#include "Card.hpp"
#include "Player.hpp"

using namespace std;
using namespace ariel;

// Card copy constructor
Card::Card(const Card &other) : name(other.name) {}

// Card assignment operator
Card &Card::operator=(const Card &other)
{
    if (this != &other)
    {
        name = other.name;
    }
    return *this;
}

// Implementation for DevelopmentCard
DevelopmentCard::DevelopmentCard(const string &type) : type(type) {}

string DevelopmentCard::getType() const
{
    return type;
}
Card *DevelopmentCard::clone() const
{
    return new DevelopmentCard(*this);
}

DevelopmentCard::DevelopmentCard(const DevelopmentCard &other) : Card(other), type(other.type) {}

DevelopmentCard &DevelopmentCard::operator=(const DevelopmentCard &other)
{
    if (this != &other)
    {
        Card::operator=(other);
        type = other.type;
    }
    return *this;
}
// Implementation for ResourceCard
ResourceCard::ResourceCard(const string &resource) : resource(resource) {}

string ResourceCard::getType() const
{
    return resource;
}

Card* ResourceCard::clone() const {
    return new ResourceCard(*this);
}

ResourceCard::ResourceCard(const ResourceCard& other) : Card(other), resource(other.resource) {}

ResourceCard& ResourceCard::operator=(const ResourceCard& other) {
    if (this != &other) {
        Card::operator=(other);
        resource = other.resource;
    }
    return *this;
}

// Implementation for VictoryPointCard
VictoryPointCard::VictoryPointCard(const string &name, int points) : name(name), points(points) {}

std::string VictoryPointCard::getType() const
{
    return name;
}

int VictoryPointCard::getPoints() const
{
    return points;
}
Card* VictoryPointCard::clone() const {
    return new VictoryPointCard(*this);
}

VictoryPointCard::VictoryPointCard(const VictoryPointCard& other) : Card(other), points(other.points), name(other.name) {}

VictoryPointCard& VictoryPointCard::operator=(const VictoryPointCard& other) {
    if (this != &other) {
        Card::operator=(other);
        points = other.points;
        name = other.name;
    }
    return *this;
}

// Implementation for ProgressCard
ProgressCard::ProgressCard(const string &action) : action(action) {}

string ProgressCard::getType() const
{
    return action;
}

string ProgressCard::getAction() const
{
    return action;
}
Card* ProgressCard::clone() const {
    return new ProgressCard(*this);
}

ProgressCard::ProgressCard(const ProgressCard& other) : Card(other), action(other.action) {}

ProgressCard& ProgressCard::operator=(const ProgressCard& other) {
    if (this != &other) {
        Card::operator=(other);
        action = other.action;
    }
    return *this;
}

// Implementation for KnightCard
KnightCard::KnightCard() : ProgressCard("Knight") {}

Card* KnightCard::clone() const {
    return new KnightCard(*this);
}

KnightCard::KnightCard(const KnightCard& other) : ProgressCard(other) {}

KnightCard& KnightCard::operator=(const KnightCard& other) {
    if (this != &other) {
        ProgressCard::operator=(other);
    }
    return *this;
}

// Implementation for RoadBuildingCard
RoadBuildingCard::RoadBuildingCard() : ProgressCard("Road Building") {}

Card* RoadBuildingCard::clone() const {
    return new RoadBuildingCard(*this);
}

RoadBuildingCard::RoadBuildingCard(const RoadBuildingCard& other) : ProgressCard(other) {}

RoadBuildingCard& RoadBuildingCard::operator=(const RoadBuildingCard& other) {
    if (this != &other) {
        ProgressCard::operator=(other);
    }
    return *this;
}
// Implementation for YearOfPlentyCard
YearOfPlentyCard::YearOfPlentyCard() : ProgressCard("Year Of Plenty") {}

Card* YearOfPlentyCard::clone() const {
    return new YearOfPlentyCard(*this);
}

YearOfPlentyCard::YearOfPlentyCard(const YearOfPlentyCard& other) : ProgressCard(other) {}

YearOfPlentyCard& YearOfPlentyCard::operator=(const YearOfPlentyCard& other) {
    if (this != &other) {
        ProgressCard::operator=(other);
    }
    return *this;
}
// Implementation for MonopolyCard
MonopolyCard::MonopolyCard() : ProgressCard("Monopoly") {}

Card* MonopolyCard::clone() const {
    return new MonopolyCard(*this);
}

MonopolyCard::MonopolyCard(const MonopolyCard& other) : ProgressCard(other) {}

MonopolyCard& MonopolyCard::operator=(const MonopolyCard& other) {
    if (this != &other) {
        ProgressCard::operator=(other);
    }
    return *this;
}

   // LongestRoadCard implementation
    LongestRoadCard::LongestRoadCard() : name("Longest Road") {}

    string LongestRoadCard::getType() const
    {
        return "Special: Longest Road";
    }

    Card *LongestRoadCard::clone() const
    {
        return new LongestRoadCard(*this);
    }

    LongestRoadCard::LongestRoadCard(const LongestRoadCard &other) : Card(other) {}

    LongestRoadCard &LongestRoadCard::operator=(const LongestRoadCard &other)
    {
        if (this != &other)
        {
            Card::operator=(other);
        }
        return *this;
    }

    // LargestArmyCard implementation
    LargestArmyCard::LargestArmyCard() : name("Largest Army") {}

    string LargestArmyCard::getType() const
    {
        return "Special: Largest Army";
    }

    Card *LargestArmyCard::clone() const
    {
        return new LargestArmyCard(*this);
    }

    LargestArmyCard::LargestArmyCard(const LargestArmyCard &other) : Card(other) {}

    LargestArmyCard &LargestArmyCard::operator=(const LargestArmyCard &other)
    {
        if (this != &other)
        {
            Card::operator=(other);
        }
        return *this;
    };


