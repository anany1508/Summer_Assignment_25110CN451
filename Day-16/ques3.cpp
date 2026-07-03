#include <iostream>
#include <vector>
#include <unordered_set>

// Function to find and print the pair with the target sum
bool findPairWithSum(const std::vector<int>& arr, int targetSum) {
    std::unordered_set<int> seenElements;

    for (int num : arr) {
        // Calculate the required complement to reach targetSum
        int complement = targetSum - num;

        // If the complement is already in the set, a pair is found
        if (seenElements.find(complement) != seenElements.end()) {
            std::cout << "Pair found: (" << complement << ", " << num << ")\n";
            return true;
        }

        // Insert the current element into the set
        seenElements.insert(num);
    }

    std::cout << "No pair found with the given sum.\n";
    return false;
}

int main() {
    std::vector<int> arr = {8, 4, 1, 6, 3, 2, 5};
    int targetSum = 10;

    std::cout << "Array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\nTarget Sum: " << targetSum << "\n\n";

    findPairWithSum(arr, targetSum);

    return 0;
}
