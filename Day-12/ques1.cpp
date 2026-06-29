#include <iostream>
#include <string>

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        // If characters mismatch, it's not a palindrome
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    // If we made it through the loop, it is a palindrome
    return true;
}

int main() {
    std::string test1 = "radar";
    std::string test2 = "hello";

    std::cout << "\"" << test1 << "\" is " << (isPalindrome(test1) ? "a palindrome." : "not a palindrome.") << std::endl;
    std::cout << "\"" << test2 << "\" is " << (isPalindrome(test2) ? "a palindrome." : "not a palindrome.") << std::endl;

    return 0;
}