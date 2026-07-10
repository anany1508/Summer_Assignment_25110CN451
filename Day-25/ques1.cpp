#include <iostream>
using namespace std;

// Function to merge two sorted arrays
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int k = 0; // Pointer for result array

    // Traverse both arrays simultaneously
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Store remaining elements of first array
    while (i < n1) {
        result[k++] = arr1[i++];
    }

    // Store remaining elements of second array
    while (j < n2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Result array to hold merged elements
    int result[n1 + n2];

    mergeSortedArrays(arr1, n1, arr2, n2, result);

    cout << "Merged Sorted Array: ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
