#include <iostream>
#include <string>

using namespace std;

char getMaxOccurringChar(const string& str) {
    // Array to store the count of all 256 ASCII characters
    int count[256] = {0}; 
    
    // Fill the frequency array
    for (char ch : str) {
        // Cast to unsigned char to safely handle negative values if any
        count[static_cast<unsigned char>(ch)]++;
    }
    
    int maxCount = -1;
    char result = ' ';
    
    // Find the character with the maximum frequency
    for (char ch : str) {
        int currentCount = count[static_cast<unsigned char>(ch)];
        if (maxCount < currentCount) {
            maxCount = currentCount;
            result = ch;
        }
    }
    
    return result;
}

int main() {
    string inputStr;
    
    cout << "Enter a string: ";
    // Use getline to accept spaces inside the input string
    getline(cin, inputStr);
    
    if (inputStr.empty()) {
        cout << "The string is empty." << endl;
        return 0;
    }
    
    char maxChar = getMaxOccurringChar(inputStr);
    
    cout << "The maximum occurring character is: '" << maxChar << "'" << endl;
    
    return 0;
}
