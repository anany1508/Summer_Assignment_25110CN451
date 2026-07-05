#include <iostream>
using namespace std;

// Function that performs binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // Prevents potential integer overflow compared to (low + high) / 2
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; 
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        } 
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    // Element was not present in the array
    return -1;
}

int main() {
    // Array must be sorted for binary search to work properly
    int myNumbers[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(myNumbers) / sizeof(myNumbers[0]);
    int target = 23;

    int result = binarySearch(myNumbers, size, target);

    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
