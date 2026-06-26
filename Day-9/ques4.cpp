#include <iostream>
using namespace std;

int main() {
    int side;

    cout << "Enter the side length of the square: ";
    cin >> side;

    // Outer loop for rows
    for (int i = 0; i < side; i++) {
        // Inner loop for columns
        for (int j = 0; j < side; j++) {
            // Print star for the boundary coordinates
            if (i == 0 || i == side - 1 || j == 0 || j == side - 1) {
                cout << "* ";
            } else {
                // Print space for the hollow interior
                cout << "  "; // Two spaces to match the "* " formatting
            }
        }
        // Move to the next line after completing a row
        cout << endl;
    }

    return 0;
}
