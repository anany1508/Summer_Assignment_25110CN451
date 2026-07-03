#include <iostream>
#include <unordered_set>

// Function to remove duplicates and return the new size
int removeDuplicates(int arr[], int n) {
    std::unordered_set<int> seen;
    int index = 0; // Tracks the position of unique elements

    for (int i = 0; i < n; i++) {
        // If the element is not found in the set, it is unique
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            arr[index++] = arr[i]; // Move it to the front
        }
    }
    return index; // New logical size of the array
}

int main() {
    int arr[] = {4, 5, 4, 2, 8, 5, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    // Remove duplicates
    int newSize = removeDuplicates(arr, n);

    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}
