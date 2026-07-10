#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string sentence;
    
    // Get full line input from user
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);
    
    // Use stringstream to break the sentence into words
    std::stringstream ss(sentence);
    std::string word;
    std::string longestWord = "";
    
    // Read word by word
    while (ss >> word) {
        // If current word is longer than the stored longest word, update it
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
    
    // Output the result
    if (longestWord.empty()) {
        std::cout << "No words found." << std::endl;
    } else {
        std::cout << "The longest word is: " << longestWord << std::endl;
        std::cout << "Length: " << longestWord.length() << std::endl;
    }
    
    return 0;
}
