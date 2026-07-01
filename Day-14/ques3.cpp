#include <iostream>
#include <vector>
#include <climits> // Required for INT_MIN

using namespace std;

// Function to find the second largest element
int getSecondLargest(const vector<int>& arr) {
    int n = arr.size();
    
    // There must be at least two elements in the array
    if (n < 2) {
        return -1; 
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        // If current element is greater than the largest
        if (arr[i] > largest) {
            secondLargest = largest; // Previous largest becomes second largest
            largest = arr[i];        // Update largest
        }
        // If current element is smaller than largest but greater than second largest
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    // If secondLargest was never updated, it means no distinct second largest exists
    if (secondLargest == INT_MIN) {
        return -1;
    }

    return secondLargest;
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    
    int result = getSecondLargest(arr);
    
    if (result == -1) {
        cout << "No distinct second largest element exists." << endl;
    } else {
        cout << "The second largest element is: " << result << endl;
    }

    return 0;
}
