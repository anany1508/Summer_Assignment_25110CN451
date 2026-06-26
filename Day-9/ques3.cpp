#include <iostream>
using namespace std;

int main() {
    int rows;
    
    // Requesting user input for pattern size
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    // Starting character 'A' (ASCII value 65)
    char ch = 'A'; 
    
    // Outer loop for managing rows
    for (int i = 1; i <= rows; i++) {
        
        // Inner loop for repeating the character in columns
        for (int j = 1; j <= i; j++) {
            cout << ch << " ";
        }
        
        // Move to the next line after printing the row
        cout << "\n";
        
        // Change character for the next row
        ch++; 
    }
    
    return 0;
}
