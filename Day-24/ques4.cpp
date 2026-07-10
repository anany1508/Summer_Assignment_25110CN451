#include <iostream>
#include <string>
#include <unordered_set>

std::string removeDuplicates(const std::string& str) {
    std::unordered_set<char> seen;
    std::string result = "";

    for (char ch : str) {
        // If the character is not in the set, it's unique
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            result += ch; // Add to final result
        }
    }
    return result;
}

int main() {
    std::string input = "programming";
    std::string output = removeDuplicates(input);

    std::cout << "Original: " << input << std::endl;
    std::cout << "Unique:   " << output << std::endl;

    return 0;
}
