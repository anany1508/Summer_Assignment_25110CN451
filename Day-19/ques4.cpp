#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the square matrix (N x N): ";
    cin >> n;

    // Initialize an N x N 2D vector
    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int principalSum = 0;
    int secondarySum = 0;

    // Single loop optimization: O(N) time complexity
    for (int i = 0; i < n; i++) {
        // Principal diagonal condition: row index == column index (i == i)
        principalSum += matrix[i][i];

        // Secondary diagonal condition: column index == n - 1 - row index
        secondarySum += matrix[i][n - 1 - i];
    }

    // Output the results
    cout << "\n--- Result ---" << endl;
    cout << "Sum of Principal Diagonal: " << principalSum << endl;
    cout << "Sum of Secondary Diagonal: " << secondarySum << endl;
    cout << "Total Diagonal Sum: " << (principalSum + secondarySum) << endl;

    return 0;
}
