
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n; // Number of cities
vector<vector<int>> dist; // Distance matrix
vector<bool> visited; // Track visited cities
int bestCost = INT_MAX; // Best cost found
vector<int> bestPath; // Best path found

void tspUtil(int currCity, int count, int cost, vector<int> path) {
    // If all cities have been visited and we can return to the starting city
    if (count == n) {
        if (dist[currCity][0] > 0) { // Check if there is a path back to the start
            int totalCost = cost + dist[currCity][0]; // Calculate total cost
            if (totalCost < bestCost) {
                bestCost = totalCost;
                bestPath = path;
                bestPath.push_back(0); // Add starting city to the path
            }
        }
        return;
    }

    // Explore further cities
    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (!visited[nextCity] && dist[currCity][nextCity]) {
            // Mark the city as visited
            visited[nextCity] = true;
            path.push_back(nextCity);

            // Recur with updated cost and count
            tspUtil(nextCity, count + 1, cost + dist[currCity][nextCity], path);

            // Backtrack
            visited[nextCity] = false;
            path.pop_back();
        }
    }
}

void findShortestPath() {
    visited[0] = true; // Start from the first city
    vector<int> path;
    path.push_back(0); // Starting city

    tspUtil(0, 1, 0, path); // Start TSP utility function
}

void printResult() {
    cout << "Minimum cost: " << bestCost << endl;
    cout << "Path: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    dist.resize(n, vector<int>(n));
    visited.resize(n, false);

    cout << "Enter the distance matrix (0 if no direct path):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    findShortestPath();
    printResult();

    return 0;
}

/*

0   10  15  20  25
10  0   35  25  30
15  35  0   30  20
20  25  30  0   15
25  30  20  15  00
*/
