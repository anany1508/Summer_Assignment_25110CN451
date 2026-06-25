#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    // Outer loop for the number of rows
    for (int i = 1; i <= rows; i++) {
        char ch = 'A'; // Start character for each row
        
        // Inner loop to print characters in each row
        for (int j = 1; j <= i; j++) {
            cout << ch << " ";
            ch++; // Move to the next character
        }
        cout << endl; // Move to the next line
    }
    return 0;

} 