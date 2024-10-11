#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the matrix (n): ";
    cin >> n;


    int upCost, downCost, leftCost, rightCost;
    cout << "Enter the cost for moving right, left, down, up: ";
    cin >> rightCost >> leftCost >> downCost >> upCost;


    int dirX[] = {1, -1, 0, 0};
    int dirY[] = {0, 0, -1, 1};
    int moveCost[] = {downCost, upCost, leftCost, rightCost};


    vector<vector<int>> result(n * n, vector<int>(n * n, INT_MAX));


    for (int startX = 0; startX < n; startX++) {
        for (int startY = 0; startY < n; startY++) {

            vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

            // Starting from (startX, startY)
            dist[startX][startY] = 0;
            pq.push({0, {startX, startY}});

            while (!pq.empty()) {
                auto current = pq.top();
                pq.pop();

                int x = current.second.first;
                int y = current.second.second;


                for (int i = 0; i < 4; i++) {

                    if ((i == 1 && x == 0) ||
                        (i == 0 && x == n - 1) ||
                        (i == 2 && y == 0) ||
                        (i == 3 && y == n - 1)) {
                        continue;
                    }

                    int newX = x + dirX[i];
                    int newY = y + dirY[i];

                    // Check bounds
                    if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
                        int newCost = dist[x][y] + moveCost[i];


                        if (newCost < dist[newX][newY]) {
                            dist[newX][newY] = newCost;
                            pq.push({newCost, {newX, newY}});
                        }
                    }
                }
            }

            // Store the results in the output matrix
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    result[startX * n + startY][i * n + j] = dist[i][j];
                }
            }
        }
    }


    cout << "Shortest path cost matrix (from each point to all points):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "From (" << i << ", " << j << "):" << endl;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    cout << result[i * n + j][k * n + l] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
