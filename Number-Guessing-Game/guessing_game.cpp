#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getHighScore() {
    ifstream file("highscore.txt");
    int score = 0;
    if (file) file >> score;
    return score;
}

void saveHighScore(int score) {
    ofstream file("highscore.txt");
    if (file) file << score;
}

void playGame() {
    srand(time(0));
    int secret = rand() % 100 + 1;
    int guess, attempts = 0;
    int highscore = getHighScore();

    cout << "=== Number Guessing Game ===" << endl;
    cout << "Guess a number between 1-100" << endl;

    do {
        cout << "Your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secret) cout << "Too high!" << endl;
        else if (guess < secret) cout << "Too low!" << endl;
    } while (guess != secret);

    cout << "Correct! You won in " << attempts << " attempts!" << endl;
    
    if (attempts < highscore || highscore == 0) {
        saveHighScore(attempts);
        cout << "🎉 New high score!" << endl;
    }
}

int main() {
    while (true) {
        playGame();
        
        char choice;
        cout << "Play again? (y/n): ";
        cin >> choice;
        if (tolower(choice) != 'y') break;
    }
    return 0;
}