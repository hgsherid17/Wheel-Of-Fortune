//
// Created by Hannah Sheridan on 1/27/23.
//
#include "WheelOfFortune.h"
#include <ostream>

using namespace std;
/**
 * Word guessing game
 * Will expand to add wheel and prizes
 */
 int main() {
     // Make object
     WheelOfFortune player;

     // Initialize balance
     int balance = 0;
     string phrase;
     string category;
     string input;

     // Start game?
     cout << "<><><><><><><><><><><><><><>" << endl;
     cout << "Welcome to Wheel of Fortune!" << endl;
     cout << "<><><><><><><><><><><><><><>" << endl;

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


     }
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





