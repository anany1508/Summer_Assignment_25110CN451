#include <bits/stdc++.h>
using namespace std;

int getMostFrequentNumber(int arr[], int n) {
    unordered_map<int, int> elements;
    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        elements[arr[i]]++;
    }
    
    int maxCount = 0, res = -1;
    // Find the element with the highest frequency
    for (auto i : elements) {
        if (maxCount < i.second) {
            res = i.first;
            maxCount = i.second;
        }
    }
    return res;
}

int main() {
    int arr[] = {1, 2, 3, 3, 2, 2, 1, 1, 2, 3, 4};
    int n = 11;
    cout << getMostFrequentNumber(arr, n) << endl; // Output: 2
    return 0;
}   