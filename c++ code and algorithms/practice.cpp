#include <bits/stdc++.h>

using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;
    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int n) {
    if (row >= n)
        return true;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQueensUtil(board, row + 1, n))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solveNQueensUtil(board, 0, n)) {
        for (const auto& row : board) {
            for (int col : row)
                cout << (col ? "Q " : ". ");
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    solveNQueens(n);
    return 0;
}

