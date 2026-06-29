#include <iostream>
using namespace std;

// Function to check if a number is a perfect number
bool isPerfect(int number) {
    if (number <= 1) {
        return false;
    }

    int sum = 0;

    // Find all proper divisors and add them together
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    // Return true if the sum of divisors equals the original number
    return (sum == number);
}

int main() {
    int inputNumber;

    cout << "Enter a positive integer: ";
    cin >> inputNumber;

    // Call the function and display the result
    if (isPerfect(inputNumber)) {
        cout << inputNumber << " is a perfect number.\n";
    } else {
        cout << inputNumber << " is not a perfect number.\n";
    }

    return 0;
}
