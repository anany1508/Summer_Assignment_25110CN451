#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    char ch = 'A'; // Start character

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << ch << " ";
        }
        ch++; // Move to the next character for the next row
        cout << endl; // Move to the next line
    }

    return 0;
}