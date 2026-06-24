#include <iostream>
using namespace std;
// Recursive function to calculate factorial
// Using 'unsigned long long' to handle larger results safely
unsigned long long factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: n! = n * (n - 1)!
    return n * factorial(n - 1);
}

int main() {
    int num;

    cout << "Enter a non-negative integer: ";
    cin >> num;

    // Validate input for negative numbers
    if (num < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        std::cout << "Factorial of " << num << " is " << factorial(num) << std::endl;
    }

    return 0;
}