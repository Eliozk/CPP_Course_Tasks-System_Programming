#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace ariel
{

    // Base Card class
    class Card
    {

    private:
        string name;

    public:
        virtual ~Card() = default;
        virtual string getType() const = 0; // Pure virtual function to get the card type
                                            // Virtual copy constructor
        virtual Card *clone() const = 0;

        // Copy constructor
        Card(const Card &other);

        // Assignment operator
        Card &operator=(const Card &other);

    protected:
        // Default constructor protected to prevent direct instantiation
        Card() = default;
    };

    // Derived DevelopmentCard class
    class DevelopmentCard : public Card
    {
    private:
        string type;

    public:
        DevelopmentCard(const string &type);
        string getType() const override;
        // Virtual copy constructor
        Card *clone() const override;

        // Copy constructor
        DevelopmentCard(const DevelopmentCard &other);

        // Assignment operator
        DevelopmentCard &operator=(const DevelopmentCard &other);
    };

    // Derived ResourceCard class
    class ResourceCard : public Card
    {
    private:
        string resource;

    public:
        ResourceCard(const string &resource);
        string getType() const override;
        // Virtual copy constructor
        Card *clone() const override;

        // Copy constructor
        ResourceCard(const ResourceCard &other);

        // Assignment operator
        ResourceCard &operator=(const ResourceCard &other);
    };

    // Derived VictoryPointCard class
    class VictoryPointCard : public Card
    {
    private:
        int points;
        string name;

    public:
        VictoryPointCard(const string &name, int points);
        string getType() const override;
        int getPoints() const;
        // Virtual copy constructor
        Card *clone() const override;

        // Copy constructor
        VictoryPointCard(const VictoryPointCard &other);

        // Assignment operator
        VictoryPointCard &operator=(const VictoryPointCard &other);
    };

    // Derived ProgressCard class//קלפי קידום
    class ProgressCard : public Card
    {
    private:
        string action;

    public:
        ProgressCard(const string &action);
        string getType() const override;
        string getAction() const;
        // Virtual copy constructor
        Card *clone() const override;

        // Copy constructor
        ProgressCard(const ProgressCard &other);

        // Assignment operator
        ProgressCard &operator=(const ProgressCard &other);
    };

    // Derived KnightCard class
    class KnightCard : public ProgressCard
    {
    public:
        KnightCard();
        // Virtual copy constructor
        Card *clone() const override;

        // Copy constructor
        KnightCard(const KnightCard &other);

        // Assignment operator
        KnightCard &operator=(const KnightCard &other);
    };

    // Derived RoadBuildingCard class
    class RoadBuildingCard : public ProgressCard
    {
    public:
        RoadBuildingCard();
        // Virtual copy constructor
        Card *clone() const override;

        // Copy constructor
        RoadBuildingCard(const RoadBuildingCard &other);

        // Assignment operator
        RoadBuildingCard &operator=(const RoadBuildingCard &other);
    };

    // Derived YearOfPlentyCard class
    class YearOfPlentyCard : public ProgressCard
    {
    public:
        YearOfPlentyCard();

        // Virtual copy constructor
        Card *clone() const override;

        // Copy constructor
        YearOfPlentyCard(const YearOfPlentyCard &other);

        // Assignment operator
        YearOfPlentyCard &operator=(const YearOfPlentyCard &other);
    };

    // Derived MonopolyCard class
    class MonopolyCard : public ProgressCard
    {
    public:
        MonopolyCard();
        // Virtual copy constructor
        Card *clone() const override;

        // Copy constructor
        MonopolyCard(const MonopolyCard &other);

        // Assignment operator
        MonopolyCard &operator=(const MonopolyCard &other);
    };

    // Derived LongestRoadCard class
    class LongestRoadCard : public Card
    {
    private:
        string name;

    public:
        LongestRoadCard();
        string getType() const override;
        // Virtual copy constructor
        Card *clone() const override;

        // Copy constructor
        LongestRoadCard(const LongestRoadCard &other);

        // Assignment operator
        LongestRoadCard &operator=(const LongestRoadCard &other);
    };

    // Derived LargestArmyCard class
    class LargestArmyCard : public Card
    {
    private:
        string name;

    public:
        LargestArmyCard();
        string getType() const override;
        // Virtual copy constructor
        Card *clone() const override;

        // Copy constructor
        LargestArmyCard(const LargestArmyCard &other);

        // Assignment operator
        LargestArmyCard &operator=(const LargestArmyCard &other);
    };
} // namespace ariel

#endif // CARD_HPP
