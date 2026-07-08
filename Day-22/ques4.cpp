#include <iostream>
#include <string>
#include <algorithm> // Required for std::remove

int main() {
    std::string str;

    // Get the full line of text including spaces
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    // Erase-Remove Idiom to remove all ' ' characters
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

    std::cout << "String after removing spaces: " << str << std::endl;

    return 0;
}
