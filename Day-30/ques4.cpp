#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Global Constants
const int ROWS = 5;
const int COLS = 5;

// Function to display the available movies
void displayMovies(const string movies[], int size) {
    cout << "\n--- NOW SHOWING ---" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << movies[i] << endl;
    }
}

// Function to initialize the seat matrix to 'O' (Open)
void initializeSeats(char seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            seats[i][j] = 'O';
        }
    }
}

// Function to display the seating arrangement using Array indices
void displaySeats(char seats[ROWS][COLS]) {
    cout << "\n  Seat Map (O = Open, X = Booked):" << endl;
    cout << "  A B C D E" << endl;
    for (int i = 0; i < ROWS; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < COLS; ++j) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to book tickets
void bookTickets(char seats[ROWS][COLS]) {
    int row;
    char colChar;
    
    cout << "\nEnter Row Number (1-" << ROWS << "): ";
    cin >> row;
    cout << "Enter Column Letter (A-E): ";
    cin >> colChar;

    // String function: Convert input to uppercase
    colChar = toupper(colChar);
    int col = colChar - 'A';

    // Validation
    if (row >= 1 && row <= ROWS && col >= 0 && col < COLS) {
        if (seats[row - 1][col] == 'O') {
            seats[row - 1][col] = 'X';
            cout << "Success! Seat " << row << colChar << " booked." << endl;
        } else {
            cout << "Error: Seat " << row << colChar << " is already booked!" << endl;
        }
    } else {
        cout << "Error: Invalid seat selection." << endl;
    }
}

int main() {
    // Array of Strings
    string movies[3] = {"The Galactic Adventure", "Mystery of the Code", "Comedy Night"};
    char seating[ROWS][COLS];
    initializeSeats(seating);

    int choice;
    string customerName;

    cout << "Welcome to the C++ Cinema!" << endl;
    
    // String Function: Get a line of text for user details
    cout << "Please enter your name: ";
    getline(cin, customerName);

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. View Movies" << endl;
        cout << "2. View Available Seats" << endl;
        cout << "3. Book a Ticket" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayMovies(movies, 3);
                break;
            case 2:
                displaySeats(seating);
                break;
            case 3:
                displaySeats(seating);
                bookTickets(seating);
                break;
            case 4:
                cout << "\nThank you for using C++ Cinema, " << customerName << "! Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
