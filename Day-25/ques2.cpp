#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void findCommonCharacters(string s1, string s2) {
    int freq1[26] = {0};
    int freq2[26] = {0};

    // Count character frequencies for the first string
    for (char ch : s1) {
        if (ch >= 'a' && ch <= 'z') {
            freq1[ch - 'a']++;
        }
    }

    // Count character frequencies for the second string
    for (char ch : s2) {
        if (ch >= 'a' && ch <= 'z') {
            freq2[ch - 'a']++;
        }
    }

    // Print the common characters based on the minimum frequency
    cout << "Common characters (including duplicates): ";
    for (int i = 0; i < 26; i++) {
        int commonCount = min(freq1[i], freq2[i]);
        for (int j = 0; j < commonCount; j++) {
            cout << (char)(i + 'a') << " ";
        }
    }
    cout << endl;
}

int main() {
    string str1 = "geeksforgeeks";
    string str2 = "platformforgeeks";
    
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    
    findCommonCharacters(str1, str2);
    
    return 0;
}
