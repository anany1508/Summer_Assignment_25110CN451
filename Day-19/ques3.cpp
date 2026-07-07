#include <iostream>
using namespace std;

int main() {
    // Declaring upper bounds for a fixed array allocation
    int matrix[10][10], transpose[10][10];
    int rows, cols;

    cout << "Enter rows and columns (Max 10): ";
    cin >> rows >> cols;

    cout << "Enter elements:\n";
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cin >> matrix[i][i];
        }
    }

    // Mapping rows to columns
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    for(int i = 0; i < cols; ++i) {
        for(int j = 0; j < rows; ++j) {
            cout << transpose[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
