#ifndef CARD_HPP
#define CARD_HPP

#include <memory>
#include <string>
#include "CardStrategy.hpp"

namespace ariel {

class Player; // Forward declaration of Player

class Card {
public:
    Card(std::unique_ptr<CardStrategy> strategy);
    Card(const Card& other);
    Card& operator=(const Card& other);
    virtual ~Card() = default;

    virtual void play(Player& player) const;
    virtual Card* clone() const = 0;

    // Add this line:
    virtual std::string getType() const = 0;

protected:
    std::unique_ptr<CardStrategy> strategy;
};

class DevelopmentCard : public Card {
public:
    DevelopmentCard(const std::string& type);
    std::string getType() const override;
    Card* clone() const override;

private:
    std::string type;
};

class ResourceCard : public Card {
public:
    ResourceCard(const std::string& resource);
    std::string getType() const override;
    Card* clone() const override;

private:
    std::string resource;
};

class VictoryPointCard : public Card {
public:
    VictoryPointCard(const std::string& name, int points);
    std::string getType() const override;
    Card* clone() const override;

private:
    std::string name;
    int points;
};

class LongestRoadCard : public Card {
public:
    LongestRoadCard();
    std::string getType() const override;
    Card* clone() const override;
};

class LargestArmyCard : public Card {
public:
    LargestArmyCard();
    std::string getType() const override;
    Card* clone() const override;
};

} // namespace ariel

#endif // CARD_HPP
