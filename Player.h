//
// Created by Hannah Sheridan on 2/21/23.
//

#ifndef M1OEP_HGSHERID_PLAYER_H
#define M1OEP_HGSHERID_PLAYER_H

#include <vector>
#include <string>
using namespace std;

class Player {
private:
    int balance;
    int numWins;
    int prize;
    string name;

public:
    Player();
    Player(string name);

    // Getters
    int getBalance();
    int getNumWins();
    int getPrize();
    string getName() const;

    // Setters
    void setBalance(int bal);
    void setNumWins(int wins);
    void setPrize(int wedge);
    void setName(string playerName);

    /*
     * Takes in number of correctly guessed consonants and updates balance accordingly
     */
    void guessConsonant(int numGuessed);

    /**
     * Removes $250 from players balance
     */
    void buyVowel();

    /**
     * Sets players balance to zero
     */
    void bankrupt();

    /**
     * increments numWins
     */
    void winner();

    /*
     * Returns true if user has sufficient funds to buy a vowel
     */
    bool sufficientFunds();

    // Overloaded Operators
    friend bool operator == (const Player &lhs, const Player &rhs);
    friend bool operator == (const Player &lhs, const string &rhs);
    friend ostream& operator << (ostream& outs, Player rhs);

};


#endif //M1OEP_HGSHERID_PLAYER_H
