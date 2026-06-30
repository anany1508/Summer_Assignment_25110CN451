#include <iostream>
using namespace std;

int main() {
    int n;

    // Get the size of the array from the user
    cout << "Enter the number of elements: ";
    cin >> n;

    // Handle invalid array sizes safely
    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    int arr[n];

    // Input the elements
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize both smallest and largest with the first element
    int smallest = arr[0];
    int largest = arr[0];

    // Traverse the array to update smallest and largest values
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Output the results
    cout << "Smallest element: " << smallest << endl;
    cout << "Largest element: " << largest << endl;

    return 0;
}
