#include <iostream>
using namespace std;

int main() {
    int num;

    // Prompt the user for input
    cout << "Enter a positive integer: ";
    cin >> num;

    // Check if the input is valid
    if (num <= 0) {
        cout << "Please enter a number greater than 0." << endl;
        return 1; 
    }

    cout << "Factors of " << num << " are: ";
    
    // Loop through all numbers from 1 to num
    for (int i = 1; i <= num; ++i) {
        // If num is perfectly divisible by i, then i is a factor
        if (num % i == 0) {
            cout << i << " ";
        }
    }
    
    cout << endl;
    return 0;
}