#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    // Loop through the entire array
    for (int i = 0; i < size; i++) {
        // Check if current element matches the target
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int size, target;

    // Ask user for the size of the array
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Ask user for the element to search
    cout << "Enter the element to search for: ";
    cin >> target;

    // Call the search function
    int result = linearSearch(arr, size, target);

    // Display the final result
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
