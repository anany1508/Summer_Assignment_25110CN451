#include <iostream>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()

using namespace std;

int main() {
    // Seed the random number generator using the current system time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    cout << "=========================================" << endl;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;
    cout << "=========================================" << endl;

    // Game loop continues until the user guesses the correct number
    do {
        cout << "\nEnter your guess: ";
        cin >> userGuess;
        attempts++;

        // Provide feedback based on the user's guess
        if (userGuess > secretNumber) {
            cout << "Too high! Try a lower number.";
        } else if (userGuess < secretNumber) {
            cout << "Too low! Try a higher number.";
        } else {
            cout << "\nCongratulations! You guessed the correct number!" << endl;
            cout << "It took you " << attempts << " attempts." << endl;
        }

    } while (userGuess != secretNumber);

    return 0;
}
