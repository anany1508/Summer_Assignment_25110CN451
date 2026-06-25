#include <iostream>
using namespace std;

int main() {
    int rows;

    // Prompting user for input
    cout << "Enter the number of rows: ";
    cin >> rows;

    // Outer loop for the total number of rows
    for (int i = 1; i <= rows; i++) {
        
        // Inner loop to print numbers in each row
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        
        // Move to the next line after completing a row
        cout << endl;
    }

    return 0;
}