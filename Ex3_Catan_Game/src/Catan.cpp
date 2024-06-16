#include "Catan.hpp"
#include <iostream>
using namespace ariel;

Catan::Catan(Player& player1, Player& player2, Player& player3) : p1(player1), p2(player2), p3(player3) {}

void Catan::ChooseStartingPlayer() const {
    std::cout << "Starting player: " << p1.getName() << std::endl;
}

Board& Catan::getBoard() {
    return board;
}

void Catan::printWinner() const {
    std::cout << "None" << std::endl; // Placeholder for determining the winner
}
