#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace ariel {

    // Base Card class
    class Card {

    private:
        string name;
    public:
        virtual ~Card() = default;
        virtual string getType() const = 0; // Pure virtual function to get the card type
    };

    // Derived DevelopmentCard class
    class DevelopmentCard : public Card {
    private:
        string type;
    public:
        DevelopmentCard(const string& type);
        string getType() const override;
    };

    // Derived ResourceCard class
    class ResourceCard : public Card {
    private:
        string resource;
    public:
        ResourceCard(const string& resource);
        string getType() const override;
    };

  // Derived VictoryPointCard class
    class VictoryPointCard : public Card {
    private:
        int points;
        string name;

    public:
        VictoryPointCard(const string& name, int points);
        string getType() const override;
        int getPoints() const;
    };

    // Derived ProgressCard class//קלפי קידום
    class ProgressCard : public Card {
    private:
        string action;

    public:
        ProgressCard(const string& action);
        string getType() const override;
        string getAction() const;
    };

    // Derived KnightCard class
    class KnightCard : public ProgressCard {
    public:
        KnightCard();
    };

    // Derived RoadBuildingCard class
    class RoadBuildingCard : public ProgressCard {
    public:
        RoadBuildingCard();
    };

    // Derived YearOfPlentyCard class
    class YearOfPlentyCard : public ProgressCard {
    public:
        YearOfPlentyCard();
    };

    // Derived MonopolyCard class
    class MonopolyCard : public ProgressCard {
    public:
        MonopolyCard();
    };

} // namespace ariel

#endif // CARD_HPP
