#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

const int N = 4; // Size of the grid (4x4)

// Function to print the puzzle state
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int tile : row) {
            cout << tile << " ";
        }
        cout << endl;
    }
}

// Check if the current state is the goal state
bool isGoal(const vector<vector<int>>& board) {
    int expected = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == N - 1 && j == N - 1) {
                return board[i][j] == 0; // Last tile should be the empty space
            }
            if (board[i][j] != expected++) {
                return false;
            }
        }
    }
    return true;
}

// Convert board state to a string for easy comparison in the set
string boardToString(const vector<vector<int>>& board) {
    string str;
    for (const auto& row : board) {
        for (int tile : row) {
            str += to_string(tile) + ",";
        }
    }
    return str;
}

// BFS to find the solution and minimum moves
int solvePuzzle(vector<vector<int>> initialBoard) {
    queue<pair<vector<vector<int>>, pair<int, int>>> q; // Pair of board state and zero position
    unordered_set<string> visited; // To track visited states
    int zeroRow, zeroCol;

    // Find the position of the empty space (0)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (initialBoard[i][j] == 0) {
                zeroRow = i;
                zeroCol = j;
            }
        }
    }

    q.push({initialBoard, {zeroRow, zeroCol}});
    visited.insert(boardToString(initialBoard));
    int moves = 0;

    // Possible directions: Up, Down, Left, Right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            // Instead of structured bindings, explicitly define types
            pair<vector<vector<int>>, pair<int, int>> front = q.front();
            vector<vector<int>> currentBoard = front.first;
            pair<int, int> zeroPos = front.second;
            q.pop();

            if (isGoal(currentBoard)) {
                return moves; // Return the number of moves when the goal is reached
            }

            for (int d = 0; d < 4; d++) {
                int newRow = zeroPos.first + directions[d][0];
                int newCol = zeroPos.second + directions[d][1];

                // Check if the new position is within bounds
                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
                    // Swap empty space with the tile in the new position
                    swap(currentBoard[zeroPos.first][zeroPos.second], currentBoard[newRow][newCol]);

                    // Check if this state has been visited
                    string boardStr = boardToString(currentBoard);
                    if (visited.find(boardStr) == visited.end()) {
                        visited.insert(boardStr);
                        q.push({currentBoard, {newRow, newCol}});
                    }

                    // Backtrack: swap back
                    swap(currentBoard[zeroPos.first][zeroPos.second], currentBoard[newRow][newCol]);
                }
            }
        }
        moves++; // Increment moves after exploring all states at the current level
    }
    return -1; // Return -1 if no solution exists
}

int main() {
    vector<vector<int>> initialBoard = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 12, 11},
        {13, 14, 0, 15} // Example initial configuration
    };

    int minMoves = solvePuzzle(initialBoard);
    if (minMoves != -1) {
        cout << "Puzzle solved in " << minMoves << " moves!\n";
        printBoard(initialBoard);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
