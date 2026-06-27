#include <iostream>
using namespace std;

int main() {
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    int i = 1; // Tracks current row
    while (i <= rows) {
        
        // Loop 1: Prints leading spaces for centering
        int j = 1;
        while (j <= rows - i) {
            cout << "  "; 
            j++;
        }

        // Loop 2: Prints increasing numbers starting from 1
        int num = 1;
        int k = 1;
        while (k <= i) {
            cout << num << " ";
            num++;
            k++;
        }

        // Loop 3: Prints decreasing numbers back down to 1
        num -= 2; 
        int l = 1;
        while (l < i) {
            cout << num << " ";
            num--;
            l++;
        }

        // Move to the next line
        cout << endl;
        i++;
    }

    return 0;
}
