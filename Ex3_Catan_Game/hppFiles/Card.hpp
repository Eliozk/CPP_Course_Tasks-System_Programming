#ifndef CARD_HPP
#define CARD_HPP

#include <string>

namespace ariel {

    // Base Card class
    class Card {
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

} // namespace ariel

#endif // CARD_HPP
