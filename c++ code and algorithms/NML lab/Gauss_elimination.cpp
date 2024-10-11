
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

void gaussElimination(vector<vector<double>>& matrix) {
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns (including augmented part)

    // Convert to upper triangular form
    for (int col = 0; col < n - 1; ++col) { // Loop through each column
        for (int row = col + 1; row < n; ++row) {// Loop through rows below the current row
            //row=col+1 because in raw echelon form all time calculated generally from 2nd raw because
            //at first our (0,0) element that means 1st raw and 1st col is pivot element
            //for 2nd col calculation will start from raw 3 .that time pivot col is 2 and raw is also 2
            if (matrix[row][col] != 0) { // Only proceed if the element is not zero
                double multiplier = matrix[row][col] / matrix[col][col];
                for (int j = col; j < m; ++j) { // Update the row
                    matrix[row][j] -= multiplier * matrix[col][j];
        //matrix[col][j] means je raw er shate multiplu korbo oi raw er number col diye bujacce
        //matrix[raw][j] rae means je raw te change hocche
                }
            }
        }
        // Rearranging after each column operation
        rearrangeRows(matrix, col);
    }

    // Final rearrangement to ensure no non-zero below zero in the last column
    rearrangeRows(matrix, m - 1);
}

bool hasInfiniteSolutions(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Check the last row for all zero coefficients
//    if (n > 0 && matrix[n - 1][m - 1] != 0) {
//        return false; // If the last element is non-zero, no infinite solutions
//    }

    for (int j = 0; j < m - 1; ++j) {
        if (matrix[n - 1][j] != 0) {
            return false; // If any coefficient is non-zero, no infinite solutions
        }
    }
    return true; // All coefficients are zero in the last row
}

int main() {
    // Example augmented matrix
    vector<vector<double>> matrix = {
        {1, 1, -1, 7},
        {1, -1, 2, 3},
        {0, 0, 0, 9},

    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    gaussElimination(matrix);

    cout << "\nUpper Triangular Matrix with Rearrangement:" << endl;
    printMatrix(matrix);

    // Check for infinite solutions
    if (hasInfiniteSolutions(matrix)) {
        cout << "\nThe linear equation has infinitely many solutions." << endl;
    } else {
        cout << "\nThe linear equation does not have infinitely many solutions." << endl;
    }

    return 0;
}
