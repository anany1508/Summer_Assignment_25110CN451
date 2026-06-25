#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    // Outer loop controls the rows
    for (int i = 1; i <= rows; ++i) {
        
        // Inner loop prints the asterisks for each row
        for (int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        
        // Move to the next line after finishing a row
        cout << "\n";
    }

    return 0;
}