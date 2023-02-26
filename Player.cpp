#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
    // fillWheel();
    balance = 0;
    name = "Current Player";
    prize = 200;
    numWins = 0;
}
Player::Player(string name) {
   // fillWheel();
    balance = 0;
    this->name = name;
    prize = 200;
    numWins = 0;
}

int Player::getBalance() {
    return this->balance;
}
int Player::getNumWins() {
    return this->numWins;
}
int Player::getPrize() {
    return this->prize;
}
string Player::getName() const {
    return this->name;
}

void Player::setBalance(int bal) {
   balance = bal;
}
void Player::setNumWins(int wins) {
    numWins = wins;
}
void Player::setPrize(int wedge) {
    prize = wedge;
}
void Player::setName(string playerName) {
    name = playerName;
}

void Player::guessConsonant(int numGuessed) {
    int prizeMoney = (prize * numGuessed);
    balance += prizeMoney;
}

void Player::buyVowel() {
    balance -= 250;
}

void Player::bankrupt() {
    balance = 0;
}

void Player::winner() {
    ++numWins;
}


bool Player::sufficientFunds() {
    if (balance >= 250) {
        return true;
    }
    else {
        return false;
    }
}

bool operator == (const Player &lhs, const Player &rhs) {
    if (lhs.getName() == rhs.getName()) {
        return true;
    }
    return false;
}

bool operator == (const Player &lhs, const string &rhs) {
    if (lhs.getName() == rhs) {
        return true;
    }
    return false;
}
ostream& operator << (ostream& outs, Player rhs) {
    char lastChar;
    for (int i = 0; i < rhs.getName().length(); ++i) {
        if (i == 0) {
            outs << (char) toupper(rhs.getName()[i]);
        }
        else if (lastChar == ' ') {
            outs << (char) toupper(rhs.getName()[i]);
        }
        else {
            outs << (char) tolower(rhs.getName()[i]);
        }
        lastChar = rhs.getName()[i];
    }
    return outs;
}

