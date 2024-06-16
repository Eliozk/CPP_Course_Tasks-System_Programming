#include "Tile.hpp"

using namespace ariel;

// Implementation for Tile
Tile::Tile(int number, const string& name) : number(number), name(name) {}


int ariel::Tile::getNumber() const {
    return number;
}

string Tile::getName() const {
    return name;
}



// Implementation for Forest
Forest::Forest(int number) : Tile(number, "Forest") {}

string ariel::Forest::getResource() const {
    return "Wood";
}

// Implementation for Hill
Hill::Hill(int number) : Tile(number, "Hill") {}

string ariel::Hill::getResource() const {
    return "Brick";
}

// Implementation for Pasture
Pasture::Pasture(int number) : Tile(number, "Pasture") {}

string Pasture::getResource() const {
    return "Sheep";
}

// Implementation for Field
Field::Field(int number) : Tile(number, "Field") {}

string Field::getResource() const {
    return "Wheat";
}

// Implementation for Mountain
Mountain::Mountain(int number) : Tile(number, "Mountain") {}

string Mountain::getResource() const {
    return "Ore";
}

// Implementation for Desert
Desert::Desert(int number) : Tile(number, "Desert") {}

string Desert::getResource() const
        {
            return ""; // Desert tiles don't yield resources, so return an empty string
        }
