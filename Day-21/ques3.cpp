#include <iostream>
#include <string>
#include <cctype> // Required for tolower() and isalpha()

using namespace std;

int main() {
    string input;
    int vowels = 0;
    int consonants = 0;

    cout << "Enter a string: ";
    // Use getline to read the entire line, including spaces
    getline(cin, input); 

    // Loop through each character in the string
    for (char ch : input) {
        // Check if the character is an alphabet letter
        if (isalpha(ch)) {
            // Convert to lowercase to minimize comparison checks
            char lowerCh = tolower(ch); 

            // Check for vowels
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                vowels++;
            } 
            // If it is an alphabet but not a vowel, it is a consonant
            else {
                consonants++;
            }
        }
    }

    // Output the final counts
    cout << "Total Vowels: " << vowels << endl;
    cout << "Total Consonants: " << consonants << endl;

    return 0;
}
