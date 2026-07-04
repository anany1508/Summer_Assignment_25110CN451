#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort and std::set_intersection

int main() {
    std::vector<int> vec1 = {4, 2, 9, 7, 1};
    std::vector<int> vec2 = {2, 8, 1, 4, 6};
    std::vector<int> common_elements;

    // Prerequisite: Both collections must be sorted
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    // Find the intersection
    std::set_intersection(vec1.begin(), vec1.end(),
                          vec2.begin(), vec2.end(),
                          std::back_inserter(common_elements));

    // Print the result
    std::cout << "Common elements: ";
    for (int num : common_elements) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
