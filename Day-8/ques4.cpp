#include <iostream>
using namespace std;

int main() {
    int rows;

    // Get the number of rows from the user
    cout << "Enter the number of rows: ";
    cin >> rows;

    // Outer loop for the total number of rows
    for (int i = 1; i <= rows; i++) {
        
        // Inner loop to print the row number 'i', repeated 'i' times
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        
        // Move to the next line after completing a row
        cout << endl;
    }

    return 0;
}