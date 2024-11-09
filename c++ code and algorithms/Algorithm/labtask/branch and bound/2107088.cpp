
#include <bits/stdc++.h>

using namespace std;

const int N = 4;

bool G(const vector<vector<int>>& Board) {
    int value = 1;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (j == N - 1 && k == N - 1) {
                if(Board[j][k] == 0)
                    return true;
            }
             if (Board[j][k] != value++) {
                return false;
            }
        }
    }
    return true;
}

string serial(const vector<vector<int>>& B) {

    string k;
    for (const auto& r : B) {
        for (int t : r) {
            k += to_string(t) + ",";
        }
    }
    return k;
}



int Puzzle(vector<vector<int>>& Board) {

unordered_set<string> visited;
  priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>, greater<>> pq;
    pq.push({0,Board});
    string k;
    for (const auto& r : Board) {
        for (int t : r) {
            k += to_string(t) + ",";
        }
    }


    visited.insert(k);
while (!pq.empty()) {
        auto curState = pq.top();
        int curCost = curState.first;

        vector<vector<int>> curBoard = curState.second;
        pq.pop();


        if (G(curBoard)) {
            return curCost;
        }


        int zeroRow, zeroCol;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (curBoard[i][j] == 0) {
                    zeroRow = i;
                    zeroCol = j;
                }
            }
        }

        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};


        vector<vector<int>> nextB(N, vector<int>(N));
        for (int i = 0; i < 4; i++) {
            int nRow = zeroRow + dx[i];
            int nCol = zeroCol + dy[i];
            if (nRow >= 0 && nRow < N && nCol >= 0 && nCol < N) {
                nextB = curBoard;
                int temp=nextB[zeroRow][zeroCol];
                nextB[zeroRow][zeroCol]=nextB[nRow][nCol];
                nextB[nRow][nCol]=temp;
                string boardKey = serial(nextB);


                if (visited.find(boardKey) == visited.end()) {
                    visited.insert(boardKey);
                    pq.push({curCost + 1, nextB});
                }
            }
        }
    }

    return -1;
}

int main() {

    vector<vector<int>> Board = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 0, 15}
    };

   int Cost = Puzzle(Board);
    if ( Cost != -1) {
        cout <<  Cost << endl;
    } else {
        cout << "No solution " << endl;
    }

    return 0;
}
