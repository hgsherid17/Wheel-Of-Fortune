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
     WheelOfFortune player;
     player.readFile("../WOFPhrases.csv");
     cout << "Welcome to Wheel of Fortune!" << endl;
     player.printPhrase(cout);

     while (player.activePlayer(cout, cin)) {
         int prize = player.spinWheel();
         if (prize == 0) {
             balance = 0;
             cout << "You've gone bankrupt!" << endl;
             cout << "New balance: $" << balance << endl;
         }
         else {
             cout << "Your prize: $" << prize << endl;
             cout << "Current balance: $" << balance << endl;
         }
         int consonants = player.guessConsonant(cout, cin);
         while (consonants > 0) {
             cout << "There were " << consonants << " " << (char) toupper(player.getLastGuessed()) << "'s!" << endl;
             player.printOptions(cout);
             
         }

     }

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





