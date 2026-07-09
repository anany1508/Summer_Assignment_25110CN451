#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to find the first non-repeating character
char findFirstNonRepeating(const string& str) {
    unordered_map<char, int> charCounts;

    // Pass 1: Count the frequency of each character
    for (char ch : str) {
        charCounts[ch]++;
    }

    // Pass 2: Find the first character with a count of 1
    for (char ch : str) {
        if (charCounts[ch] == 1) {
            return ch; 
        }
    }

    // Return a fallback character if all characters repeat
    return '\0'; 
}

int main() {
    string inputStr;
    cout << "Enter a string: ";
    cin >> inputStr;

    char result = findFirstNonRepeating(inputStr);

    if (result != '\0') {
        cout << "The first non-repeating character is: " << result << endl;
    } else {
        cout << "All characters are repeating or the string is empty." << endl;
    }

    return 0;
}
