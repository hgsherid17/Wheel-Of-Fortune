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
#include <cctype>
#include <iomanip>
#include "Player.h"

using namespace std;
/**
 * The Wheel of Fortune class represents functions of the wheel of fortune game.
 * It is also now a two-player game!
 * It has the following fields:
 * phrase: the current puzzle to be guessed by the user
 * category: the topic of the given puzzle
 * letterGuessed: a vector to hold each letter the user has guessed
 * phrases: a vector to hold all possible phrases
 * categories: a vector to hold all possible categories
 * lastGuessed: holds the last letter to be guessed by the user
 * wheel: a constant vector that holds the prizes offered
 * vowels: a constant vector to hold vowels
 */
class WheelOfFortune {
private:
    string phrase, category;
    vector<char> lettersGuessed;
    vector<string> categories, phrases;
    char lastGuessed;
    vector<Player> players;
    int currentPlayer;
    const vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};
public:
    /**
     * Default constructor initializes fields
     */
    WheelOfFortune();

    // Getters
    string getPhrase();
    string getCategory();
    char getLastGuessed();
    vector<char> getLettersGuessed();
    vector<string> getPhrases();
    vector<string> getCategories();
    vector<Player> getPlayers();

    // Setters
    void setPhrase (string p);
    void setCategory(string c);
    void setPlayers(Player player1, Player player2);

    /**
     * Table of options
     * @param outs
     */
    void printGameOptions(ostream& outs);

    /**
     * getOption() prompts user to choose a game option and validates their choice.
     * The function returns the option once it is validated.
     * @param outs
     * @param ins
     * @return option
     */
    char getOption(ostream& outs, istream& ins);

    /**
    * Prints the options that are offered between rounds
    * @param outs
    */
    void printRoundOptions(ostream& outs);

    /**
     * activePlayer() checks if the player would like to continue a new round by prompting
     * the user to spin the wheel or exit the game and validates their choice.
     * If the user chooses to spin, the function returns true.
     * If the user chooses to exit, the function returns false.
     * @param outs
     * @param ins
     * @return boolean value true or false
     */
    bool activePlayer(ostream& outs, istream& ins);

    /**
     * readFile() reads through a given file and passes values to vectors
     * representing phrases and categories. The function returns true
     * if the file is successfully opened and read.
     * @param filename
     * @return boolean value
     */
    bool readFile(string filename);

    /**
     * setRandom() sets the phrase and category variables to a random
     * value from their respective vectors.
     *
     * @param categories
     * @param phrases
     */
    void setRandom();

    /**
     * guessConsonant() prompts a user to guess a consonant and validates their response.
     * If validated, the consonant will be searched for in the phrase. The function will
     * return the amount of that specific consonant found in the phrase.
     * @param outs
     * @param ins
     * @return guessed // The number of consonants correctly guessed
     */
    int guessConsonant(ostream& outs, istream& ins);

    /**
     * guessVowel() prompts a user to guess a vowel and validates their response.
     * If validated, the vowel will be searched for in the phrase. The function will
     * return the amount of that specific vowel found in the phrase.
     * @param outs
     * @param ins
     * @return guessed // The number of correctly guessed vowels
     */
    int guessVowel(ostream& outs, istream& ins);


    /**
     * printPhrase() prints a formatted version of the given phrase. The function will only
     * print the letters that the user has correctly guessed. If a letter has not yet been
     * guessed, the function will print an underscore. Punctuation is printed normally.
     * @param outs
     */
    void printPhrase(ostream& outs);

    void printLettersGuessed(ostream& outs);

    /**
     * spinWheel() chooses a random value from the prizes vector and
     * retur ns that value.
     * @return prize
     */
    int spinWheel();

    /**
     * solvePuzzle takes in a string and compares it with the current phrase.
     * If the string matches the phrase, the function returns true. Otherwise,
     * the function returns false.
     * @param guess
     * @return boolean value
     */
    bool solvePuzzle(string guess);

    bool guessedPhrase();

    /**
     * playAgain() asks the user if they wish to play again and validates the input.
     * If the user chooses to play again, the function returns true.
     * @param outs
     * @param ins
     * @return boolean value
     */
    bool playAgain(ostream& outs, istream& ins);

    void switchPlayers();

    Player getCurrentPlayer();





};



#endif //M1OEP_HGSHERID_WHEELOFFORTUNE_H
