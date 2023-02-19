/*
 * Created by Hannah Sheridan
 * CS 120 Section B
 * Open-Ended Project
 *
 */
#include "WheelOfFortune.h"
#include <ostream>
#include <iostream>
#include <string>
using namespace std;

/*
 * Main uses the WheelOfFortune class to build a user interface for the Wheel of Fortune game.
 * It stores the user's balance and current prize.
 * */

/**
 * TODO: "Help" option to print game rules and/or give the user a suggestion on what to do/guess
 * ex: you have 4 vowels left, why not try guessing a vowel?
 * TODO: Play with a second user
 * TODO: Do not allow user to guess vowel if all possible vowels have been guessed
 *
 *
 */
 int main() {
     // Variables
     int balance = 0;
     bool solved = false;
     bool playing;
     bool round;
     int consonants;
     int vowels;
     char option = 'C';
     int prize;
     int vowelsGuessed = 0;

     // Create object and get puzzle from file
     WheelOfFortune player;
     player.readFile("../WOFPhrases.csv");
     player.setRandom();

     // Game home screen
     cout << "Welcome to Wheel of Fortune!" << endl;
     player.printPhrase(cout);

     // Prompt user to spin wheel
     playing = player.activePlayer(cout, cin);

     while(playing){
         // If user decides to spin the wheel, spin wheel and print prize
         cout << endl << "Spinning the wheel..." << endl;
         prize = player.spinWheel();
         player.printPhrase(cout);
         cout << endl << "Your prize: $" << prize << endl;
         cout << "Balance: $" << balance << endl;

         // Prompt user to guess a consonant
         consonants = player.guessConsonant(cout, cin);
         player.printPhrase(cout);

         // Display output and update balance based on number of consonants guessed
         if (consonants > 1) {
             cout << "There are " << consonants << " " << player.getLastGuessed() << "'s!" << endl;
             balance += (consonants * prize);
             cout << "Balance: $" << balance << endl;
             round = true;
         }
         else if (consonants == 1) {
             cout << "There is " << consonants << " " << player.getLastGuessed() << "!" << endl;
             balance += prize;
             cout << "Balance: $" << balance << endl;
             round = true;
         }
         else {
             cout << "Sorry, there are no " << player.getLastGuessed() << "'s in this puzzle!" << endl;
             cout << "Balance: $" << balance << endl;
             round = false;
         }

         if (player.guessedPhrase()) {
             cout << "Congratulations, you solved the puzzle!" << endl;
             solved = true;
             round = false;
             option = 'E';
         }
         // If user guesses a consonant correctly, allow them more game options
         while (round) {
             option = player.getOption(cout, cin);
             switch(option) {

                 // User chose to guess a consonant
                 case 'C': {
                     // Jump out of loop and spin the wheel again
                     round = false;
                     break;
                 }

                 // User chose to buy a vowel
                 case 'V': {
                     // Ensure user has sufficient funds
                     if (balance > 250) {
                         balance -= 250;

                         // Prompt user to guess a vowel
                         ++vowelsGuessed;
                         vowels = player.guessVowel(cout, cin);
                         player.printPhrase(cout);

                         // Display message based on number of vowels guessed
                         if (vowels > 1) {
                             cout << "There are " << vowels << " " << player.getLastGuessed() << "'s!" << endl;

                         } else if (vowels == 1) {
                             cout << "There is " << vowels << " " << player.getLastGuessed() << "! " << endl;

                         } else {
                             // If they guess wrong, restart round
                             cout << "Sorry, there are no " << player.getLastGuessed() << "'s in this puzzle!" << endl;
                             round = false;
                         }
                         cout << "Balance: $" << balance << endl;
                         break;
                     }
                     // If insufficient funds, reprompt user to choose another option
                     while (balance < 250) {
                         cout << "Sorry, you do not have enough money to buy a vowel!" << endl;
                         option = player.getOption(cout, cin);
                         break;
                     }
                     break;
                 }
                 // User chose to solve the puzzle
                 case 'P': {
                     string guess;
                     cout << "Solve the puzzle: ";
                     getline(cin, guess);
                     while (guess == "") {
                         cout << "No input. Please try to solve the puzzle: ";
                         cin.clear();
                         getline(cin, guess);
                     }

                     // Jump out of loop if user guesses correctly
                     if ((player.solvePuzzle(guess))) {
                         player.printPhrase(cout);
                         cout << "Congratulations, you solved the puzzle!" << endl;
                         round = false;
                         solved = true;
                     }
                     // Start another round if user guesses wrong
                     else {
                         cout << "Sorry, you did not solve the puzzle. Guess more letters and try again!" << endl;
                         round = false;
                         break;
                     }
                 }
                 // User chooses to exit game
                 case 'E' : {
                     // Quit program
                     round = false;
                     playing = false;
                     option = 'C';
                 }
             }
             if (player.guessedPhrase()) {
                 cout << "Congratulations, you solved the puzzle!" << endl;
                 solved = true;
             }

         }
         // If the player has solved the puzzle
         if (solved){
             // Ask if they would like to play again
             option = 'C';
             playing = player.playAgain(cout, cin);

             // Get new phrase if user chooses to play again
             // Otherwise, leave program
             if (playing) {
                 solved = false;
                 player.setRandom();
             }
             else {
                 round = false;
             }
         }

         // If user guesses incorrectly, start a new round
         if (option != 'C' || consonants == 0) {
             playing = player.activePlayer(cout, cin);
         }

     }
     // Goodbye message for end of game
     cout << "Thank you for playing! See you later :)" << endl;
     cout << "Final balance: $" << balance << endl;

     return 0;
 }
/// Wheel of Fortune: Phrases ///





