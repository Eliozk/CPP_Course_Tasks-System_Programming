#ifndef CARDSTRATEGY_HPP
#define CARDSTRATEGY_HPP

namespace ariel {

class Player; // Forward declaration
class Card; // Forward declaration

class CardStrategy {
public:

    virtual ~CardStrategy() {};;
    virtual void execute(Player& player, const Card& card) = 0;
    virtual CardStrategy* clone() const = 0; // Clone function for polymorphic copying
};

class DevelopmentCardStrategy : public CardStrategy {
public:
    void execute(Player& player, const Card& card) override;
    CardStrategy* clone() const override;
};

class ResourceCardStrategy : public CardStrategy {
public:
    void execute(Player& player, const Card& card) override;
    CardStrategy* clone() const override;
};

class VictoryPointCardStrategy : public CardStrategy {
public:
    void execute(Player& player, const Card& card) override;
    CardStrategy* clone() const override;
};

class LongestRoadCardStrategy : public CardStrategy {
public:

    void execute(Player& player, const Card& card) override;
    CardStrategy* clone() const override;
};

class LargestArmyCardStrategy : public CardStrategy {
public:
    void execute(Player& player, const Card& card) override;
    CardStrategy* clone() const override;
};

} // namespace ariel

#endif // CARDSTRATEGY_HPP
