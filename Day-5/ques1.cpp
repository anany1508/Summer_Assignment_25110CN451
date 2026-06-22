#include <iostream>
using namespace std;

// Function to check if a number is a perfect number
bool isPerfectNumber(int num) {
    // Perfect numbers must be greater than 0
    if (num <= 0) {
        return false;
    }

    int sum = 0;

    // Loop to find proper divisors up to num / 2
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i; // Add divisor to sum
        }
    }

    // If sum of proper divisors equals the original number
    return (sum == num);
}

int main() {
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    if (isPerfectNumber(number)) {
        cout << number << " is a perfect number." << endl;
    } else {
        cout << number << " is not a perfect number." << endl;
    }

    return 0;
}