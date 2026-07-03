#include <iostream>
#include <vector>
#include <numeric>

int findMissingNumberSum(const std::vector<int>& arr) {
    int n = arr.size();
    // Expected sum for 1 to n+1
    int expectedSum = (n + 1) * (n + 2) / 2;
    int actualSum = std::accumulate(arr.begin(), arr.end(), 0);
    return expectedSum - actualSum;
}

int main() {
    std::vector<int> arr = {1, 2, 4, 5, 6};
    std::cout << "Missing Number: " << findMissingNumberSum(arr) << std::endl;
    return 0;
}   