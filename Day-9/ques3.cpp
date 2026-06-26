#include <iostream>
using namespace std;

int main() {
    int rows;
    char startChar = 'A';

    cout << "Enter the number of rows: ";
    cin >> rows;

    // Outer loop for the number of rows
    for (int i = 0; i < rows; i++) {
        // Inner loop to repeat the character in each column
        for (int j = 0; j <= i; j++) {
            cout << startChar << " ";
        }
        // Move to the next line after printing a row
        cout << "\n"; 
        
        // Increment the character for the next row
        startChar++; 
    }

    return 0;
}
