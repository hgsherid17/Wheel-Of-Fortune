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
#include <algorithm>
#include <ctype.h>
#include <cctype>
#include <iomanip>

using namespace std;

class WheelOfFortune {
private:
    vector<int> wheel;
    string phrase, category;
    vector<char> lettersGuessed;
    char lastGuessed;

    vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};


public:
    WheelOfFortune() {
        wheel = {500, 550, 600, 650, 700, 800, 900, 2500, 500, 550, 600, 650, 700};
        srand(time(NULL));

    }
    // Options
    void printGameOptions(ostream& outs) {
        outs << endl << "<><><>Options<><><>" << endl;
        outs << "C - Guess a consonant" << endl << "V - Buy a vowel" << endl << "P - Solve the puzzle!" << endl << "E - Exit" << endl;
        outs << "<><><><><><><><><><>" << endl << endl;
    }


    char getOption(ostream& outs, istream& ins) {
        string option;

        bool valid = false;

        printGameOptions(outs);

        outs << "Choose an option: ";
        getline(ins, option);

        while (!valid) {
            if (option =="") {
                valid = false;
                outs << "No input. Please choose an option: ";
                ins.clear();
                getline(ins, option);
            }
            else if (option.length() != 1 || toupper(option[0]) != 'C' && toupper(option[0]) != 'V' && toupper(option[0]) != 'P' && toupper(option[0]) != 'E') {
                valid = false;
                outs << "Did you even look at the options? Here they are again: " << endl;
                printGameOptions(outs);

                ins.clear();
                outs << "Choose an option: ";
                getline(ins, option);
            }
            else {
                valid = true;
            }
        }
        return option[0];
    }

    void printRoundOptions(ostream& outs) {
        outs << endl << "<><><>Options<><><>" << endl;
        outs << "S - Spin the wheel!" << endl << "E - Exit game" << endl;
        outs << "<><><><><><><><><><>" << endl << endl;
        outs << "Choose an option: ";
    }
    bool activePlayer(ostream& outs, istream& ins) {
        string active;
        bool valid = false;
        printRoundOptions(outs);
        getline(ins, active);

        while (!valid) {
            if (active == ""){
                valid = false;
                outs << "No input. Choose an option: ";
                ins.clear();
                getline(ins, active);
            }
            else if (active.length() != 1) {
                valid = false;
                outs << "That is not an option! Choose one from the list below: " << endl;
                printRoundOptions(outs);
                ins.clear();
                getline(ins, active);
            }

            else if (toupper(active[0]) != 'E' && toupper(active[0]) != 'S') {
                valid = false;
                outs << "That is not an option! Choose one from the list below: " << endl;
                printRoundOptions(outs);
                ins.clear();
                getline(ins, active);
            }
            else {
                valid = true;
            }

        }

        if (active == "S" || active == "s") {
            return true;
        }
        else {
            return false;
        }
    }

    bool readFile(string filename) {
        ifstream inFile;
        inFile.open(filename);

        char comma, quote;
        vector<string> categories, phrases;

        if (!inFile) {
            return false;
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

        setRandom(categories, phrases);

        return true;
    }

    void setRandom(vector<string> categories, vector<string> phrases) {
         int index = rand() % phrases.size();
         phrase = phrases[index];
         category = categories[index];
    }

    string getPhrase() {
         return this->phrase;
     }

    string getCategory() {
         return this->category;
    }

    void setPhrase (string p) {
        this->phrase = p;
    }

    int guessConsonant(ostream& outs, istream& ins) {
        int guessed = 0;
        string letter;
        bool valid = false;

        outs << "Guess a consonant: ";
        getline(ins, letter);

        while (!valid) {
             if (letter == "") {
                 valid = false;
                 outs << "No input. Guess a consonant: ";
                 ins.clear();
                 getline(ins, letter);
             }
             else if (letter.length() != 1 || !isalpha(letter[0]) || find(vowels.begin(), vowels.end(), toupper(letter[0])) != vowels.end()){
                 valid = false;
                 outs << "That is not a consonant! Try again: ";
                 ins.clear();
                 getline(ins, letter);
             }
             else if (find(lettersGuessed.begin(), lettersGuessed.end(), letter[0]) != lettersGuessed.end()) {
                 valid = false;
                 outs << "You have already guessed that letter!";
                 outs << " Try again: ";
                 ins.clear();
                 getline(ins, letter);
             }
             else {
                 valid = true;
             }
        }

        for (char ch : phrase) {
            if (ch == letter[0]) {
                ++guessed;
            }
        }

        lastGuessed = letter[0];
        lettersGuessed.push_back(letter[0]);
        return guessed;

    }

    int guessVowel(ostream& outs, istream& ins) {
        int guessed = 0;
        string letter;
        bool valid = false;

        outs << "Guess a vowel: ";

        getline(ins, letter);

        while (!valid) {
            if (letter == "") {
                valid = false;
                cout << "No input. Guess a vowel: ";
                ins.clear();
                getline(ins, letter);
            }
            else if (letter.length() != 1 || find(vowels.begin(), vowels.end(), toupper(letter[0])) == vowels.end()) {
                valid = false;
                cout << "That is not a vowel! Try again: " << endl;
                ins.clear();
                getline(ins, letter);
            }
            else if (find(lettersGuessed.begin(), lettersGuessed.end(), toupper(letter[0])) != lettersGuessed.end()) {
                valid = false;
                cout << "You have already guessed that letter! Try again: " << endl;
                ins.clear();
                getline(ins, letter);
            }
            else {
                valid = true;
            }

        }

        for (char ch : phrase) {
            if (ch == letter[0]) {
                guessed++;
            }
        }
        lastGuessed = letter[0];
        lettersGuessed.push_back(letter[0]);
        return guessed;

    }

    /**
     * TODO:
     * if not alpha, print normally
     *
     */
    void printPhrase(ostream& outs) {
        /*
        outs << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
        outs << "<>                                                      <>" << endl;*/
        outs << "            ";
        bool guessed = false;
        for (int i = 0; i < phrase.size(); ++i) {
            for (int j = 0; j < lettersGuessed.size(); ++j) {
                 if (toupper(phrase[i]) == toupper(lettersGuessed[j])) {
                     guessed = true;
                 }
            }
            if (guessed) {
                outs << (char) toupper(phrase[i]) << " ";
            }
            else if (!isalpha(phrase[i])) {
                outs << phrase[i] << " ";
            }
            else if (isspace(phrase[i])) {
                outs << "   ";
            }
            else {
                outs << "_ ";
            }
            guessed = false;
        }

        outs << endl;
        outs << "            " << "<><><> " << category << " <><><>" << endl;
        /*
        outs << endl << "<>                                                      <>" << endl;
        outs << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;*/
    }

    int spinWheel() {
        int prizeIndex = rand() % wheel.size();
        int prize = wheel[prizeIndex];

        return prize;
    }

    bool solvePuzzle(string guess) {
        int flag = 0;
        for (int i = 0; i < phrase.size(); ++i) {
            if (phrase[i] == guess[i]) {
                ++flag;
            }
        }

        if (flag == phrase.size()) {
            return true;
        }
        else {
            return false;
        }
    }
    bool guessedPhrase() {
        int flag = 0;
        for (int i = 0; i < phrase.size(); ++i) {
            for (int j = 0; j < lettersGuessed.size(); ++j) {
                if (toupper(phrase[i]) == toupper(lettersGuessed[j])) {
                    ++flag;
                }
            }
        }

        if (flag == phrase.length()) {
            return true;
        }
        else {
            return false;
        }
    }
    char getLastGuessed() {
        return this->lastGuessed;
    }
    bool playAgain(ostream& outs, istream& ins) {
        string ans;
        outs << "Play again? (y/n) " << endl;
        getline(ins, ans);

        while (ans.length() != 1 || toupper(ans[0]) != 'Y' && toupper(ans[0]) != 'N') {
            outs << "Invalid input. Please type y or n: " << endl;
            ins.clear();
            getline(ins, ans);
        }

        if (toupper(ans[0]) == 'Y') {
            return true;
        }
        else {
            return false;
        }
    }

};



#endif //M1OEP_HGSHERID_WHEELOFFORTUNE_H
