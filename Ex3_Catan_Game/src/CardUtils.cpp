#include "CardUtils.hpp" // Include the header file for card utilities
#include <algorithm>     // for std::shuffle
#include <random>        // for std::default_random_engine

using namespace ariel;
using namespace std;



        vector<Card*> CardUtils::createAndShuffleCards() {
        /**
         * 14 קלפי אביר
         * 5 קלפי ניצחון
         * 2 בניית דרך
         * 2 year of plenty take 2 resources from bank
         * 2מונופול נשמר אצלינו וכשתמשתים כל השחקנים מעבירים לנו את כל המשאב שנבחר שקיים אצלם
         */
        vector<Card*> allCards;

        // Add Victory Point Cards קלפי ניצחון 5
        allCards.push_back(new VictoryPointCard("Governor's House", 1));
        allCards.push_back(new VictoryPointCard("Library", 1));
        allCards.push_back(new VictoryPointCard("Market", 1));
        allCards.push_back(new VictoryPointCard("Chapel", 1));
        allCards.push_back(new VictoryPointCard("Universuty of Catan", 1));

        // Add Development Cards 6 קלפי התפתחות
        for(int i = 0 ; i < 2 ; i++){
        allCards.push_back(new ProgressCard("Road Building"));
        allCards.push_back(new ProgressCard("Year of Plenty"));
        allCards.push_back(new ProgressCard("Monopoly"));
        }
        //2 special cards 2
        allCards.push_back(new ProgressCard("Largest Army"));
        allCards.push_back(new ProgressCard("Longest Road"));

        // Add 14 Knight Cards 14 קלפי אביר
        for(int i = 0 ; i < 14 ; i++){
            allCards.push_back(new KnightCard());
        }      

        // Shuffle the vector
        random_device random;
        mt19937 g(random());
        shuffle(allCards.begin(), allCards.end(), g);

        return allCards;
    }
