//
// Created by Hannah Sheridan on 1/27/23.
//
#include "WheelOfFortune.h"
#include <ostream>
#include <iostream>
#include <string>

using namespace std;
/**
 * TODO
 * Fix Exit in game options
 * Fix play again
 * could put opption at the end of the while loop and set option to C to start so if C > 0, jumps right to C in switch statement
 *
 */
/**
 * Word guessing game
 * Will expand to add wheel and prizes
 */
 int main() {
     // Make object
     int balance = 0;
     bool solved = false;
     bool playing = true;
     bool round = false;
     int consonants = 0;
     int vowels = 0;
     char option = 'C';
     int prize;

     WheelOfFortune player;
     player.readFile("../WOFPhrases.csv");
     cout << "Welcome to Wheel of Fortune!" << endl;

     player.printPhrase(cout);
     cout << player.getPhrase() << endl;

     playing = player.activePlayer(cout, cin);

     while(playing){
         cout << endl << "Spinning the wheel..." << endl;
         prize = player.spinWheel();
         player.printPhrase(cout);
         cout << endl << "Your prize: $" << prize << endl;
         cout << "Balance: $" << balance << endl;
         consonants = player.guessConsonant(cout, cin);
         player.printPhrase(cout);

         if (consonants > 1) {
             cout << "There are " << consonants << " " << player.getLastGuessed() << "'s!" << endl;
             balance += (consonants * prize);
             cout << "New balance: $" << balance << endl;
             round = true;
         }
         else if (consonants == 1) {
             cout << "There is " << consonants << " " << player.getLastGuessed() << "!" << endl;
             balance += prize;
             cout << "New balance: $" << balance << endl;
             round = true;
         }
         else {
             cout << "Sorry, there are no " << player.getLastGuessed() << "'s in this puzzle!" << endl;
             round = false;
         }

         while (round) {
             option = player.getOption(cout, cin);
             switch(option) {
                 case 'C': {
                     round = false;
                     break;
                 }
                 case 'V': {
                     if (balance > 250) {
                         balance -= 250;
                         vowels = player.guessVowel(cout, cin);
                         player.printPhrase(cout);
                         if (vowels > 1) {
                             cout << "There are " << vowels << " " << player.getLastGuessed() << "'s!" << endl;
                         } else if (vowels == 1) {
                             cout << "There is " << vowels << " " << player.getLastGuessed() << "! " << endl;
                         } else {
                             cout << "Sorry, there are no " << player.getLastGuessed() << "'s in this puzzle!" << endl;

                             round = false;
                             //playing = player.activePlayer(cout, cin);
                         }
                         break;
                     }
                     while (balance < 250) {
                         cout << "Sorry, you do not have enough money to buy a vowel!" << endl;
                         option = player.getOption(cout, cin);
                         break;
                     }
                 }
                 case 'P': {
                     string guess;
                     cout << "Solve the puzzle: ";
                     getline(cin, guess);
                     //player.solvePuzzle(guess);
                     if ((player.solvePuzzle(guess))) {
                         player.printPhrase(cout);
                         cout << "Congratulations, you solved the puzzle!" << endl;
                         round = false;
                         solved = true;
                     }
                     else {
                         cout << "Sorry, you did not solve the puzzle. Guess more letters and try again!" << endl;
                         round = false;
                         break;
                     }
                 }
                 case 'E' : {
                     round = false;
                     playing = false;
                     option = 'C';
                 }
             }

         }

         if (solved){
             option = 'C';
             playing = player.playAgain(cout, cin);
             if (playing) {
                 solved = false;
                 player.readFile("../WOFPhrases.csv");
             }
         }
         if (option != 'C') {
             playing = player.activePlayer(cout, cin);
         }

     }

     // While playing
        // Guess consonant
        // If consonants = true
        //

     /*
     while (playing && !solved) {
         cout << endl << "Spinning the Wheel... " << endl;
         int prize = player.spinWheel();
         player.printPhrase(cout);
         cout << endl << "Your prize: $" << prize << endl;
         cout << "Current balance: $" << balance << endl;

         consonants = player.guessConsonant(cout, cin);

         if (consonants == 0) {
             player.printPhrase(cout);
             cout << "Sorry, there are no " << (char) toupper(player.getLastGuessed()) << "'s in this puzzle!" << endl;
             cout << "Balance: $" << balance << endl;
         }
         while (consonants > 0) {
             option = 'C';
             //balance += (consonants * prize);
             //player.printPhrase(cout);

             if (consonants == 1) {
                 cout << "There is " << consonants << " " << (char) toupper(player.getLastGuessed()) << "!" << endl;
             }
             else {
                 cout << "There are " << consonants << " " << (char) toupper(player.getLastGuessed()) << "'s!" << endl;
             }

             cout << "New balance: $" << balance << endl;

             while (option != 'E') {
                 option = player.getOption(cout, cin);
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
                                 //option = 'E';
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
                            break;
                         }
                         //option = 'E';
                         //break;
                     }
                     case 'C': {
                         balance += (consonants * prize);

                         consonants = player.guessConsonant(cout, cin);
                         player.printPhrase(cout);

                         if (consonants == 1) {
                             cout << "There is " << consonants << " " << (char) toupper(player.getLastGuessed()) << "!" << endl;
                             option = player.getOption(cout, cin);
                         }
                         else if (consonants > 1) {
                             cout << "There are " << consonants << " " << (char) toupper(player.getLastGuessed()) << "'s!" << endl;
                             option = player.getOption(cout, cin);
                         }
                         else {
                             cout << "Sorry, there are no " << (char) toupper(player.getLastGuessed()) << "'s in this puzzle!" << endl;
                             break;
                         }
                     }
                     case 'E': {
                         playing = false;
                         solved = true;
                         option = 'C';
                         break;
                     }
                 }

             }
         }

         if (option == 'E') {
             playing = false;
             solved = true;
         }
         if (player.guessedPhrase()) {
             cout << "You solved the puzzle!" << endl;
             player.printPhrase(cout);
             playing = player.playAgain(cout, cin);
         }

         if (playing) {
             playing = player.activePlayer(cout, cin);
         }

     }*/
     cout << "Thank you for playing! See you later :)" << endl;
     cout << "Final balance: $" << balance << endl;
     
     return 0;
 }
/// Wheel of Fortune: Phrases ///





