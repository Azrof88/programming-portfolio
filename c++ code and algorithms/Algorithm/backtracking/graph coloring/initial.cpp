#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>>& adj, int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // Since the graph is undirected
}

bool isSafe(int v, const vector<vector<int>>& adj, const vector<char>& color, char c) {
    for (int neighbor : adj[v]) {
        if (color[neighbor] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(const vector<vector<int>>& adj, vector<char>& color, int m, int v) {
    if (v == adj.size()) {
        return true;
    }

    for (char c = 'A'; c < 'A' + m; c++) { // Use characters starting from 'A'
        if (isSafe(v, adj, color, c)) {
            color[v] = c;
            if (graphColoringUtil(adj, color, m, v + 1)) {
                return true;
            }
            color[v] = '\0'; // Backtrack
        }
    }
    return false;
}

bool graphColoring(int n, const vector<vector<int>>& adj, int m) {
    vector<char> color(n, '\0');
    if (graphColoringUtil(adj, color, m, 0)) {
        cout << "Solution exists: Following are the assigned colors:\n";
        for (int i = 0; i < color.size(); i++) {
            cout << "Vertex " << i << " ---> Color " << color[i] << endl;
        }
        return true;
    }
    cout << "No solution exists\n";
    return false;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of colors (as a number): ";
    cin >> m;

    vector<vector<int>> adj(n);
    cout << "Enter the edges (format: u v) and type -1 -1 to stop:\n";
    while (true) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        addEdge(adj, u, v);
    }

    graphColoring(n, adj, m);
    return 0;
}
