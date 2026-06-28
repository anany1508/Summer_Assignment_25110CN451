#include <iostream>
using namespace std;

// Function to calculate factorial
unsigned long long findFactorial(int n) {
    if (n < 0) {
        return 0; // Factorial for negative numbers is not defined
    }
    
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (num < 0) {
        cout << "Error: Factorial of a negative number does not exist." << endl;
    } else {
        cout << "Factorial of " << num << " = " << findFactorial(num) << endl;
    }

    return 0;
}
