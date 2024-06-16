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
        Player &p1;
        Player &p2;
        Player &p3;
        Board board;

    public:
        Catan(Player &p1, Player &p2, Player &p3) : p1(p1), p2(p2), p3(p3) {}

        void ChooseStartingPlayer() const;

        Board &getBoard()
        {
            return board;
        }

        void printWinner() const
        {
            cout << "None" << endl; // Placeholder for determining the winner
        }
    };
}
#endif // CATAN_HPP
