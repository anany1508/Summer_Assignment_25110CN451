#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

int main() {
    std::string str = "Hello World";

    // Reverse the string from beginning to end
    std::reverse(str.begin(), str.end());

    std::cout << "Reversed String: " << str << std::endl;

    return 0;
}
