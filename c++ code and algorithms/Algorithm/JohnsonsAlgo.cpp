#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>

using namespace std;

const int INF = 1000;

// Dijkstra's algorithm using basic arrays
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int n, int start) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        pair<int, int> s = pq.top();
        pq.pop();
        int d = s.first;
        int u = s.second;

        if (d > dist[u]) continue; // Skip if we already found a better path

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Bellman-Ford algorithm using basic arrays
vector<int> bellman(vector<vector<int>>& edges, int n, int start) {
    vector<int> dist(n, INF);
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        assert(dist[v] <= dist[u] + w);
    }

    return dist;
}

// Johnson's algorithm using basic arrays
vector<vector<int>> johnsons(vector<vector<int>>& edges, int n) {
    // Add a new node and set edges to it
    for (int i = 0; i < n; i++) {
        edges.push_back({n, i, 0});
    }

    vector<int> h = bellman(edges, n + 1, n);

    // Reweight the edges
    for (auto& edge : edges) {
        edge[2] += h[edge[0]] - h[edge[1]]; // Update weight in-place
    }

    vector<vector<pair<int, int>>> graph(n);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (u != n) {
            graph[u].emplace_back(v, w);
        }
    }

    vector<vector<int>> res(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        res[i] = dijkstra(graph, n, i);
    }

    // Adjust the distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (res[i][j] != INF) {
                res[i][j] += h[j] - h[i];
            }
        }
    }

    return res;
}

int main() {
    int n = 4; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1, -5},
        {0, 2, 2},
        {0, 3, 3},
        {1, 2, 4},
        {2, 3, 1}
    };

    vector<vector<int>> js = johnsons(edges, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (js[i][j] == INF ? "INF" : to_string(js[i][j])) << " ";
        }
        cout << endl;
    }

    return 0;
}
