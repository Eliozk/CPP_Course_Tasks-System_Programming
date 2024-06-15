#include "Card.hpp"

using namespace std;
using namespace ariel;


    // Implementation of DevelopmentCard class
    DevelopmentCard::DevelopmentCard(const string& type) : type(type) {}

    string DevelopmentCard::getType() const {
        return "Development: " + type;
    }

    // Implementation of ResourceCard class
    ResourceCard::ResourceCard(const string& resource) : resource(resource) {}

    string ResourceCard::getType() const {
        return "Resource: " + resource;
    }

