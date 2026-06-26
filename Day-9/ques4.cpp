#include <iostream>
using namespace std;

int main() {
    int size;

    // Ask user for the size of the square
    cout << "Enter the size of the square: ";
    cin >> size;

    // Outer loop for rows
    for (int i = 0; i < size; i++) {
        // Inner loop for columns
        for (int j = 0; j < size; j++) {
            // Print star for the border elements
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                cout << "* ";
            } else {
                // Print space for inner elements
                cout << "  "; 
            }
        }
        // Move to the next line after completing a row
        cout << endl;
    }

    return 0;
}
