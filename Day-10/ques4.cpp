#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter number of rows (1-26): ";
    cin >> rows;

    int i = 1; // Tracks current row
    while (i <= rows) {
        
        // Loop 1: Prints leading spaces for centering
        int j = 1;
        while (j <= rows - i) {
            cout << "  "; 
            j++;
        }

        // Loop 2: Prints increasing characters starting from 'A'
        char ch = 'A';
        int k = 1;
        while (k <= i) {
            cout << ch << " ";
            ch++;
            k++;
        }

        // Loop 3: Prints decreasing characters back down to 'A'
        ch -= 2; 
        int l = 1;
        while (l < i) {
            cout << ch << " ";
            ch--;
            l++;
        }

        // Move to the next line
        cout << endl;
        i++;
    }

    return 0;
}
