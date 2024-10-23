
#include <bits/stdc++.h>

using namespace std;

void printBoard(const vector<int>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
}

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
            board[i] - i == col - row ||
            board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& board, int row, int n) {
    if (row == n) {
        printBoard(board, n);
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1, n);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    vector<int> board(n);
    solveNQueens(board, 0, n);
    return 0;
}
