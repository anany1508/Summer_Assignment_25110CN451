#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to check if two strings are anagrams
bool checkAnagram(string str1, string str2) {
    // If lengths are different, they cannot be anagrams
    if (str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, int> charCount;

    // Increment count for characters in the first string
    for (char ch : str1) {
        charCount[ch]++;
    }

    // Decrement count for characters in the second string
    for (char ch : str2) {
        charCount[ch]--;
    }

    // If all counts are zero, the strings are anagrams
    for (auto pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string string1, string2;

    // Take input from user
    cout << "Enter first string: ";
    cin >> string1;
    cout << "Enter second string: ";
    cin >> string2;

    // Check and print the result
    if (checkAnagram(string1, string2)) {
        cout << "\"" << string1 << "\" and \"" << string2 << "\" are anagrams." << endl;
    } else {
        cout << "\"" << string1 << "\" and \"" << string2 << "\" are NOT anagrams." << endl;
    }

    return 0;
}
