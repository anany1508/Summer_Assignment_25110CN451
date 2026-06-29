#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int number) {
    int originalNumber = number;
    int temp = number;
    int digits = 0;
    int sum = 0;

    // Step 1: Count the total number of digits
    while (temp > 0) {
        temp /= 10;
        digits++;
    }

    temp = number;

    // Step 2: Calculate the sum of individual digits raised to the power of total digits
    while (temp > 0) {
        int remainder = temp % 10;
        sum += round(pow(remainder, digits)); // round() handles floating-point inaccuracies
        temp /= 10;
    }

    // Step 3: Compare the calculated sum with the original number
    return (sum == originalNumber);
}

int main() {
    int inputNumber;

    cout << "Enter a positive integer: ";
    cin >> inputNumber;

    // Call the function and display the result
    if (isArmstrong(inputNumber)) {
        cout << inputNumber << " is an Armstrong number.\n";
    } else {
        cout << inputNumber << " is not an Armstrong number.\n";
    }

    return 0;
}

