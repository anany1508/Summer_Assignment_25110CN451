#include <iostream>
#include <string>

// Function to compress the given string
std::string compressString(const std::string& str) {
    int n = str.length();
    if (n == 0) return "";

    std::string compressed = "";

    for (int i = 0; i < n; i++) {
        // Count occurrences of the current character
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Append character and its count to the result
        compressed += str[i];
        compressed += std::to_string(count);
    }

    // Return compressed string only if it is shorter than the original
    return compressed.length() < str.length() ? compressed : str;
}

int main() {
    std::string input1 = "aaabbbbccffff";
    std::string input2 = "abc";

    std::cout << "Original: " << input1 << " -> Compressed: " << compressString(input1) << std::endl;
    std::cout << "Original: " << input2 << " -> Compressed: " << compressString(input2) << std::endl;

    return 0;
}
