//
// Created by Hannah Sheridan on 2/20/23.
//
#include "WheelOfFortune.h"
#include "Player.h"
#include <vector>
bool testWheelOfFortune();
bool testPlayer();
bool testWheel();

int main() {
    if (testWheelOfFortune()) {
        cout << "PASSED ALL WHEEL OF FORTUNE TEST CASES" << endl;
    }
    if (testPlayer()) {
        cout << "PASSED ALL PLAYER TEST CASES" << endl;
    }
    if (testWheel()) {
        cout << "PASSED ALL WHEEL TEST CASES" << endl;
    }
    return 0;
}
/**
 * TODO: There are lots of "print" functions in this class.... how should I test them?
 * @return
 */
bool testWheelOfFortune() {
    bool passed = true;
    WheelOfFortune test;

    // Solve puzzle
    // Guessed phrase
    // Switch players
    //
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

    // Default constructor
    Player player1;
    if (player1.getName() != "Current Player") {
        cout << "FAILED Player default constructor test case" << endl;
        passed = false;
    }
    if (player1.getBalance() != 0 || player1.getNumWins() != 0) {
        cout << "FAILED Player default constructor test case 2" << endl;
        passed = false;
    }
    if (player1.getPrize() != 200) {
        cout << "FAILED default constructor test case 3" << endl;
        passed = false;
    }

    // Constructor
    Player player2("Hannah");
    if (player2.getName() != "Hannah") {
        cout << "FAILED Player constructor test case 1" << endl;
        passed = false;
    }

    if (player2.getBalance() != 0 || player2.getNumWins() != 0) {
        cout << "FAILED Player constructor test case 2" << endl;
        passed = false;
    }
    if (player2.getPrize() != 200) {
        cout << "FAILED Player constructor test case 3" << endl;
        passed = false;
    }

    // Guess consonant
    player1.setPrize(100);

    player1.guessConsonant(3);
    if (player1.getBalance() != 300) {
        cout << "FAILED guess consonant test case 1" << endl;
        passed = false;
    }

    // Buy vowel
    player1.buyVowel();
    if (player1.getBalance() != 50) {
        cout << "FAILED buy vowel test case 1" << endl;
        passed = false;
    }

    // Bankrupt
    player1.bankrupt();
    if (player1.getBalance() != 0) {
        cout << "FAILED bankrupt test case" << endl;
        passed = false;
    }

    // Sufficient funds
    if (player1.sufficientFunds()) {
        cout << "FAILED sufficient funds test case" << endl;
        passed = false;
    }

    player1.setName("Jane Doe");
    player2.setName("Jane Doe");
    // Overloaded == operator
    if (!(player1 == player2)) {
        cout << "FAILED overloaded == operator test case" << endl;
        passed = false;
    }

    player2.setName("John Doe");
    if (player1 == player2) {
        cout << "FAILED overloaded == operator" << endl;
        passed = false;
    }

    // Overloaded << operator
    cout << "Testing Player overloaded print operator..." << endl;
    cout << "Player 1: " << player1 << endl << "Player 2: " << player2 << endl;
    cout << "End testing Player overloaded print operator" << endl;

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
    if (find(wheel2.getWheel().begin(), wheel2.getWheel().end(), 700) == wheel2.getWheel().end()) {
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
    if (wheel2.getSize() != 3) {
        cout << "FAILED remove wedge test case 2" << endl;
        passed = false;
    }

    Wheel wheel3;
    wheel3.fillWheel();

    if (wheel3.getSize() != 26) {
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