#ifndef CARD_HPP
#define CARD_HPP

#include <memory>
#include <string>

namespace ariel {

class Player; // Forward declaration

class Card {
public:
    Card() = default;
    Card(const Card& other);
    Card& operator=(const Card& other);
    virtual ~Card() = default;

    virtual void play(Player& player) const = 0;

    virtual std::string getType() const = 0;
    virtual Card* clone() const = 0;
};

class DevelopmentCard : public Card {
private:
    std::string type;
public:
    DevelopmentCard(const std::string& type);
    DevelopmentCard(const DevelopmentCard& other);
    DevelopmentCard& operator=(const DevelopmentCard& other);

    void play(Player& player) const override;
    std::string getType() const override;
    Card* clone() const override;
};

class ResourceCard : public Card {
private:
    std::string resource;
public:
    ResourceCard(const std::string& resource);
    ResourceCard(const ResourceCard& other);
    ResourceCard& operator=(const ResourceCard& other);

    void play(Player& player) const override;
    std::string getType() const override;
    Card* clone() const override;
};

class VictoryPointCard : public Card {
private:
    std::string name;
    int points;
public:
    VictoryPointCard(const std::string& name, int points);
    VictoryPointCard(const VictoryPointCard& other);
    VictoryPointCard& operator=(const VictoryPointCard& other);

    void play(Player& player) const override;
    std::string getType() const override;
    Card* clone() const override;
};

class LongestRoadCard : public Card {
public:
    LongestRoadCard();
    LongestRoadCard(const LongestRoadCard& other);
    LongestRoadCard& operator=(const LongestRoadCard& other);

    void play(Player& player) const override;
    std::string getType() const override;
    Card* clone() const override;
};

class LargestArmyCard : public Card {
public:
    LargestArmyCard();
    LargestArmyCard(const LargestArmyCard& other);
    LargestArmyCard& operator=(const LargestArmyCard& other);

    void play(Player& player) const override;
    std::string getType() const override;
    Card* clone() const override;
};

} // namespace ariel

#endif // CARD_HPP
