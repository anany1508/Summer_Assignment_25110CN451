#include <iostream>

void findSortedUnion(int arr1[], int n1, int arr2[], int n2) {
    int i = 0, j = 0;

    std::cout << "Union of the two sorted arrays: ";
    while (i < n1 && j < j) {
        // Skip duplicate elements in the first array
        while (i > 0 && i < n1 && arr1[i] == arr1[i - 1]) {
            i++;
        }
        // Skip duplicate elements in the second array
        while (j > 0 && j < n2 && arr2[j] == arr2[j - 1]) {
            j++;
        }

        // If bounds exceeded after skipping duplicates, break loop
        if (i >= n1 || j >= n2) {
            break;
        }

        if (arr1[i] < arr2[j]) {
            std::cout << arr1[i++] << " ";
        } else if (arr2[j] < arr1[i]) {
            std::cout << arr2[j++] << " ";
        } else {
            std::cout << arr1[i] << " ";
            i++;
            j++;
        }
    }

    // Print remaining elements of arr1
    while (i < n1) {
        if (i == 0 || arr1[i] != arr1[i - 1]) {
            std::cout << arr1[i] << " ";
        }
        i++;
    }

    // Print remaining elements of arr2
    while (j < n2) {
        if (j == 0 || arr2[j] != arr2[j - 1]) {
            std::cout << arr2[j] << " ";
        }
        j++;
    }
    std::cout << std::endl;
}

int main() {
    int arr1[] = {1, 2, 2, 3, 5};
    int arr2[] = {2, 3, 4, 5, 6};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    findSortedUnion(arr1, n1, arr2, n2);

    return 0;
}
