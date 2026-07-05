#include <iostream>

// Function to perform Insertion Sort on an array
void insertionSort(int arr[], int size) {
    // Start from the second element (index 1) as a single element is already sorted
    for (int i = 1; i < size; i++) {
        int key = arr[i]; // The element to be positioned
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Place the key at its correct position
        arr[j + 1] = key;
    }
}

// Function to print the array elements
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, size);

    // Call the sorting function
    insertionSort(arr, size);

    std::cout << "Sorted array:   ";
    printArray(arr, size);

    return 0;
}
