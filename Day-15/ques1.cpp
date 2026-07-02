#include <iostream>
#include <algorithm> // Required for std::reverse

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Reverse the array elements in-place
    std::reverse(arr, arr + n);

    // Print the reversed array
    std::cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    
    return 0;
}
