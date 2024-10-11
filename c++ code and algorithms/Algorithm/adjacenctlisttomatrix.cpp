#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int vertices = 5; // Number of vertices
    vector<vector<pair<int, int>>> adjList(vertices); // Adjacency list for weighted graph

    // Adding edges (directed graph with weights)
    adjList[0].push_back({1, 2}); // Edge from 0 to 1 with weight 2
    adjList[0].push_back({4, 3}); // Edge from 0 to 4 with weight 3
    adjList[1].push_back({2, 5}); // Edge from 1 to 2 with weight 5
    adjList[1].push_back({3, 1}); // Edge from 1 to 3 with weight 1
    adjList[1].push_back({4, 4}); // Edge from 1 to 4 with weight 4
    adjList[2].push_back({3, 2}); // Edge from 2 to 3 with weight 2
    adjList[3].push_back({4, 6}); // Edge from 3 to 4 with weight 6

    // Convert adjacency list to adjacency matrix
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));

    // Initialize adjacency matrix with a high value for no direct edge
    const int INF = numeric_limits<int>::max();
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i != j) {
                adjMatrix[i][j] = INF; // No edge initially
            }
        }
    }

    // Fill the adjacency matrix with weights
    for (int i = 0; i < vertices; i++) {
        for (const auto& edge : adjList[i]) {
            int j = edge.first; // Destination vertex
            int weight = edge.second; // Weight of the edge
            adjMatrix[i][j] = weight; // Set the weight in the matrix
        }
    }

    // Print the adjacency matrix
    cout << "Adjacency Matrix (Weights):" << endl;
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            if (val == INF) {
                cout << "INF "; // Indicating no edge
            } else {
                cout << val << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
