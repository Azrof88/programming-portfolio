#include <bits/stdc++.h>
using namespace std;

bool isValidMove(int x, int y, int n, vector<vector<int>>& output_matrix) {
    return (x >= 0 && x < n && y >= 0 && y < n && output_matrix[x][y] == -1);
}

bool horseMoveUtil(int x, int y, int move_count, int n, vector<vector<int>>& output_matrix, const vector<pair<int, int>>& moves) {
    output_matrix[x][y] = move_count;

    if (move_count == n * n - 1) {
        return true;
    }

    for (const auto& move : moves) {
        int new_x = x + move.first;
        int new_y = y + move.second;
        if (isValidMove(new_x, new_y, n, output_matrix)) {
            if (horseMoveUtil(new_x, new_y, move_count + 1, n, output_matrix, moves)) {
                return true;
            }
        }
    }

    output_matrix[x][y] = -1;
    return false;
}

void horseMoves(int n, pair<int, int> start_pos) {
    vector<vector<int>> output_matrix(n, vector<int>(n, -1));
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {2, -1}, {-1, 2},
        {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}
    };

    if (horseMoveUtil(start_pos.first, start_pos.second, 0, n, output_matrix, moves)) {
        for (const auto& row : output_matrix) {
            for (const auto& cell : row) {
                cout << cell << "  ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found to visit all positions." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (n): ";
    cin >> n;

    int start_x, start_y;
    cout << "Enter the starting position of the horse (x y): ";
    cin >> start_x >> start_y;

    horseMoves(n, {start_x, start_y});

    return 0;
}
