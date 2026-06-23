#include <iostream>
#include <cmath> // Required for the pow() function

using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(long long n) {
    int decimalNumber = 0;
    int i = 0;
    long long remainder;

    while (n != 0) {
        remainder = n % 10;          // Extract the last digit
        n /= 10;                     // Remove the last digit
        decimalNumber += remainder * pow(2, i); // Multiply by 2^i and add to sum
        ++i;                         // Move to the next power of 2
    }
    
    return decimalNumber;
}

int main() {
    long long binaryNumber;
    
    cout << "Enter a binary number (e.g., 1010): ";
    cin >> binaryNumber;
    
    cout << "Decimal equivalent: " << binaryToDecimal(binaryNumber) << endl;
    
    return 0;
}