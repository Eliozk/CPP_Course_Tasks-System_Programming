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
        static vector<Card *> specialCards;
       // void distributeResources(vector<Player *> &players, const Vertex& vertex, const Tile& tile, int settlementLevel);
    public:
        Catan(Player &p1, Player &p2, Player &p3,Board &board);
        // Catan();
        void initializePlayers();
        vector<Card *> createAndShuffleCards(); // responsible for all kind of cards including the specials.
        static vector<Card*> getMainSpecialCards();
        void placeInitialSettlementsAndRoads(Board &catanbBoard);
        //void distributeInitialResources();
        //void distribution(vector<Player *> &players, int diceRoll);

        void ChooseStartingPlayer() const;

        Board &getBoard();

        void printWinner() const;
        void deleteMemory();
    };
}
#endif // CATAN_HPP
