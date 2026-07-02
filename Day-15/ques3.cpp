#include <iostream>
#include <algorithm> // Required for std::swap

// Function to reverse a section of the array from start index to end index
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to right rotate the array by k positions
void rightRotate(int arr[], int n, int k) {
    // Handle cases where k is greater than the size of the array
    k = k % n;
    
    // Step 1: Reverse the first n-k elements
    reverseArray(arr, 0, n - k - 1);
    
    // Step 2: Reverse the last k elements
    reverseArray(arr, n - k, n - 1);
    
    // Step 3: Reverse the whole array
    reverseArray(arr, 0, n - 1);
}

// Helper function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Number of positions to rotate right

    std::cout << "Original Array: ";
    printArray(arr, n);

    rightRotate(arr, n, k);

    std::cout << "Right Rotated Array by " << k << " places: ";
    printArray(arr, n);

    return 0;
}
