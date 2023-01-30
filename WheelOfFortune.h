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
#include <fstream>
using namespace std;

class WheelOfFortune {
private:
    vector<int> wheel;
    string phrase;
    string category;

public:
    WheelOfFortune() {
        wheel = {500, 550, 600, 650, 700, 800, 900, 2500, 500, 550, 600, 650, 700, 0};
        //srand(time(NULL));
    }
    // Options
    void printOptions(ostream outs) {
        outs << "<><><> Options <><><>" << endl;
        outs << "V - Buy a vowel" << endl << "C - Consonant" << endl << "P - Solve the puzzle!" << endl;
    }
/*
    bool guessLetter(char letter){

    }*/
     void readFile(string filename) {
        ifstream inFile;
        inFile.open(filename);

        vector<string> categories, phrases;
        char comma, quote;

        if (inFile) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        while (inFile && inFile.peek() != EOF) {
            if (inFile.peek() == '"') {
                inFile >> quote;
                getline(inFile, category, '"');
                inFile >> comma;
            }
            else {
                getline(inFile, category, ',');
            }

            if (inFile.peek() == '"') {
                inFile >> quote;
                getline(inFile, phrase, '"');
                inFile >> comma;
            }
            else {
                getline(inFile, phrase, '\n');
            }

            categories.push_back(category);
            phrases.push_back(phrase);
        }
        inFile.close();
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
