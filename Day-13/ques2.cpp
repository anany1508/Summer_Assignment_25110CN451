#include <iostream>
using namespace std;

int main() {
    int n;
    double sum = 0.0, average;

    // Ask user for the size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    // Check for edge case of 0 or negative size
    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    double arr[n]; // Create an array of size n

    // Input array elements from user
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i]; // Keep adding elements to get the sum
    }

    // Calculate average
    average = sum / n;

    // Display the output
    cout << "\nSum of array elements = " << sum << endl;
    cout << "Average of array elements = " << average << endl;

    return 0;
}
