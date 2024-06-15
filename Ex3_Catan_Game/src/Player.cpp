//Player.cpp

#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <Board.hpp>
using namespace ariel;

Player::Player(const string& playerName) : name(playerName), points(0) {
    //init resources
}

void Player::placeSettlement(const vector<string>& places, const std::vector<int>& placesNum, Board& board) {
    // Implementation to place settlement on the board
    // Update player's points
    points += 1;
}

void Player::placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
    // Implementation to place road on the board
}

void Player::rollDice() {
    // Implementation to roll dice and distribute resources
}

void Player::trade(Player& otherPlayer, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount) {
    // Implementation for trading resources
    if (resources[giveResource] >= giveAmount) {
        resources[giveResource] -= giveAmount;
        resources[getResource] += getAmount;
        otherPlayer.resources[giveResource] += giveAmount;
        otherPlayer.resources[getResource] -= getAmount;
    } else {
        throw std::runtime_error("Insufficient resources for trade");
    }
}

void Player::buyDevelopmentCard() {
    // Implementation to buy development card
}

void Player::printPoints() const {
    std::cout << name << " has " << points << " points." << std::endl;
}

void Player::endTurn() {
    // Implementation to end turn
}

std::string Player::getName() const {
    return name;
}