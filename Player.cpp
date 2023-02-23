#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
    fillWheel();
    balance = 0;
    name = "Current Player";
}
Player::Player(string name) {
    fillWheel();
    balance = 0;
    this->name = name;
}

int Player::getBalance() {
    return this->balance;
}
int Player::getNumWins() {
    return this->numWins;
}
int Player::getCurrentPrize() {
    return this->prize;
}
string Player::getName() {
    return this->name;
}
vector<int> Player::getWheel() {
    return this->wheel;
}

void Player::setBalance(int bal) {
   balance = bal;
}
void Player::setNumWins(int wins) {
    numWins = wins;
}
void Player::setCurrentPrize(int wedge) {
    prize = wedge;
}
void Player::setName(string playerName) {
    name = playerName;
}

void Player::fillWheel() {
    for (int i = 200; i <= 700; i += 50) {
        wheel.push_back(i);
        wheel.push_back(i);
    }

    // Highest value prize, lose a turn, and bankrupt are less probable
    wheel.push_back(1000);
    wheel.push_back(2500);
    wheel.push_back(0); // Bankrupt
    wheel.push_back(-1); // Lose a turn
}

void Player::spinWheel() {
    srand(time(nullptr));
    int randIndex = rand() % wheel.size();

    prize = wheel[randIndex];

}

void Player::bankrupt() {
    balance = 0;
}

bool Player::sufficientFunds() {
    if (balance >= 250) {
        return true;
    }
    else {
        return false;
    }
}