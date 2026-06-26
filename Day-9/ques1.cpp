#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    // Outer loop for rows (starts from maximum rows and counts down)
    for (int i = rows; i >= 1; i--) {
        // Inner loop to print stars for the current row
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        // Move to the next line after completing a row
        cout << endl;
    }

    return 0;
}
