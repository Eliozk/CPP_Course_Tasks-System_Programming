#ifndef CARDUTILS_HPP
#define CARDUTILS_HPP

#include "Card.hpp" // Include the necessary card classes header file
#include <vector>   // Include vector for managing cards

namespace ariel
{

    class CardUtils
    {

        // Function declaration to create and shuffle cards
        vector<Card *> createAndShuffleCards();

    }; // namespace ariel
}
#endif // CARDUTILS_HPP
