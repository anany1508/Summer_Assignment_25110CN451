#include <iostream>

using namespace std;

int main() {
    int rows, cols;

    // Get matrix dimensions from user
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int matrix[100][100];

    // Input matrix elements
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Logic to calculate and print column-wise sum
    cout << "\nColumn-wise sums:\n";
    for (int j = 0; j < cols; j++) { // Outer loop iterates over columns
        int colSum = 0;              // Reset sum for the current column
        for (int i = 0; i < rows; i++) { // Inner loop iterates over rows
            colSum += matrix[i][j];
        }
        cout << "Sum of Column " << (j + 1) << " = " << colSum << endl;
    }

    return 0;
}
