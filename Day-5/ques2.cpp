#include <iostream>
using namespace std;

// Function to calculate the factorial of a single digit
int getFactorial(int digit) {
    int fact = 1;
    for (int i = 1; i <= digit; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num, originalNum, rem;
    int sum = 0;

    // Request input from the user
    cout << "Enter a number to check: ";
    cin >> num;

    // Save the original number for the final comparison
    originalNum = num;

    // Process every single digit of the number
    while (num > 0) {
        rem = num % 10;          // Extract the last digit
        sum += getFactorial(rem); // Add its factorial to the sum
        num = num / 10;          // Remove the last digit
    }

    // Determine and display if the number is a Strong Number
    if (sum == originalNum) {
        cout << originalNum << " is a Strong Number." << endl;
    } else {
        cout << originalNum << " is not a Strong Number." << endl;
    }

    return 0;
}