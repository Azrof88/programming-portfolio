#include <iostream>
#include <vector>

using namespace std;

// Function to perform LU factorization
void luDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    // Initialize L and U
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                L[i][j] = 1; // Diagonal elements of L are 1
            } else {
                L[i][j] = 0;
            }
            U[i][j] = A[i][j]; // Initialize U as A
        }
    }

    // Perform the LU factorization
    for (int j = 0; j < n; ++j) {
        for (int i = j + 1; i < n; ++i) {
            L[i][j] = U[i][j] / U[j][j]; // Calculate L
            for (int k = j; k < n; ++k) {
                U[i][k] -= L[i][j] * U[j][k]; // Update U
            }
        }
    }
}

// Function to solve the equation Ax = b using LU decomposition
vector<double> solve(const vector<vector<double>>& L, const vector<vector<double>>& U, const vector<double>& b) {
    int n = L.size();
    vector<double> y(n);
    vector<double> x(n);

    // Forward substitution to solve Ly = b
    for (int i = 0; i < n; ++i) {
        y[i] = b[i];
        for (int j = 0; j < i; ++j) {
            y[i] -= L[i][j] * y[j];
        }
    }

    // Back substitution to solve Ux = y
    for (int i = n - 1; i >= 0; --i) {
        x[i] = y[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }

    return x;
}

// Function to print a matrix
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrix A and vector b
    vector<vector<double>> A = {
        {1, 1,-1},
        {1, -2,3},
        {2,3,1}
    };
    vector<double> b = {4,-6,7};

    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));

    // Perform LU decomposition
    luDecomposition(A, L, U);

    // Print L and U matrices
    cout << "Lower Triangular Matrix L:" << endl;
    printMatrix(L);
    cout << "Upper Triangular Matrix U:" << endl;
    printMatrix(U);

    // Solve the equation Ax = b
    vector<double> x = solve(L, U, b);

    // Print the solu
    cout << "Solution x:" << endl;
    for (const auto& val : x) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
