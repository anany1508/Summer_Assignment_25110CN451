#include <iostream>
using namespace std;

int main() {
    int arr1[50], arr2[50], mergedArr[100];
    int size1, size2, i, k;

    // Input for the first array
    cout << "Enter size of the first array: ";
    cin >> size1;
    cout << "Enter " << size1 << " elements: ";
    for (i = 0; i < size1; i++) {
        cin >> arr1[i];
        mergedArr[i] = arr1[i]; // Copy directly to the merged array
    }

    // Set index pointer for the remaining slots in the merged array
    k = size1; 

    // Input for the second array
    cout << "\nEnter size of the second array: ";
    cin >> size2;
    cout << "Enter " << size2 << " elements: ";
    for (i = 0; i < size2; i++) {
        cin >> arr2[i];
        mergedArr[k] = arr2[i]; // Append to the merged array
        k++;
    }

    // Display the merged array
    cout << "\nThe Merged Array is:\n";
    for (i = 0; i < k; i++) {
        cout << mergedArr[i] << " ";
    }
    cout << endl;

    return 0;
}
