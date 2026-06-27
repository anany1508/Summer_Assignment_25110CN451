#include <iostream>
using namespace std;

int main() {
    int rows;

    // Get user input for the number of rows
    cout << "Enter number of rows: ";
    cin >> rows;

    // Outer loop to handle the number of rows
    for(int i = 1; i <= rows; i++) {
        
        // 1. Inner loop to print leading spaces
        for(int j = 1; j < i; j++) {
            cout << " ";
        }

        // 2. Inner loop to print stars (*)
        // Total stars in row 'i' = (total rows * 2) - (2 * i - 1)
        for(int j = 1; j <= (rows * 2 - (2 * i - 1)); j++) {
            cout << "*";
        }

        // Move to the next line after printing each row
        cout << "\n";
    }

    return 0;
}

