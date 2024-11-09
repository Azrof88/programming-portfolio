#include <bits/stdc++.h>

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

// Function to generate all possible moves from the current state
void generateMoves(const vector<vector<int>>& board, int zeroRow, int zeroCol,
                   vector<vector<int>>& nextBoard) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right
    for (int d = 0; d < 4; d++) {
        int newRow = zeroRow + directions[d][0];
        int newCol = zeroCol + directions[d][1];
        if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
            nextBoard = board; // Create a copy of the current board
            swap(nextBoard[zeroRow][zeroCol], nextBoard[newRow][newCol]);
        }
    }
}

// Function to serialize board state for unique identification
string serializeBoard(const vector<vector<int>>& board) {
    string key;
    for (const auto& row : board) {
        for (int tile : row) {
            key += to_string(tile) + ",";
        }
    }
    return key;
}

// Function to solve the puzzle using branch and bound
int solvePuzzle(vector<vector<int>>& initialBoard) {
    // Find the position of the empty space (0)
    int zeroRow, zeroCol;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (initialBoard[i][j] == 0) {
                zeroRow = i;
                zeroCol = j;
            }
        }
    }

    // Priority queue for states
    auto cmp = [](const pair<int, vector<vector<int>>>& a, const pair<int, vector<vector<int>>>& b) {
        return a.first > b.first; // Min-heap based on cost
    };
    priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>, decltype(cmp)> pq(cmp);
    unordered_set<string> visited;

    pq.push({0, initialBoard});
    visited.insert(serializeBoard(initialBoard));

    while (!pq.empty()) {
        auto currentState = pq.top();
        int currentCost = currentState.first;
        vector<vector<int>> currentBoard = currentState.second;
        pq.pop();

        // Check if the goal is reached
        if (isGoal(currentBoard)) {
            return currentCost; // Return the least cost
        }

        // Find the position of the empty space
        int zeroRow, zeroCol;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (currentBoard[i][j] == 0) {
                    zeroRow = i;
                    zeroCol = j;
                }
            }
        }

        // Generate possible moves
        vector<vector<int>> nextBoard(N, vector<int>(N));
        for (int d = 0; d < 4; d++) {
            int newRow = zeroRow + (d == 0 ? -1 : d == 1 ? 1 : 0);
            int newCol = zeroCol + (d == 2 ? -1 : d == 3 ? 1 : 0);
            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
                nextBoard = currentBoard; // Create a copy of the current board
                swap(nextBoard[zeroRow][zeroCol], nextBoard[newRow][newCol]);

                string boardKey = serializeBoard(nextBoard);
                if (visited.find(boardKey) == visited.end()) {
                    visited.insert(boardKey);
                    pq.push({currentCost + 1, nextBoard});
                }
            }
        }
    }

    return -1; // If no solution found
}

int main() {
    vector<vector<int>> initialBoard = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 12, 11},
        {14, 13, 0, 15} // Example initial configuration
    };

    int leastCost = solvePuzzle(initialBoard);
    if (leastCost != -1) {
        cout << "Least cost to solve the puzzle: " << leastCost << endl;
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
