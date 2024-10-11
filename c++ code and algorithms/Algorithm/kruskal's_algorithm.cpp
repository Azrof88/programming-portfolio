#include <bits/stdc++.h>

using namespace std;

// Function to find the root of an element with path compression
int find(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent); // Path compression
    }
    return parent[x];
}

// Function to union two sets with union by rank
void unionSets(int x, int y, vector<int>& parent, vector<int>& rank) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);

    if (rootX != rootY) {
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Function to check if two elements are in the same set
bool connected(int x, int y, vector<int>& parent) {
    return find(x, parent) == find(y, parent);
}

// Function to find the path between two nodes in the MST
void findPath(int start, int end, const vector<pair<int, int>>& mstEdges, vector<int>& path, vector<bool>& visited) {
    // Base case: if we've reached the end node, add it to the path and return
    if (start == end) {
        path.push_back(start);
        return;
    }

    // Mark the current node as visited
    visited[start] = true;
    path.push_back(start); // Add the current node to the path

    // Iterate through all edges in the MST
    for (const auto& edge : mstEdges) {
        int u = edge.first;
        int v = edge.second;

        // Check if the current edge connects to the start node and the other node hasn't been visited
        if ((u == start && !visited[v]) || (v == start && !visited[u])) {
            // Move to the unvisited node
            int nextNode = (u == start) ? v : u;
            findPath(nextNode, end, mstEdges, path, visited);

            // If the path has been found, return
            if (!path.empty() && path.back() == end) {
                return;
            }
        }
    }

    // If we reach here, it means we didn't find the path, so backtrack
    path.pop_back(); // Remove the current node from the path if no path was found
}

int main() {
    int node, edge;
    cout << "Enter number of nodes & edges: ";
    cin >> node >> edge;

    vector<pair<int, pair<int, int>>> v; // Edges list
    int weight, from, to;

    while (edge--) {
        cin >> weight >> from >> to;
        v.push_back({weight, {from, to}});
    }

    // Sort the vector in ascending order based on the weight
    sort(v.begin(), v.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first < b.first; // Compare the weights
    });

    // Initialize parent and rank arrays
    vector<int> parent(node);
    vector<int> rank(node, 0);

    // Initializing the parent array
    for (int i = 0; i < node; ++i) {
        parent[i] = i; // Each element is its own parent
    }

    int sum = 0;
    vector<pair<int, int>> mstEdges; // To store edges in the MST

    for (auto it : v) {
        weight = it.first;
        from = it.second.first;
        to = it.second.second;

        if (!connected(from, to, parent)) {
            unionSets(from, to, parent, rank);
            sum += weight;
            mstEdges.push_back({from, to}); // Store the edge in the MST
        }
    }

    cout << "Total weight of MST: " << sum << endl;

    // Output the edges of the MST
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (auto edge : mstEdges) {
        cout << edge.first << " -- " << edge.second << endl;
    }

    // Finding a path between two nodes
    int startNode, endNode;
    cout << "Enter the start and end nodes to find the path: ";
    cin >> startNode >> endNode;

    vector<int> path;
    vector<bool> visited(node, false);
    findPath(startNode, endNode, mstEdges, path, visited);

    cout << "Path from " << startNode << " to " << endNode << ": ";
    if (!path.empty()) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
