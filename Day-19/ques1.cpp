#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Get matrix dimensions from the user
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Declare 2D arrays for the matrices
    int matrix1[100][100], matrix2[100][100], sum[100][100];

    // Input elements for the first matrix
    cout << "\nEnter elements of the 1st matrix:\n";
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
            cin >> matrix1[i][j];
        }
    }

    // Input elements for the second matrix
    cout << "\nEnter elements of the 2nd matrix:\n";
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
            cin >> matrix2[i][j];
        }
    }

    // Adding the two matrices element by element
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Displaying the resulting sum matrix
    cout << "\nResultant Matrix (Sum):\n";
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << sum[i][j] << "    ";
        }
        cout << endl; // New line after each row
    }

    return 0;
}
