#include <iostream>
using namespace std;

int main() {
    int n;
    
    // 1. Take size of the array from the user
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n]; // Declare the array with size n
    
    // 2. Input elements into the array
    cout << "Enter " << n << " integers: \n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 3. Display the array elements
    cout << "The array elements are: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
