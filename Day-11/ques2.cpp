#include <iostream>
using namespace std;

// Custom function to find the maximum of two numbers
int findMaximum(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    int a = 25;
    int b = 40;

    // Call the custom function
    int maxVal = findMaximum(a, b);

    cout << "The maximum value is: " << maxVal << endl;

    return 0;
}
