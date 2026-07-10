#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

// Custom comparator function to compare string lengths
bool compareByLength(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

int main() {
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    std::vector<std::string> words;
    std::stringstream ss(input);
    std::string word;

    // Split the sentence into individual words
    while (ss >> word) {
        words.push_back(word);
    }

    // Sort the words using the custom comparator
    std::sort(words.begin(), words.end(), compareByLength);

    // Display the sorted words
    std::cout << "\nWords sorted by length:\n";
    for (const auto& w : words) {
        std::cout << w << " (Length: " << w.length() << ")\n";
    }

    return 0;
}
