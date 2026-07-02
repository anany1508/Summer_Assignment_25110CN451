#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

// Function to move all zeroes to the end of the vector
void moveZeroesToEnd(std::vector<int>& nums) {
    int j = 0; // Pointer to track the position of the next non-zero element

    for (int i = 0; i < nums.size(); i++) {
        // If the current element is not zero, swap it with the element at index j
        if (nums[i] != 0) {
            std::swap(nums[j], nums[i]);
            j++; // Move the pointer forward
        }
    }
}

int main() {
    // Example array containing zeroes
    std::vector<int> nums = {0, 1, 0, 3, 12, 0, 8};

    std::cout << "Original Array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Call the function
    moveZeroesToEnd(nums);

    std::cout << "Modified Array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
