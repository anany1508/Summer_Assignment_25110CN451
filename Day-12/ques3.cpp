#include <iostream>
using namespace std;

// Function to print Fibonacci sequence up to N terms
void printFibonacci(int terms) {
    int t1 = 0;
    int t2 = 1;
    int nextTerm = 0;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= terms; ++i) {
        // Print the first two terms as they are
        if(i == 1) {
            cout << t1 << " ";
            continue;
        }
        if(i == 2) {
            cout << t2 << " ";
            continue;
        }
        
        // Calculate and print subsequent terms
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << " ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter the number of terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer greater than 0." << endl;
    } else {
        // Call the function
        printFibonacci(n);
    }

    return 0;
}
