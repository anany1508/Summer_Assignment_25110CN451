#include <iostream>
#include <algorithm> // Required for std::reverse

// Function to left rotate an array by d positions
void leftRotate(int arr[], int d, int n) {
    // Handle cases where d is greater than the array size
    d = d % n; 
    
    // Step 1: Reverse the first d elements
    std::reverse(arr, arr + d);
    
    // Step 2: Reverse the remaining n-d elements
    std::reverse(arr + d, arr + n);
    
    // Step 3: Reverse the entire array
    std::reverse(arr, arr + n);
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
    int d = 2; // Number of positions to rotate left

    std::cout << "Original Array: ";
    printArray(arr, n);

    leftRotate(arr, d, n);

    std::cout << "Left Rotated Array (by " << d << " places): ";
    printArray(arr, n);

    return 0;
}
