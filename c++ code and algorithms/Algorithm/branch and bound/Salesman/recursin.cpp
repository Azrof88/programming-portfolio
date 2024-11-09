
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Recursive function to find the minimum cost path
void tspRec(int dist[][10], int currPos, int n, int visited[], int count, int cost, int& minCost, vector<int>& bestPath, vector<int>& currentPath) {
    // Base case: if all cities have been visited
    if (count == n && dist[currPos][0]) {
        int totalCost = cost + dist[currPos][0]; // Return to starting city
        if (totalCost < minCost) {
            minCost = totalCost;
            bestPath = currentPath; // Update best path
            bestPath.push_back(0); // Return to starting city
        }
        return;
    }

    // Explore the next cities
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[currPos][i]) { // If city i hasn't been visited
            visited[i] = 1; // Mark as visited
            currentPath.push_back(i); // Add city to the current path

            // Recur for the next city
            tspRec(dist, i, n, visited, count + 1, cost + dist[currPos][i], minCost, bestPath, currentPath);

            // Backtrack
            visited[i] = 0; // Mark as unvisited
            currentPath.pop_back(); // Remove city from current path
        }
    }
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

    // Variables to store the minimum cost and paths
    int minCost = INT_MAX;
    vector<int> bestPath;
    vector<int> currentPath;

    // Array to keep track of visited cities
    int visited[10] = {0};

    // Start from the first city
    visited[0] = 1; // Start from city 0
    currentPath.push_back(0); // Starting path

    // Call the recursive TSP function
    tspRec(dist, 0, n, visited, 1, 0, minCost, bestPath, currentPath);

    // Output the best path and cost
    cout << "Minimum cost: " << minCost << endl;
    cout << "Path: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
