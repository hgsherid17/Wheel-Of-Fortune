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
    //vector<int> wheel;

public:
    Player();
    Player(string name);

    // Getters
    int getBalance();
    int getNumWins();
    int getPrize();
    string getName();
    //vector<int> getWheel();

    // Setters
    void setBalance(int bal);
    void setNumWins(int wins);
    void setPrize(int wedge);
    void setName(string playerName);

    /**
     * Fills the wheel vector with values between 200-2500
     * Decreased likelihood of getting a high number
     */
    //void fillWheel();

    /**
     * Randomly chooses an element from the wheel vector and sets the current
     * prize value to that element
     */
    //void spinWheel();

    /*
     * Takes in number of correctly guessed consonants and updates balance accordingly
     */
    void guessConsonant(int numGuessed);

    /**
     * Removes $250 from players balance
     */
    void buyVowel();

    void bankrupt();

    void winner();

    /*
     * Returns true if user has sufficient funds to buy a vowel
     */
    bool sufficientFunds();

    friend bool operator == (Player &lhs, Player &rhs);

    friend ostream& operator << (ostream& outs, Player rhs);

};


#endif //M1OEP_HGSHERID_PLAYER_H
