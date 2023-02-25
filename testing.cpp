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
/**
 * TODO: There are lots of "print" functions in this class.... how should I test them?
 * @return
 */
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

bool testPlayer() {
    bool passed = true;

    // 


    return passed;
}

bool testWheel() {
    bool passed = true;

    Wheel wheel;

    // Default constructor
    if (wheel.getCurrentWedge() != 200) {
        cout << "FAILED default constructor test case 1" << endl;
        passed = false;
    }
    if (wheel.getWheel().size() == 0) {
        cout << "FAILED default constructor test case 2" << endl;
        passed = false;
    }

    vector<int> testWheel = {300, 400, 500, 600};
    Wheel wheel2(testWheel);

    // Constructor
    if (wheel2.getWheel().size() != 4) {
        cout << "FAILED constructor test case 1" << endl;
        passed = false;
    }
    if (wheel2.getCurrentWedge() != 300) {
        cout << "FAILED constructor test case 2" << endl;
        passed = false;
    }

    // Add wedge
    wheel2.addWedge(700);
    if (find(wheel2.getWheel().begin(), wheel2.getWheel().end(), 700) != wheel2.getWheel().end()) {
        cout << "FAILED addWedge test case 1" << endl;
        passed = false;
    }
    if (wheel2.getSize() != 5) {
        cout << "FAILED addWedge test case 2" << endl;
        passed = false;
    }
    if (wheel2.getCurrentWedge() != 700) {
        cout << "FAILED addWedge test case 3" << endl;
        passed = false;
    }
    if (wheel2.addWedge(300)) {
        cout << "FAILED cannot add wedge test case" << endl;
        passed = false;
    }

    // Remove wedge
    if (wheel2.removeWedge(800)) {
        cout << "FAILED cannot remove wedge test case" << endl;
        passed = false;
    }

    wheel2.removeWedge(300);
    if (find(wheel2.getWheel().begin(), wheel2.getWheel().end(), 300) == wheel2.getWheel().end()) {
        cout << "FAILED remove wedge test case 1" << endl;
    }

    wheel2.removeWedge(400);
    if (wheel2.getSize() != 2) {
        cout << "FAILED remove wedge test case 2" << endl;
        passed = false;
    }

    Wheel wheel3;
    wheel3.fillWheel();

    if (wheel3.getSize() != 25) {
        cout << "FAILED fillWheel test case 1" << endl;
        passed = false;
    }

    /**
     * TODO: add another for this func?
     */

    cout << "Testing Wheel class overloaded print operator..." << endl;
    cout << wheel3;
    cout << "End testing Wheel class overloaded print operator" << endl;

    return passed;
}