//
// Created by Hannah Sheridan on 2/24/23.
//
#include "Wheel.h"
#include <vector>

using namespace std;
Wheel::Wheel() {
    fillWheel();
    wedge = 200;
}
Wheel::Wheel(vector<int> wheel) {
    this->wheel = wheel;
    wedge = wheel[0];
}

vector<int> Wheel::getWheel() {
    return this->wheel;
}
int Wheel::getCurrentWedge() {
    return this->wedge;
}

bool Wheel::addWedge(int wedge) {
    if (find(wheel.begin(), wheel.end(), wedge) != wheel.end()) {
        // Wedge is already in wheel
        return false;
    }
    else {
        wheel.push_back(wedge);
        return true;
    }
}
bool Wheel::removeWedge(int wedge) {
    if (find(wheel.begin(), wheel.end(), wedge) == wheel.end()) {
        for (int i = 0; i < wheel.size(); ++i) {
            if (wheel[i] == wedge) {
                wheel.erase(wheel.begin() + i);
            }
        }
        return true;
    }
    else {
        // Wedge is not in wheel and cannot be removed
        return false;
    }
}
void Wheel::fillWheel() {
    for (int i = 200; i <= 700; i += 50) {
        wheel.push_back(i);
        wheel.push_back(i);
    }

    // Highest value prize, lose a turn, and bankrupt are less probable
    wheel.push_back(1000);
    wheel.push_back(2500);
    wheel.push_back(0); // Bankruptwheel.push_back(-1); // Lose a turn

}
int Wheel::spin() {
    srand(time(nullptr));
    int randIndex = rand() % wheel.size();

    wedge = wheel[randIndex];

    return wedge;

}
/*
ostream& operator << (ostream& outs, Wheel& rhs) {
    for (int i = 0; i < wheel.size(); ++i)
}*/