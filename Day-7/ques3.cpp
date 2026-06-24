#include <iostream>

// Recursive function to calculate the sum of digits
int sumOfDigits(int n) {
    // Base case: if the number becomes 0, stop recursion
    if (n == 0) {
        return 0;
    }
    
    // Recursive case: extract the last digit (n % 10) 
    // and add it to the sum of the remaining digits (n / 10)
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int number;
    
    std::cout << "Enter an integer: ";
    std::cin >> number;
    
    // Handle negative numbers by converting them to positive
    int absoluteNumber = std::abs(number);
    
    int result = sumOfDigits(absoluteNumber);
    
    std::cout << "The sum of digits of " << number << " is: " << result << std::endl;
    
    return 0;
}