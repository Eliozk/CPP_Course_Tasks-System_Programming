#ifndef CATAN_HPP
#define CATAN_HPP

#include "Player.hpp"

#include "Tile.hpp"
#include "Settlement.hpp"
#include "Card.hpp"
using namespace std;
namespace ariel
{
    class Card;
    class Board;
    class Catan
    {
    private:
        Player &player1;
        Player &player2;
        Player &player3;
        Board &board;
        vector<Player *> players;
        vector<Card *> cards;
        static vector<Card *> specialCards;
       // void distributeResources(vector<Player *> &players, const Vertex& vertex, const Tile& tile, int settlementLevel);
    public:
        Catan(Player &p1, Player &p2, Player &p3,Board &board);
        void initializePlayers();
        vector<Card *> createAndShuffleCards(); // responsible for all kind of cards including the specials.
        static vector<Card*> getMainSpecialCards();
        void placeInitialSettlementsAndRoads(Board &catanbBoard);
        void cleanup();
        void ChooseStartingPlayer() const;

        Board &getBoard();

        void deleteMemory();
    };
}
#endif // CATAN_HPP
