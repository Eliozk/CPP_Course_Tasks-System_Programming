#ifndef CATAN_HPP
#define CATAN_HPP

#include "Player.hpp"
#include "Board.hpp"
#include "Tile.hpp"
#include "Settlement.hpp"
using namespace std;
namespace ariel
{
    class Catan
    {
    private:
        Player &player1;
        Player &player2;
        Player &player3;
        Board board;
        vector<Player *> players;
        vector<Card *> cards;
        vector<Card *> specialCards;

    public:
        Catan(Player &p1, Player &p2, Player &p3);
        // Catan();
        void initializePlayers();
        vector<Card *> createAndShuffleCards(); // responsible for all kind of cards including the specials.
        //
        void placeInitialSettlementsAndRoads(Board &catanbBoard);
        void distributeInitialResources();
        void distribution(vector<Player *> &players, int diceRoll);

        void ChooseStartingPlayer() const;

        Board &getBoard();

        void printWinner() const;
    };
}
#endif // CATAN_HPP
