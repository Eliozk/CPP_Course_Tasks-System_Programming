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
        Catan(Player &p1, Player &p2, Player &p3);

        void ChooseStartingPlayer() const;

        Board &getBoard();

        void printWinner() const;
    };
}
#endif // CATAN_HPP
