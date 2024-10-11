#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<tuple<int, int, int>> edges; // (source, destination, weight)

    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back(make_tuple(u, v, w));
    }

    void printNegativeCycle(int parent[], int start) {
        vector<int> cycle;
        int current = start;

        do {
            cycle.push_back(current);
            current = parent[current];
        } while (current != start && current != -1);

        cycle.push_back(start);
        sort(cycle.begin(), cycle.end());

        cout << "Negative weight cycle: ";
        for (int node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    }

    void bellmanFord(int src) {
        vector<int> distance(V, numeric_limits<int>::max());
        int parent[V]; // To store the path
        distance[src] = 0;
        parent[src] = -1;

        // Relax edges |V| - 1 times
        for (int i = 1; i < V; i++) {
            for (auto edge : edges) {
                int u, v, w;
                tie(u, v, w) = edge;
                if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    parent[v] = u;
                }
            }
        }

        // Check for negative weight cycles
        for (auto edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v]) {
                cout << "Graph contains negative weight cycle." << endl;
                printNegativeCycle(parent, v); // Print the cycle
                return;
            }
        }

        cout << "No negative weight cycle found." << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 1, 1);
    g.addEdge(3, 2, 5);
    g.addEdge(4, 3, -3);

    g.bellmanFord(0); // Start from vertex 0

    return 0;
}
