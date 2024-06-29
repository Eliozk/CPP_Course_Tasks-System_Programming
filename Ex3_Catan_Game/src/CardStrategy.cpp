#include "CardStrategy.hpp"
#include <iostream>
#include "Player.hpp"
using namespace std;

namespace ariel
{

    void DevelopmentCardStrategy::execute(Player &player, const Card &card)
    {
        cout << "Executing DevelopmentCardStrategy for player: " << player.getName() << " with card: " << card.getType() << std::endl;

        string cardType = card.getType();

        if (cardType == "Victory Point")
        {
            // Example implementation for Victory Point card
            player.add1point();
        }
        else if (cardType == "Road Building")
        {
            // Example implementation for Road Building card
            // player can build 2 roads for free
            // player.buildRoad();
            // player.buildRoad();
        }
        else if (cardType == "Year Of Plenty")
        {
            // Example implementation for Year Of Plenty card
            // player gets 2 resources of their choice from the bank
            player.addResource("choice1", 1);
            player.addResource("choice2", 1);
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
    }

    CardStrategy *DevelopmentCardStrategy::clone() const
    {
        return new DevelopmentCardStrategy(*this);
    }

    void ResourceCardStrategy::execute(Player &player, const Card &card)
    {
        // Implementation for ResourceCardStrategy::execute
    }

    CardStrategy *ResourceCardStrategy::clone() const
    {
        return new ResourceCardStrategy(*this);
    }

    void VictoryPointCardStrategy::execute(Player &player, const Card &card)
    {
        // Implementation for VictoryPointCardStrategy::execute
    }

    CardStrategy *VictoryPointCardStrategy::clone() const
    {
        return new VictoryPointCardStrategy(*this);
    }

    void LongestRoadCardStrategy::execute(Player &player, const Card &card)
    {
        // Implementation for LongestRoadCardStrategy::execute
        std::cout << "Executing LongestRoadCardStrategy for player: " << player.getName() << std::endl;
        // Perform specific actions for this strategy using 'card'
    }

    CardStrategy *LongestRoadCardStrategy::clone() const
    {
        return new LongestRoadCardStrategy(*this);
    }

    void LargestArmyCardStrategy::execute(Player &player, const Card &card)
    {
        // Implementation for LargestArmyCardStrategy::execute
    }

    CardStrategy *LargestArmyCardStrategy::clone() const
    {
        return new LargestArmyCardStrategy(*this);
    }

} // namespace ariel
