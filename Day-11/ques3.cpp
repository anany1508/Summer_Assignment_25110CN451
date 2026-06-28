#include <iostream>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // 0 and 1 are not prime numbers
    if (n <= 1) {
        return false;
    }
    
    // Check for factors from 2 up to the square root of n
    // i * i <= n is more efficient than calling sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Found a factor, so it's not prime
        }
    }
    
    return true; // No factors found, it's prime
}

int main() {
    int number;
    
    cout << "Enter a positive integer: ";
    cin >> number;
    
    // Call the function and display the result
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }
    
    return 0;
}
