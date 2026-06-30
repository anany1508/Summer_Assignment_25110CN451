#include <iostream>
using namespace std;

int main() {
    int size;

    // Get array size from user
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    int even_count = 0;
    int odd_count = 0;

    // Input array elements
    cout << "Enter " << size << " elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Count even and odd elements
    for (int i = 0; i < size; i++) {
        // A number is even if it is completely divisible by 2
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    // Display the results
    cout << "\nTotal Even elements: " << even_count << endl;
    cout << "Total Odd elements: " << odd_count << endl;

    return 0;
}
