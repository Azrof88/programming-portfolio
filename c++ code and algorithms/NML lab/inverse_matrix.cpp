#include <iostream>
#include <vector>

#define N 4

using namespace std;

// Function to get cofactor of A[p][q] in temp[][]. n is
// current dimension of A[][]
void getCofactor(const vector<vector<int> >& A,
                 vector<vector<int> >& temp, int p, int q,
                 int n)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copying into temporary matrix only those
            // element which are not in given row and column
            if (row != p && col != q) {
                temp[i][j++] = A[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* Recursive function for finding determinant of matrix.
n is current dimension of A[][]. */
int determinant(const vector<vector<int> >& A, int n)
{
    int D = 0; // Initialize result

    // Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];

    vector<vector<int> > temp(
        N, vector<int>(N)); // To store cofactors

    int sign = 1; // To store sign multiplier

    // Iterate for each element of first row
    for (int f = 0; f < n; f++) {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}

// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(const vector<vector<int> >& A,
             vector<vector<int> >& adj)
{
    if (N == 1) {
        adj[0][0] = 1;
        return;
    }

    // temp is used to store cofactors of A[][]
    int sign = 1;
    vector<vector<int> > temp(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, N);

            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i + j) % 2 == 0) ? 1 : -1;

            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign) * (determinant(temp, N - 1));
        }
    }
}

// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(const vector<vector<int> >& A,
             vector<vector<float> >& inv)
{
    // Find determinant of A[][]
    int det = determinant(A, N);
    if (det == 0) {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }

    // Find adjoint
    vector<vector<int> > adj(N, vector<int>(N));
    adjoint(A, adj);

    // Find Inverse using formula "inverse(A) =
    // adj(A)/det(A)"
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inv[i][j] = adj[i][j] / float(det);

    return true;
}

// Generic function to display the matrix. We use it to
// display both adjoint and inverse. adjoint is integer
// matrix and inverse is a float.
void display(const vector<vector<int> >& A)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

void display(const vector<vector<float> >& A)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%.6f ", A[i][j]);
        cout << endl;
    }
}

// Driver program
int main()
{
    vector<vector<int> > A = { { 5, -2, 2, 7 },
                               { 1, 0, 0, 3 },
                               { -3, 1, 5, 0 },
                               { 3, -1, -9, 4 } };

    vector<vector<int> > adj(
        N, vector<int>(N)); // To store adjoint of A[][]
    vector<vector<float> > inv(
        N, vector<float>(N)); // To store inverse of A[][]

    cout << "Input matrix is :\n";
    display(A);

    cout << "\nThe Adjoint is :\n";
    adjoint(A, adj);
    display(adj);

    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);

    return 0;
}

