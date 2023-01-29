//
// Created by Hannah Sheridan on 1/29/23.
//

#ifndef M1OEP_HGSHERID_WHEELOFFORTUNE_H
#define M1OEP_HGSHERID_WHEELOFFORTUNE_H

#include <string>
#include <vector>
#include <functional>
#include <random>
#include <ostream>
#include <iostream>
using namespace std;

template<typename Prizes>
class WheelOfFortune {
private:
    vector<Prizes> wheel;
    int balance;
    string phrase;

public:
    WheelOfFortune() {
        wheel = {500, 550, 600, 650, 700, 800, 900, 2500, 500, 550, 600, 650, 700, "Bankrupt"};
        balance = 0;
    }

    // Options
    void printOptions(ostream outs) {
        outs << "<><><> Options <><><>" << endl;
        outs << "V - Buy a vowel" << endl << "C - Consonant" << endl << "P - Solve the puzzle!" << endl;
    }

    string getPhrase(string filename) {

    }
    /** Spin wheel
    bool spinWheel(ostream outs) {
        Prizes prizeIndex = rand() % wheel.size();
        Prizes prize = wheel[prizeIndex];

        if (prize == "Bankrupt") {
            outs << "You've gone Bankrupt!" << endl;
            balance = 0;
        }
        else {
            outs << ""
        }
    }**/
    // Options

    // Get phrase

    // Buy vowel

    // Bank
        // User balance

};



#endif //M1OEP_HGSHERID_WHEELOFFORTUNE_H
