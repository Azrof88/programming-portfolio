
#include <bits/stdc++.h>

using namespace std;

// Function to calculate the cost of the current path
int calculateCost(int path[], int n, int dist[][10]) {
    int cost = 0;
    for (int i = 0; i < n - 1; i++) {
        cost += dist[path[i]][path[i + 1]];
    }
    cost += dist[path[n - 1]][path[0]]; // Returning to the origin
    return cost;
}

// Function to find the minimum cost path using branch and bound
void tsp(int dist[][10], int n) {
    int minCost = INT_MAX;
    int bestPath[10]; // To store the best path
    int path[10]; // Current path
    vector<bool> visited(n, false); // Visited cities

    // Initialize the starting city
    visited[0] = true;
    path[0] = 0;

    // Priority queue to hold paths and their costs
    priority_queue<pair<int, vector<int>>> pq; // (negative cost, path)
    pq.push({0, {0}}); // Start from city 0

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int currentCost = -top.first; // Get the current cost
        vector<int> currentPath = top.second; // Get the current path

        int lastCity = currentPath.back();

        // If we have visited all cities
        if (currentPath.size() == n) {
            // Calculate cost to return to the starting city
            int totalCost = currentCost + dist[lastCity][0];
            if (totalCost < minCost) {
                minCost = totalCost;
                bestPath[0] = 0;
                for (int i = 1; i < n; i++) {
                    bestPath[i] = currentPath[i - 1];
                }
                bestPath[n] = 0; // Returning to starting city
            }
            continue;
        }

        // Explore the next cities
        for (int nextCity = 0; nextCity < n; nextCity++) {
            if (find(currentPath.begin(), currentPath.end(), nextCity) == currentPath.end()) {
                // Calculate the cost of the new path
                int newCost = currentCost + dist[lastCity][nextCity];
                vector<int> newPath = currentPath;
                newPath.push_back(nextCity);
                pq.push({-newCost, newPath}); // Push with negative cost for min-heap behavior
            }
        }
    }

    // Output the best path and cost
    cout << "Minimum cost: " << minCost << endl;
    cout << "Path: ";
    for (int i = 0; i <= n; i++) {
        cout << bestPath[i] << " ";
    }
    cout << endl;
}

int main() {
    int n; // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;

    int dist[10][10]; // Distance matrix

    // Input distance matrix
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Call the tsp function
    tsp(dist, n);

    return 0;
}
