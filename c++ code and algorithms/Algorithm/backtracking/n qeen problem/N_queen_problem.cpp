
#include <bits/stdc++.h>

using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check this column on upper side
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int n) {
    // Base case: If all queens are placed
    if (row >= n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // Place queen
            board[row][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, row + 1, n))
                return true;

            // If placing queen in the current position doesn't lead to a solution
            board[row][col] = 0; // Backtrack
        }
    }
    return false;
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueensUtil(board, 0, n)) {
        for (const auto& row : board) {
            for (int col : row)
                cout << (col ? " Q " : " . ");
            cout << endl;
        }
    } else {
        cout << "Solution does not exist" << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    solveNQueens(n);
    return 0;
}
