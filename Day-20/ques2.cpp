#include <iostream>
#include <vector>

using namespace std;

// Function to check if the matrix is symmetric
bool isSymmetric(const vector<vector<int>>& mat, int n) {
    for (int i = 0; i < n; i++) {
        // Only loop up to 'i' to avoid duplicate checks across the diagonal
        for (int j = 0; j < i; j++) {
            if (mat[i][j] != mat[j][i]) {
                return false; 
            }
        }
    }
    return true;
}

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    // A matrix must be square to be symmetric
    if (rows != cols) {
        cout << "The matrix is NOT symmetric (It must be a square matrix)." << endl;
        return 0;
    }

    int n = rows;
    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    // Output results
    if (isSymmetric(mat, n)) {
        cout << "The matrix is a Symmetric Matrix." << endl;
    } else {
        cout << "The matrix is NOT a Symmetric Matrix." << endl;
    }

    return 0;
}
