#include <iostream>
#include <string>

using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    int start = 0;
    int end = str.length() - 1;

    // Move pointers towards the middle
    while (start < end) {
        // If characters mismatch, it's not a palindrome
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    // If the loop completes, all matched
    return true; 
}

int main() {
    string userInput;

    cout << "Enter a string: ";
    cin >> userInput;

    if (isPalindrome(userInput)) {
        cout << "\"" << userInput << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << userInput << "\" is NOT a palindrome." << endl;
    }

    return 0;
}
