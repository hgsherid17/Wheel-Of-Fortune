//
// Created by Hannah Sheridan on 2/21/23.
//

#ifndef M1OEP_HGSHERID_PLAYER_H
#define M1OEP_HGSHERID_PLAYER_H

#include <vector>
using namespace std;

class Player {
private:
    int balance;
    int numWins;
    int prize;
    vector<int> wheel;

public:
    Player();

    // Getters
    int getBalance();
    int getNumWins();
    int getCurrentPrize();

    int spinWheel();

    int numGuessed();

};


#endif //M1OEP_HGSHERID_PLAYER_H
