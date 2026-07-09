#include <iostream>
#include <string>
#include <unordered_set>

// Function to find the first repeating character
char findFirstRepeating(const std::string& str) {
    std::unordered_set<char> seenCharacters;

    for (char ch : str) {
        // If the character is already in the set, it is the first repeat
        if (seenCharacters.find(ch) != seenCharacters.end()) {
            return ch;
        }
        // Otherwise, add the character to the set
        seenCharacters.insert(ch);
    }

    // Return a null character if no repeating character is found
    return '\0';
}

int main() {
    std::string inputStr = "geeksforgeeks";
    
    char result = findFirstRepeating(inputStr);

    if (result != '\0') {
        std::cout << "The first repeating character is: " << result << std::endl;
    } else {
        std::cout << "No repeating characters found." << std::endl;
    }

    return 0;
}
