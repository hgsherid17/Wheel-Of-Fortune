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

    vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};


public:
    WheelOfFortune() {
        wheel = {500, 550, 600, 650, 700, 800, 900, 2500, 500, 550, 600, 650, 700, 0};
        srand(time(NULL));

    }
    // Options
    void printOptions(ostream& outs) {
        outs << "<><>Options<><>" << endl;
        outs << "C - Guess a consonant" << endl << "V - Buy a vowel" << endl << "P - Solve the puzzle!" << endl << "E - Exit" << endl;
    }

    char getOption(ostream& outs, istream& ins) {
        string option;
        char choice;

        printOptions(outs);

        getline(cin, option);
        while (option != "c" && option != "v" && option != "p" && option != "e" && option.length() != 1) {
            outs << "Invalid input. Please choose an option: ";
            getline(cin, option);
        }

        choice = option[0];

        return choice;

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

        outs << "Enter a consonant: ";
        getline(ins, letter);

        /**
         * TODO: validate if digit in string
         */
        while (letter.length() != 1 || letter == "" || find(vowels.begin(), vowels.end(), toupper(letter[0])) != vowels.end()) {
            if (letter == "") {
                outs << "No input. Enter a consonant: ";
                ins.clear();
                getline(ins, letter);
            }
            else {
                outs << "That is not a consonant! Try again: ";
                ins.clear();
                getline(ins, letter);
            }
        }


        for (int i = 0; i < lettersGuessed.size(); ++i) {
            if (lettersGuessed[i] == letter[0]) {
                cout << "You have already guessed that letter!" << endl;
                return -1;
            }
        }
        for (char ch : phrase) {
            if (ch == letter[0]) {
                guessed++;
            }
        }

        lettersGuessed.push_back(letter[0]);
        return guessed;

    }

    int guessVowel(ostream& outs, istream& ins) {
        int guessed = 0;
        string letter;

        outs << "Enter a vowel: ";

        getline(ins, letter);

        while (letter.length() != 1 || letter == "" || find(vowels.begin(), vowels.end(), toupper(letter[0])) == vowels.end()) {
            if (letter == "") {
                outs << "No input. Enter a vowel: ";
                ins.clear();
                getline(ins, letter);
            }
            else {
                outs << "That is not a vowel! Try again: ";
                ins.clear();
                getline(ins, letter);
            }
        }

        // Do this or prompt again?
        for (char ch : lettersGuessed) {
            if (ch == letter[0]) {
                return -1;
            }
        }
        for (char ch : phrase) {
            if (ch == letter[0]) {
                guessed++;
            }
        }
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
        /*
        outs << endl << "<>                                                      <>" << endl;
        outs << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;*/
    }

    int spinWheel() {
        int prizeIndex = rand() % wheel.size();
        int prize = wheel[prizeIndex];

        return prize;
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
};



#endif //M1OEP_HGSHERID_WHEELOFFORTUNE_H
