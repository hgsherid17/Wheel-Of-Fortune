//
// Created by Hannah Sheridan on 1/27/23.
//
#include "WheelOfFortune.h"
#include <ostream>
#include <iostream>
#include <string>

using namespace std;
/**
 * Word guessing game
 * Will expand to add wheel and prizes
 */
 int main() {
     // Make object
     int balance = 0;
     bool solved = false;
     bool playing = true;
     int consonants = 0;
     int vowels = 0;
     char option;

     WheelOfFortune player;
     player.readFile("../WOFPhrases.csv");
     cout << "Welcome to Wheel of Fortune!" << endl;


     player.printPhrase(cout);
     cout << player.getPhrase() << endl;
     playing = player.activePlayer(cout, cin);

     while (playing && !solved) {
         cout << endl << "Spinning the Wheel... " << endl;
         int prize = player.spinWheel();
         player.printPhrase(cout);
         cout << endl << "Your prize: $" << prize << endl;
         cout << "Current balance: $" << balance << endl;

         consonants = player.guessConsonant(cout, cin);

         while (consonants != 0) {
             balance += (consonants * prize);
             player.printPhrase(cout);

             if (consonants == 1) {
                 cout << "There is " << consonants << " " << (char) toupper(player.getLastGuessed()) << "!" << endl;
             }
             else {
                 cout << "There are " << consonants << " " << (char) toupper(player.getLastGuessed()) << "'s!" << endl;
             }

             cout << "New balance: $" << balance << endl;

             option = player.getOption(cout, cin);

             while (option != 'X') {
                 switch(toupper(option)) {
                     case 'V': {
                         if (balance > 250) {
                             vowels = player.guessVowel(cout, cin);
                             balance -= 250;
                             player.printPhrase(cout);

                             if (vowels == 1) {
                                 cout << "There is " << vowels << " " << (char) toupper(player.getLastGuessed()) << "!" << endl;
                                 option = player.getOption(cout, cin);
                                 break;
                             } else if (vowels > 1) {
                                 cout << "There are " << vowels << " " << (char) toupper(player.getLastGuessed()) << "'s!"
                                      << endl;
                                 option = player.getOption(cout, cin);
                                 break;
                             }
                             else {
                                 cout << "Sorry, there are no " << (char) toupper(player.getLastGuessed())
                                      << "'s in this puzzle!" << endl;
                                 option = 'X';
                                 break;
                             }
                         }
                         else {
                             cout << "You do not have enough money to buy a vowel!" << endl;
                             option = player.getOption(cout, cin);
                             break;
                         }

                     }
                     case 'P': {
                         string guess;
                         cout << "Solve: ";
                         getline(cin, guess);
                         //player.solvePuzzle(guess);
                         if ((player.solvePuzzle(guess))) {
                             player.printPhrase(cout);
                             cout << "You solved it!" << endl;
                             playing = player.playAgain(cout, cin);
                         }
                         else {
                            cout << "Sorry, you did not solve the puzzle. Guess more letters and try again!" << endl;
                         }
                         option = 'X';
                         break;
                     }
                     case 'C': {
                         consonants = player.guessConsonant(cout, cin);
                         option = 'X';
                         break;
                     }
                     case 'E': {
                         playing = false;
                         solved = true;
                         option = 'X';
                         break;
                     }
                 }

             }
         }
         if (consonants == 0) {
             player.printPhrase(cout);
             cout << "Sorry, there are no " << (char) toupper(player.getLastGuessed()) << "'s in this puzzle!" << endl;
             cout << "Balance: " << balance << endl;
         }

         if (player.guessedPhrase()) {
             cout << "You solved the puzzle!" << endl;
             player.printPhrase(cout);
             playing = player.playAgain(cout, cin);
         }

         if (playing) {
             playing = player.activePlayer(cout, cin);
         }

     }
     cout << "Thank you for playing! See you later :)" << endl;

     // Player spins wheel or exits


     // While playing
        // Consonant guessed after spinning wheel

        // If right
            // Guess vowel
            // Spin for new prize
            // Guess phrase



     /*
     // Initialize balance
     int balance = 0;
     string phrase;
     string category;
     string input;

     // Start game?


     player.readFile("../WOFPhrases.csv");
     cout << player.getPhrase() << endl;
     player.printPhrase(cout);
     int num = 0;

     int guessed = 0;
     guessed = player.guessConsonant(cout, cin);
     guessed = player.guessConsonant(cout, cin);
     guessed = player.guessConsonant(cout, cin);
     while (guessed == -1) {
        cout << "That letter was already guessed!";
        cin.clear();
        guessed = player.guessConsonant(cout, cin);
     }
*/
     /*
     num = player.guessConsonant(cout, cin);
     cout << "Cons: " << num << endl;
     num = player.guessVowel(cout, cin);
     cout << "Vow: " << num << endl;
*/
/*
     cout << "Press any key to spin the wheel: ";
     getline(cin, input);
     if (input != "") {
         player.readFile("../WOFPhrases.csv");
         player.setRandom();
         category = player.getCategory();

         cout << "Your balance: " << balance << endl;
         cout << "Category: " << category << endl;
         player.printPhrase(cout);
         char choice = player.getOption(cout, cin);

         int vowel;
         int consonant;
         while (choice != 'e') {
             switch (choice) {
                 case 'c' :


             }
         }


     }*/

        // Yes
            // Read in from file
            // Print sentence and category
            // Print balance
            // Print options
                // C - Consonant / spin wheel
                // V - Buy vowel
                // E - exit game
                    // Jumps to no
        // No
            // return 0



    // Spin the wheel



     return 0;
 }
/// Wheel of Fortune: Phrases ///





