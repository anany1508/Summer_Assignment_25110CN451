#include <iostream>

using namespace std;

// Recursive function to find the nth Fibonacci number
int fibonacci(int n) {
    // Base case: return 0 for n=0, and 1 for n=1
    if (n <= 1) {
        return n;
    }
    // Recursive case: sum of the two preceding numbers
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int terms;

    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> terms;

    // Validate user input
    if (terms <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    cout << "Fibonacci Series: ";
    for (int i = 0; i < terms; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}