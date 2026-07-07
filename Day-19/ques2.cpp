#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Get matrix dimensions from the user
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    // Input elements for the first matrix
    cout << "\nEnter elements for the first matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    // Input elements for the second matrix
    cout << "\nEnter elements for the second matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    // Perform matrix subtraction
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // Display the result
    cout << "\nResultant Matrix after Subtraction:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
