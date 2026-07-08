#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string str;
    
    // Read the full line of text including spaces
    cout << "Enter a string: ";
    getline(cin, str);
    
    // Hash map to store character frequencies
    unordered_map<char, int> frequencyMap;
    
    // Count occurrences of each character
    for (char ch : str) {
        frequencyMap[ch]++;
    }
    
    // Display the results
    cout << "\nCharacter Frequencies:\n";
    for (char ch : str) {
        // Only print if it hasn't been printed yet
        if (frequencyMap[ch] > 0) {
            // Check for a space character to make output readable
            if (ch == ' ') {
                cout << "[Space] : " << frequencyMap[ch] << endl;
            } else {
                cout << "'" << ch << "' : " << frequencyMap[ch] << endl;
            }
            // Mark as printed by resetting its count
            frequencyMap[ch] = 0;
        }
    }
    
    return 0;
}
