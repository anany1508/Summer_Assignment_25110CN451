#include <iostream>
#include <cmath>

using namespace std;

// Function to find the largest prime factor
long long getLargestPrimeFactor(long long n) {
    long long maxPrime = -1;

    // Divide out all the factors of 2
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    // Check for odd factors starting from 3 up to sqrt(n)
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }

    // If n is still greater than 2, the remaining n must be prime
    if (n > 2) {
        maxPrime = n;
    }

    return maxPrime;
}

int main() {
    long long number;
    
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number <= 1) {
        cout << "Numbers less than or equal to 1 do not have prime factors." << endl;
    } else {
        long long result = getLargestPrimeFactor(number);
        cout << "The largest prime factor of " << number << " is: " << result << endl;
    }

    return 0;
}
