#include <iostream>
using namespace std;

int main() {
    int rows;

    // Prompt user for the number of rows
    cout << "Enter number of rows: ";
    cin >> rows;

    // Outer loop for handling number of rows
    for (int i = 1; i <= rows; i++) {
        
        // Inner loop for printing the repeated number
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        
        // Move to the next line after printing each row
        cout << endl;
    }

    return 0;
}