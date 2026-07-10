#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::sort

int main() {
    int count;
    std::cout << "Enter the number of names: ";
    std::cin >> count;

    // Clear the input buffer to prevent getline from skipping inputs
    std::cin.ignore();

    std::vector<std::string> names;
    std::cout << "Enter " << count << " names:\n";

    for (int i = 0; i < count; ++i) {
        std::string temp_name;
        std::getline(std::cin, temp_name);
        names.push_back(temp_name);
    }

    // Sort names alphabetically (A to Z)
    std::sort(names.begin(), names.end());

    std::cout << "\nNames in alphabetical order:\n";
    for (const auto& name : names) {
        std::cout << name << "\n";
    }

    return 0;
}
