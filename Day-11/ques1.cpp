#include <iostream>
using namespace std;

// Function to find the sum of two numbers
int findSum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int a, b, sum;

    // Taking user input
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    // Calling the function and storing the result
    sum = findSum(a, b);

    // Displaying the result
    cout << "The sum of " << a << " and " << b << " is: " << sum << endl;

    return 0;
}
