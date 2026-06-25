#include <iostream>
using namespace std;

int main() {
    int rows;

    // Get the number of rows from the user
    cout << "Enter number of rows: ";
    cin >> rows;

    // Outer loop handles the number of rows
    for (int i = 1; i <= rows; ++i) {
        
        // Inner loop handles the number of columns in each row
        for (int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        
        // Move to the next line after printing each row
        cout << "\n";
    }

    return 0;
}