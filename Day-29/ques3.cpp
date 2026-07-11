#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Function prototypes for clarity
void clearInputBuffer();
void getStringLength();
void concatenateStrings();
void reverseString();
void checkPalindrome();
void countVowelsAndConsonants();

int main() {
    int choice;

    do {
        // Displaying the system interface menu
        cout << "\n=========================================\n";
        cout << "      STRING OPERATION SYSTEM IN C++      \n";
        cout << "=========================================\n";
        cout << "1. Find Length of a String\n";
        cout << "2. Concatenate Two Strings\n";
        cout << "3. Reverse a String\n";
        cout << "4. Check if Palindrome\n";
        cout << "5. Count Vowels and Consonants\n";
        cout << "6. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice (1-6): ";
        
        // Handle non-integer inputs gracefully
        if (!(cin >> choice)) {
            cout << "\n[Error] Invalid choice! Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer(); // Clear newline character after reading the choice

        switch (choice) {
            case 1:
                getStringLength();
                break;
            case 2:
                concatenateStrings();
                break;
            case 3:
                reverseString();
                break;
            case 4:
                checkPalindrome();
                break;
            case 5:
                countVowelsAndConsonants();
                break;
            case 6:
                cout << "\nExiting the system. Goodbye!\n";
                break;
            default:
                cout << "\n[Error] Choice out of range! Select an option between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}

// Clears remnant characters and reset input state
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// 1. Find Length of a String
void getStringLength() {
    string str;
    cout << "\nEnter a string: ";
    getline(cin, str);
    cout << "Result: The length of the string is " << str.length() << " characters.\n";
}

// 2. Concatenate Two Strings
void concatenateStrings() {
    string str1, str2;
    cout << "\nEnter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);
    
    string result = str1 + str2;
    cout << "Result: Concatenated string is -> \"" << result << "\"\n";
}

// 3. Reverse a String
void reverseString() {
    string str;
    cout << "\nEnter a string to reverse: ";
    getline(cin, str);
    
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    cout << "Result: Reversed string is -> \"" << revStr << "\"\n";
}

// 4. Check if Palindrome
void checkPalindrome() {
    string str;
    cout << "\nEnter a string to check: ";
    getline(cin, str);
    
    // Create a normalized version (remove spaces and convert to lowercase)
    string normalized = "";
    for (char c : str) {
        if (!isspace(c)) {
            normalized += tolower(c);
        }
    }
    
    string revStr = normalized;
    reverse(revStr.begin(), revStr.end());
    
    if (normalized == revStr) {
        cout << "Result: \"" << str << "\" is a Palindrome!\n";
    } else {
        cout << "Result: \"" << str << "\" is NOT a Palindrome.\n";
    }
}

// 5. Count Vowels and Consonants
void countVowelsAndConsonants() {
    string str;
    cout << "\nEnter a string: ";
    getline(cin, str);
    
    int vowels = 0, consonants = 0;
    
    for (char c : str) {
        if (isalpha(c)) {
            char lowerC = tolower(c);
            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    cout << "Result:\n";
    cout << " - Total Vowels: " << vowels << "\n";
    cout << " - Total Consonants: " << consonants << "\n";
}
