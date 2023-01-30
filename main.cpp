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
     WheelOfFortune wheel;

     wheel.printOptions(cout);
     wheel.readFile("../WOFPhrases.csv");
     wheel.setRandom();



     return 0;
 }
/// Wheel of Fortune: Phrases ///





