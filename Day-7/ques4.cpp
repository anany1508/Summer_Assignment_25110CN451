#include <iostream>

using namespace std;

// Recursive function to reverse a number
int reverseNumber(int n, int revNum = 0) {
    // Base case: when all digits are processed
    if (n == 0) {
        return revNum;
    }
    
    // Extract the last digit and append to the reversed number
    revNum = (revNum * 10) + (n % 10);
    
    // Recursive call with the remaining digits
    return reverseNumber(n / 10, revNum);
}

int main() {
    int num;
    
    cout << "Enter an integer: ";
    cin >> num;
    
    int reversed = reverseNumber(num);
    
    cout << "Reversed number: " << reversed << endl;
    
    return 0;
}
