#include <iostream>

int main() {
    int age;

    // Prompt user for input
    std::cout << "Enter your age: ";
    std::cin >> age;

    // Check voting eligibility
    if (age >= 18) {
        std::cout << "You are eligible to vote." << std::endl;
    } else {
        std::cout << "You are not eligible to vote yet." << std::endl;
        std::cout << "Years left to eligibility: " << (18 - age) << std::endl;
    }

    return 0;
}
