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
    vector<int> wheel;

public:
    Player();
    Player(string name);

    // Getters
    int getBalance();
    int getNumWins();
    int getCurrentPrize();
    string getName();
    vector<int> getWheel();

    // Setters
    void setBalance(int bal);
    void setNumWins(int wins);
    void setCurrentPrize(int wedge);
    void setName(string playerName);

    /******
     * TODO: WHEEL CLASS?
     */
    /**
     * Fills the wheel vector with values between 200-2500
     * Decreased likelihood of getting a high number
     */
    void fillWheel();

    /**
     * Randomly chooses an element from the wheel vector and sets the current
     * prize value to that element
     */
    void spinWheel();

    void bankrupt();
    /*
     * Returns true if user has sufficient funds to buy a vowel
     */
    bool sufficientFunds();

};


#endif //M1OEP_HGSHERID_PLAYER_H
