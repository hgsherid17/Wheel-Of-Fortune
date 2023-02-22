//
// Created by Hannah Sheridan on 2/20/23.
//
#include "WheelOfFortune.h"
#include "Player.h"
#include <vector>
bool testWheelOfFortune();

int main() {
    testWheelOfFortune();
    return 0;
}

bool testWheelOfFortune() {
    bool passed = true;
    WheelOfFortune test;

    // Test setters
    test.setPhrase("Hello");
    if (test.getPhrase() != "Hello") {
        cout << "FAILED setPhrase() test case" << endl;
        passed = false;
    }

    test.setCategory("Thing");
    if (test.getCategory() != "Thing") {
        cout << "FAILED setCategory() test case" << endl;
    }


    Player player;

    return passed;
}

