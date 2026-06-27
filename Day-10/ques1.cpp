#include <iostream>
using namespace std;

int main() {
    int rows = 5;
    for (int i = 1; i <= rows; ++i) {
        // Print leading spaces
        for (int space = 1; space <= rows - i; ++space) {
            cout << " ";
        }
        // Print stars
        for (int star = 1; star <= 2 * i - 1; ++star) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
