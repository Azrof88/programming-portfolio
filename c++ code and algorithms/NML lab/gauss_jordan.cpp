#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << setw(10) << setprecision(4) << val << " ";
        }
        cout << endl;
    }
}

void rearrangeRows(vector<vector<double>>& matrix, int col) {
    int n = matrix.size();
    for (int row = 0; row < n; ++row) {
        if (matrix[row][col] == 0) {
            for (int k = row + 1; k < n; ++k) {
                if (matrix[k][col] != 0) {
                    // Swap rows
                    swap(matrix[row], matrix[k]);
                    break; // Only swap with the first non-zero found below
                }
            }
        }
    }
}

vector<vector<double>> gaussElimination(vector<vector<double>>& matrix) {
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns (including augmented part)

    // Convert to upper triangular form
    for (int col = 0; col < n - 1; ++col) { // Loop through each column
        rearrangeRows(matrix, col); // Rearranging before processing
        for (int row = col + 1; row < n; ++row) { // Loop through rows below the current row
            if (matrix[row][col] != 0) { // Only proceed if the element is not zero
                double multiplier = matrix[row][col] / matrix[col][col];
                for (int j = col; j < m; ++j) { // Update the row
                    matrix[row][j] -= multiplier * matrix[col][j];
                }
            }
        }
    }
    return matrix; // Return the upper triangular matrix
}

vector<vector<double>> gaussJordan(vector<vector<double>>& matrix) {
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns (including augmented part)

    // Convert to reduced row echelon form (RREF)
    for (int col = 0; col < n; ++col) { // Loop through each column
        // Ensure the pivot is at the diagonal
        rearrangeRows(matrix, col);

        // Eliminate values above and below the pivot
        for (int row = 0; row < n; ++row) {
            if (row != col) { // Skip the pivot row
                double multiplier = matrix[row][col] / matrix[col][col];
                for (int j = 0; j < m; ++j) {
                    matrix[row][j] -= multiplier * matrix[col][j];
                }
            }
        }
    }
    return matrix; // Return the RREF matrix
}

int main() {
    vector<vector<double>> matrix = {
        {2,1,2,1,6},
        {6,-6,6,12,36},
        {4, 3, 3, -3,-1},
        {2,2,-1,1,10}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    // Perform Gauss Elimination
    matrix = gaussElimination(matrix);
    cout << "\nUpper Triangular Matrix:\n";
    printMatrix(matrix);

    // Perform Gauss-Jordan Elimination
    matrix = gaussJordan(matrix);
    cout << "\nReduced Row Echelon Form (RREF):\n";
    printMatrix(matrix);

    return 0;
}
