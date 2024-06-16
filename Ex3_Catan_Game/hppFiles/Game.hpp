#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Player.hpp"
#include "Board.hpp"

namespace ariel
{
    class Game
    {
    private:
        Player p1, p2, p3;
        vector<Player> players;
        Board board;
        int currentPlayerIndex;
        bool gameOver;

    public:
Game::Game(const string& playerName1, const string& playerName2, const string& playerName3);
        void start(); // Start the game
        void ChooseStartingPlayer();
        void simulateTurns();
        void printWinner() const;
        void printPoints() const;
        void playTurn();           // Play a turn for the current player
        void switchToNextPlayer(); // Switch to the next player
        bool isGameOver();         // Check if the game is over
    };
}
#endif
