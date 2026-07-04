#include <iostream>
#include <vector>
#include <unordered_set>

// Function to find the intersection of two arrays
std::vector<int> findIntersection(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::unordered_set<int> elementsSet(arr1.begin(), arr1.end());
    std::unordered_set<int> intersectionSet;
    std::vector<int> result;

    // Traverse the second array to check for common elements
    for (int num : arr2) {
        if (elementsSet.count(num)) {
            intersectionSet.insert(num); // Prevents duplicate elements in the final intersection
        }
    }

    // Move the unique common elements into the result vector
    for (int num : intersectionSet) {
        result.push_back(num);
    }

    return result;
}

int main() {
    std::vector<int> array1 = {4, 9, 5, 4};
    std::vector<int> array2 = {9, 4, 9, 8, 4};

    std::vector<int> intersection = findIntersection(array1, array2);

    // Display the result
    std::cout << "Intersection of the two arrays: ";
    for (int num : intersection) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
