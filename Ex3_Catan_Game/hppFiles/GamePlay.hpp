#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Player.hpp"
#include "Board.hpp"
#include "Catan.hpp"
#include <vector>

namespace ariel
{
    class GamePlay
    {
    private:
        Catan catan;
        Board board;
        vector<Player *> players;
        int currentPlayerIndex;
        vector<Card *> cards;

    public:
        GamePlay(vector<Player *> &players, Catan &catan, Board &board);
        void startGame();
        void nextTurn();
        void rollDiceAndDistributeResources();
        void playerTurn(Player &player);
        bool playerBuySettlement(Player &player);
        void playerBuyRoad(Player &player);
        void playerBuyCity(Player &player);
        int rollDice() const;
        void tradeResources(Player &currentPlayer);
        void handleDiceRollEquals7();
        void checkWinnerAndEndGame(); // Declaration for checking winner and ending the game
    };
}
#endif // GAMEPLAY_HPP
