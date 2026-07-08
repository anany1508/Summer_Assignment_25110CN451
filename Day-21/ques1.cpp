#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int length = 0;

    // Taking user input (handles spaces as well)
    cout << "Enter a string: ";
    getline(cin, str);

    // Loop until the null character is reached
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }

    cout << "The length of the string is: " << length << endl;

    return 0;
}
