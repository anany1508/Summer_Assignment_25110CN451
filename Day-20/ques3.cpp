#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Get matrix dimensions from the user
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int matrix[100][100];

    // Input matrix elements
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\n--- Row-wise Sums ---" << endl;

    // Logic to find row-wise sum
    for (int i = 0; i < rows; i++) {
        int rowSum = 0; // Reset sum for each new row
        
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j]; // Add each element in the current row
        }
        
        cout << "Sum of row " << i + 1 << " = " << rowSum << endl;
    }

    return 0;
}
