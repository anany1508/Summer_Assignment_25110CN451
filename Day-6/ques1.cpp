#include <iostream>
using namespace std;

void convertDecimalToBinary(int n) {
    // Handle the edge case where the input number is 0
    if (n == 0) {
        cout << "0" << endl;
        return;
    }

    int binaryArray[32]; // Array to store binary digits (32 bits max for int)
    int i = 0;

    // Extract remainders and divide by 2
    while (n > 0) {
        binaryArray[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Printing the array in reverse order to get correct binary sequence
    for (int j = i - 1; j >= 0; j--) {
        cout << binaryArray[j];
    }
    cout << endl;
}

int main() {
    int decimalNumber;
    cout << "Enter a positive decimal number: ";
    cin >> decimalNumber;

    cout << "Binary equivalent: ";
    convertDecimalToBinary(decimalNumber);

    return 0;
}