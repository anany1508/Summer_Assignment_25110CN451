#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    // Outer loop for the rows (counting down)
    for (int i = rows; i >= 1; i--) {
        // Inner loop to print numbers from 1 to i
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        // Move to the next line after completing a row
        cout << endl;
    }

    return 0;
}
