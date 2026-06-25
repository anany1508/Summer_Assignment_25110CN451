#include <iostream>
using namespace std;

int main() {
    int rows;

    // Prompt user for input
    cout << "Enter the number of rows: ";
    cin >> rows;

    // Outer loop handles the number of rows
    for (int i = 1; i <= rows; i++) {
        
        // Inner loop handles the numbers in each row
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        
        // Move to the next line after printing each row
        cout << endl;
    }

    return 0;
}