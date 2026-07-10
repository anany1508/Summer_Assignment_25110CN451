#include <iostream>
#include <string>

using namespace std;

// Function to check if s2 is a rotation of s1
bool isRotation(string s1, string s2) {
    // If lengths are not equal, they cannot be rotations
    if (s1.length() != s2.length()) {
        return false;
    }

    // Concatenate s1 with itself
    string temp = s1 + s1;

    // Check if s2 is a substring of the concatenated string
    // temp.find() returns string::npos if the substring is not found
    if (temp.find(s2) != string::npos) {
        return true;
    }

    return false;
}

int main() {
    string str1 = "ABCD";
    string str2 = "CDAB";

    if (isRotation(str1, str2)) {
        cout << "\"" << str2 << "\" is a rotation of \"" << str1 << "\"" << endl;
    } else {
        cout << "\"" << str2 << "\" is NOT a rotation of \"" << str1 << "\"" << endl;
    }

    return 0;
}
