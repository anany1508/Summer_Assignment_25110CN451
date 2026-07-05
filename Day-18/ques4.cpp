#include <iostream>
#include <algorithm> // Required for std::sort
#include <functional> // Required for std::greater

int main() {
    // Initialize a C-style array with unsorted elements
    int arr[] = {15, 3, 89, 42, 7, 21, 0};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // Sort the array in descending order
    // Passing std::greater<int>() changes the default ascending behavior to descending
    std::sort(arr, arr + n, std::greater<int>());

    std::cout << "Sorted array (Descending): ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
