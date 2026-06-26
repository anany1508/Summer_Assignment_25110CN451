#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    // Outer loop controls the rows, counting down
    for (int i = rows; i >= 1; --i) {
        
        // Inner loop prints stars equal to the current row number
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        
        // Move to the next line
        cout << endl;
    }

    return 0;
}
