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

     WheelOfFortune player;
     player.readFile("../WOFPhrases.csv");
     cout << "Welcome to Wheel of Fortune!" << endl;
     player.printPhrase(cout);

     playing = player.activePlayer(cout, cin);

     while (playing && !solved) {
         int prize = player.spinWheel();
         cout << "Your prize: $" << prize << endl;
         cout << "Current balance: $" << balance << endl;

         consonants = player.guessConsonant(cout, cin);
         if (consonants > 0) {
             balance += (consonants * prize);
             player.printPhrase(cout);
             if (consonants == 1) {
                 cout << "There was " << consonants << " " << (char) toupper(player.getLastGuessed()) << "!" << endl;
             }
             else {
                 cout << "There were " << consonants << " " << (char) toupper(player.getLastGuessed()) << "'s!" << endl;
             }


             cout << "New balance: $" << balance << endl;
             char option = player.getOption(cout, cin);
             switch(toupper(option)) {
                 case 'V': {
                     vowels = player.guessVowel(cout, cin);
                     balance -= 250;
                     if (vowels == 1) {
                         cout << "There was " << vowels << " " << (char) toupper(player.getLastGuessed()) << "!" << endl;
                     }
                     else if (vowels > 0) {
                         cout << "There were " << vowels << " " << (char) toupper(player.getLastGuessed()) << "'s!" << endl;
                     }
                     else {
                         cout << "Sorry, no " << (char) toupper(player.getLastGuessed()) << " in this puzzle!" << endl;
                         consonants = 0;
                     }
                     player.printPhrase(cout);
                     break;
                 }
                 case 'P': {
                     string guess;
                     cout << "Solve: " << endl;
                     getline(cin, guess);
                     player.solvePuzzle(guess);
                     if (!player.guessedPhrase()) {
                         cout << "Sorry, you did not solve the puzzle." << endl;
                     }
                     break;
                 }
                 case 'C': {
                     consonants = player.guessConsonant(cout, cin);
                     //break;
                 }
                 case 'E': {
                     playing = false;
                     solved = true;
                     break;
                 }

             }
         }
         else if (consonants == 0) {
             player.printPhrase(cout);
             cout << "There were no " << (char) toupper(player.getLastGuessed()) << "'s!" << endl;
         }

         while (consonants == -1) {
             consonants = player.guessConsonant(cout, cin);
         }
         playing = player.activePlayer(cout, cin);

         if (player.guessedPhrase()) {
             cout << "You solved the puzzle!" << endl;
             player.printPhrase(cout);
             playing = player.playAgain(cout, cin);
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





