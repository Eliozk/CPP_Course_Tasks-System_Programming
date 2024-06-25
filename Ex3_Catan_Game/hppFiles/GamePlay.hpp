#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Player.hpp"
#include "Board.hpp"
#include "Catan.hpp"
#include <vector>

namespace ariel {
    class GamePlay {
    private:
        Catan catan;
        Board board;
        vector<Player*> players;
        int currentPlayerIndex;

    public:
        GamePlay(vector<Player*> &players, Catan& catan, Board &board);
        void startGame();
        void nextTurn();
        void rollDiceAndDistributeResources();
        void playerTurn(Player &player);
         bool playerBuySettlement(Player &player);
         bool playerBuyRoad(Player &player);
        // void displayGameState();
    };
}
#endif // GAMEPLAY_HPP
