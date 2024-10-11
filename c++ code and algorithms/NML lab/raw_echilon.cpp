
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printMatrix(const vector<vector<double>>& matrix)
{
    for (const auto& row : matrix)
    {
        for (double val : row)
        {
            cout << setw(10) << setprecision(4) << val << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

void rearrangeRows(vector<vector<double>>& matrix, int col)
{
    int n = matrix.size();
    int flag=0;
    //cout<<col<<endl;
    for (int row = 0; row < n; ++row)
    {
        if (matrix[row][col] == 0)
        {
            for(int l=0; l<col; l++)
            {
                //cout<<row<<" "<<l<<" "<<matrix[row][l]<<endl;

                if(matrix[row][l]<0 || matrix[row][l]>0)
                {
                    flag=1;
                    // cout<<"flag="<<flag<<endl;
                    break;
                }
            }

            if(flag==0)
            {
                for (int k = row + 1; k < n; ++k)
                {
                    if (matrix[k][col] != 0)
                    {
                        // Swap rows
                        swap(matrix[row], matrix[k]);
                        break; // Only swap with the first non-zero found below
                    }
                }
            }
        }
    }
}

vector<vector<double>> gaussElimination(vector<vector<double>>& matrix)
{
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns (including augmented part)

    // Convert to upper triangular form
    for (int col = 0; col < n - 1; ++col)   // Loop through each column
    {
        //n-1 cause nicher raw er diagonal value calculate korbo na
        rearrangeRows(matrix, col); // Rearranging before processing
        for (int row = col + 1; row < n; ++row)   // Loop through rows below the current row
        {
            if (matrix[row][col] != 0)   // Only proceed if the element is not zero
            {
                double multiplier = matrix[row][col] / matrix[col][col];
                for (int j = col; j < m; ++j)   // Update the row
                {
                    matrix[row][j] -= multiplier * matrix[col][j];
                }
            }
        }

        printMatrix(matrix);
    }
    return matrix; // Return the upper triangular matrix
}

vector<vector<double>> gaussJordan(vector<vector<double>>& matrix)
{
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns (including augmented part)

    // Convert to reduced row echelon form (RREF)
    for (int col = 0; col < n; ++col)   // Loop through each column
    {
        // Ensure the pivot is at the diagonal
        rearrangeRows(matrix, col);

        // Eliminate values above and below the pivot
        for (int row = 0; row < n; ++row)
        {
            if (row != col)   // Skip the pivot value
            {
                double multiplier = matrix[row][col] / matrix[col][col];
                for (int j = 0; j < m; ++j)
                {
                    matrix[row][j] -= multiplier * matrix[col][j];
                }
            }
            //rearrangeRows(matrix, col);
        }
        // rearrangeRows(matrix, col);
    }
    // rearrangeRows(matrix, col);
    return matrix; // Return the RREF matrix
}
vector<vector<double>> raw_echilon_form(vector<vector<double>>& matrix)
{
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns (including augmented part)

    for (int col = 0; col < n; ++col)   // Loop through each column
    {
        // Ensure the pivot is at the diagonal


        // Normalize the pivot row
        double pivot = matrix[col][col];
        if (pivot != 0)
        {
            for (int j = 0; j < m; ++j)
            {
                matrix[col][j] /= pivot;
                if(matrix[col][j]==-0)
                {
                    matrix[col][j]=0;
                }// Normalize the pivot row
            }
        }
    }
    return matrix;
}

int main()
{
    vector<vector<double>> matrix =
    {
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
    cout<<endl;

    matrix = raw_echilon_form(matrix);
    cout << "\nReduced Row Echelon Form (RREF):\n";
    printMatrix(matrix);
int n;
n=matrix[0].size();

for(int i=0;i<matrix.size();i++)
{
    for(int j=0;j<n-1;j++)
    {
        if(i==j)
        cout<<"x"<<i<<"="<<matrix[i][n-1]<<endl;
    }
}
    return 0;
}
