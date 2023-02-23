//
// Created by Hannah Sheridan on 2/5/23.
//
#include "WheelOfFortune.h"
#include "Player.h"

WheelOfFortune::WheelOfFortune() {
    phrase = "";
    category = "";
    lettersGuessed = {};
    categories = {};
    phrases = {};

    // Fill players vector
    currentPlayer = 0;
    Player player1("Player 1");
    Player player2("Player 2");
    setPlayers(player1, player2);

    srand(time(NULL));

}

string WheelOfFortune::getPhrase() {
    return this->phrase;
}

string WheelOfFortune::getCategory() {
    return this->category;
}

char WheelOfFortune::getLastGuessed() {
    return (char) toupper(lastGuessed);
}

vector<char> WheelOfFortune::getLettersGuessed() {
    return this->lettersGuessed;
}

vector<string> WheelOfFortune::getPhrases() {
    return this->phrases;
}

vector<string> WheelOfFortune::getCategories(){
    return this->categories;
}

vector<Player> WheelOfFortune::getPlayers() {
    return this->players;
}

void WheelOfFortune::setPhrase (string p) {
    this->phrase = p;
}

void WheelOfFortune::setCategory(string c) {
    this->category = c;
}

void WheelOfFortune::setPlayers(Player player1, Player player2) {
    players.push_back(player1);
    players.push_back(player2);
}

void WheelOfFortune::printGameOptions(ostream& outs) {
    outs << endl << "<><><>Options<><><>" << endl;
    outs << "C - Guess a consonant" << endl << "V - Buy a vowel for $250" << endl << "P - Solve the puzzle!" << endl << "E - Exit game" << endl;
    outs << "<><><><><><><><><><>" << endl << endl;
}

char WheelOfFortune::getOption(ostream& outs, istream& ins) {
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
    return toupper(option[0]);
}

void WheelOfFortune::printRoundOptions(ostream& outs) {
    outs << endl << "<><><>Options<><><>" << endl;
    outs << "S - Spin the wheel!" << endl << "E - Exit game" << endl;
    outs << "<><><><><><><><><><>" << endl << endl;
    outs << "Choose an option: ";
}

bool WheelOfFortune::activePlayer(ostream& outs, istream& ins) {
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

bool WheelOfFortune::readFile(string filename) {
    ifstream inFile;
    inFile.open(filename);

    char comma, quote;

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


    return true;
}

void WheelOfFortune::setRandom() {
    int index = rand() % phrases.size();
    phrase = phrases[index];
    category = categories[index];
}

int WheelOfFortune::guessConsonant(ostream& outs, istream& ins) {
    int guessed = 0;
    bool valid = false;

    string letter;

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
        else if (find(lettersGuessed.begin(), lettersGuessed.end(), toupper(letter[0])) != lettersGuessed.end()) {
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

    for (int i = 0; i < phrase.length(); ++i) {
        if (toupper(phrase[i]) == toupper(letter[0])) {
            ++guessed;
        }
    }

    lastGuessed = letter[0];
    lettersGuessed.push_back((char) toupper(letter[0]));

    return guessed;


}

int WheelOfFortune::guessVowel(ostream& outs, istream& ins) {
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
            cout << "That is not a vowel! Try again: ";
            ins.clear();
            getline(ins, letter);
        }
        else if (find(lettersGuessed.begin(), lettersGuessed.end(), toupper(letter[0])) != lettersGuessed.end()) {
            valid = false;
            cout << "You have already guessed that letter! Try again: ";
            ins.clear();
            getline(ins, letter);
        }
        else {
            valid = true;
        }

    }

    for (int i = 0; i < phrase.length(); ++i) {
        if (toupper(phrase[i]) == toupper(letter[0])) {
            guessed++;
        }
    }
    lastGuessed = letter[0];
    lettersGuessed.push_back((char) toupper(letter[0]));
    return guessed;

}

void WheelOfFortune::printPhrase(ostream& outs) {
    int length = 0;
    /*
    outs << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    outs << "<>                                                      <>" << endl;*/
    //outs << "            ";
    //outs << setw(53) << left;
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
        ++length;
    }

    outs << endl;
    outs  << "<><><> " << category << " <><><>" << endl;
    printLettersGuessed(outs);
    /*
    outs << endl << "<>                                                      <>" << endl;
    outs << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;*/
}

void WheelOfFortune::printLettersGuessed(ostream& outs) {
    // Print ascii values of 65-90
    outs << endl;
    outs << "            --------------------------" << endl;
    outs << "            ";
    for (int alpha = 65; alpha <= 90; ++alpha) {
        if (find(lettersGuessed.begin(), lettersGuessed.end(), alpha) != lettersGuessed.end()) {
            outs << ":: ";
        }
        else {
            outs << char(alpha) << " ";
        }
        if (alpha == 77) {
            outs << endl << "            ";
        }
    }
    outs << endl << "            --------------------------";
    outs << endl;
}
/*
int WheelOfFortune::spinWheel() {
    int prizeIndex = rand() % wheel.size();
    int prize = wheel[prizeIndex];

    return prize;
}
*/
bool WheelOfFortune::solvePuzzle(string guess) {
    int flag = 0;

    for (int i = 0; i < phrase.size(); ++i) {
        if (toupper(phrase[i]) == toupper(guess[i])) {
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

bool WheelOfFortune::guessedPhrase() {
    int flag = 0;
    for (int i = 0; i < phrase.length(); ++i) {
        if (!isalpha(phrase[i])) {
            ++flag;
        }
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

bool WheelOfFortune::playAgain(ostream& outs, istream& ins) {
    string ans;
    outs << "Play again? (y/n) ";
    getline(ins, ans);

    while (ans.length() != 1 || toupper(ans[0]) != 'Y' && toupper(ans[0]) != 'N') {
        outs << "Invalid input. Please type y or n: " << endl;
        ins.clear();
        getline(ins, ans);
    }

    if (toupper(ans[0]) == 'Y') {
        lettersGuessed = {};
        return true;
    }
    else {
        return false;
    }
}

void WheelOfFortune::switchPlayers() {
    if (currentPlayer == 0) {
        ++currentPlayer;
    }
    else if (currentPlayer == 1){
        --currentPlayer;
    }
    else {
        currentPlayer = 0;
    }

}

Player WheelOfFortune::getCurrentPlayer() {
    return players[currentPlayer];
}


