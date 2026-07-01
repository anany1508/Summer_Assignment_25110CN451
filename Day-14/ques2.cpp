#include <iostream>
#include <vector>
#include <algorithm> // Required for std::count

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 2, 1, 3, 2, 4, 2, 5};
    int target = 2;

    // Use std::count to find the frequency of the target element
    int frequency = std::count(numbers.begin(), numbers.end(), target);

    std::cout << "The element " << target << " appears " << frequency << " times." << std::endl;

    return 0;
}
