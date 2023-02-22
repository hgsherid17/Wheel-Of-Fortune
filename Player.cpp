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

void Player::setBalance(int bal) {
   balance = bal;
}
void Player::setNumWins(int wins) {
    numWins = wins;
}
void Player::setCurrentPrize(int wedge) {
    prize = wedge;
}

vector<int> Player::getWheel() {
    return this->wheel;
}

void Player::fillWheel() {
    for (int i = 200; i <= 2500; i += 50) {
        wheel.push_back(i);
        for (int j = 200; j <= 300; j += 50) {
            wheel.push_back(j);
        }

    }
}

void Player::spinWheel() {
    srand(time(NULL));

    int wedge = rand() % wheel.size();

    setCurrentPrize(wedge);

}

int Player::numGuessed() {

}

bool Player::sufficientFunds() {
    if (balance >= 250) {
        return true;
    }
    else {
        return false;
    }
}