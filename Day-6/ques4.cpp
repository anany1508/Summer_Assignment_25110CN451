#include <iostream>
using namespace std;

int main() {
    int x, n;
    long long result = 1; // Stores the final answer

    // Take user input
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter power (n): ";
    cin >> n;

    // Calculate x^n using a simple loop
    for (int i = 0; i < n; i++) {
        result = result * x;
    }

    // Output the result
    cout << x << " raised to the power of " << n << " is: " << result << endl;

    return 0;
}
