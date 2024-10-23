
#include <bits/stdc++.h>
using namespace std;


bool isValid(int x, int y, int n, const vector<vector<int>>& board) {
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -2);
}


bool hrec(int x, int y, int moveCount, int n, vector<vector<int>>& board, const vector<pair<int, int>>& moves) {
    board[x][y] = moveCount;

    if (moveCount == n * n - 1) {
        return true;
    }

    for ( auto& mov : moves) {
        int newX = x + mov.first;
        int newY = y + mov.second;
        if (isValid(newX, newY, n, board)) {
            if (hrec(newX, newY, moveCount + 1, n, board, moves)) {
                return true;
            }
        }
    }

    board[x][y] = -2;
    return false;
}


void hTour(int n,int posX,int posY) {
    vector<vector<int>> board(n, vector<int>(n, -2));
    vector<pair<int, int>> hMoves = {
        {2, 1}, {1, 2}, {2, -1}, {-1, 2},
        {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}
    };
    pair<int,int>startPos;
    startPos.first=posX;
    startPos.second=posY;

    if (hrec(startPos.first, startPos.second, 0, n, board, hMoves)) {
        for ( auto& r : board) {
            for ( auto& c : r) {
                cout << c << "  ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found " << endl;
    }
}


int main() {
    int n;
    cin >> n;
int posX, posY;

    cin >> posX >> posY;

    hTour(n, posX, posY);

    return 0;
}
