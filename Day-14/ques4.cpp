#include <iostream>
#include <vector>
#include <unordered_set>

void findDuplicates(const std::vector<int>& arr) {
    std::unordered_set<int> seen;
    std::unordered_set<int> duplicates;

    for (int num : arr) {
        // If the number is already in the 'seen' set, it's a duplicate
        if (seen.find(num) != seen.end()) {
            duplicates.insert(num);
        } else {
            seen.insert(num);
        }
    }

    // Print the unique duplicates found
    if (duplicates.empty()) {
        std::cout << "No duplicate elements found." << std::endl;
        return;
    }

    std::cout << "Duplicate elements: ";
    for (int num : duplicates) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1, 3};
    
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    findDuplicates(arr);

    return 0;
}
