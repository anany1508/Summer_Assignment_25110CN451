#include <iostream>
using namespace std;

// Function to perform an optimized Bubble Sort
void bubbleSort(int arr[], int size) {
    // Loop for each pass through the array
    for (int step = 0; step < size - 1; ++step) {
        // Track if any swapping happens in this pass
        bool swapped = false;
        
        // Loop to compare adjacent elements
        for (int i = 0; i < size - step - 1; ++i) {
            // Change > to < to sort in descending order
            if (arr[i] > arr[i + 1]) {
                // Swap elements using built-in C++ swap
                swap(arr[i], arr[i + 1]);
                swapped = true; 
            }
        }
        
        // If no elements were swapped, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to print the array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);
    
    cout << "Original array:\n";
    printArray(data, size);
    
    // Call the bubble sort function
    bubbleSort(data, size);
    
    cout << "Sorted array in ascending order:\n";
    printArray(data, size);
    
    return 0;
}
