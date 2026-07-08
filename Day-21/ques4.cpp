#include <iostream>
#include <cctype> // Required for std::toupper

int main() {
    char lower_char;
    
    std::cout << "Enter a lowercase character: ";
    std::cin >> lower_char;
    
    // std::toupper returns an int, so we cast it back to char
    char upper_char = static_cast<char>(std::toupper(lower_char));
    
    std::cout << "Uppercase character: " << upper_char << std::endl;
    
    return 0;
}
