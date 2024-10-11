
#include<bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max(); // Define infinity

void printPath(const vector<vector<int>>& next, int u, int v) {
    if (next[u][v] == -1) {
        cout << "No path from " << u << " to " << v << endl;
        return;
    }
    cout << u ; // Print the source node
    while (u != v) {
        u = next[u][v];
        cout << " -> " << u ; // Print the path
    }
    cout << endl;
}
bool compareDescending(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first; // Sort by first element in descending order
}

int main() {
    int vertices = 5; // Number of vertices
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, INF));
    vector<vector<int>> next(vertices, vector<int>(vertices, -1));
       vector<pair<int,int> >vec(5); // To store the path
    for(int i=0;i<5;i++)
    {

        vec[i]={0,i};
    }
    // Initialize the adjacency matrix for the graph
    // Adding edges (directed graph with weights)
    adjMatrix[0][1] = 6; // Edge from 1 to 2 with weight 2
    adjMatrix[0][2] = 7; // Edge from 1 to 5 with weight 3
    adjMatrix[1][3] = 5; // Edge from 2 to 3 with weight 5
    adjMatrix[2][3] = -10; // Edge from 2 to 4 with weight 1
    adjMatrix[1][4] = -2; // Edge from 2 to 5 with weight 4
    adjMatrix[3][4] = -1; // Edge from 3 to 4 with weight 2
    adjMatrix[2][0] = 2; // Edge from 4 to 5 with weight 6

    // Initialize next array for path reconstruction
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i != j && adjMatrix[i][j] < INF) {
                next[i][j] = j; // Set next node
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (adjMatrix[i][k] < INF && adjMatrix[k][j] < INF && 
                    adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j]) {
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                    next[i][j] = next[i][k]; // Update path
                    
 vec[k].first++;
                }
            }
        }
    }

    // Print the shortest paths from each source node
    for (int i = 0; i < vertices; i++) {
        cout << "From node " << i  << ":\n";
        for (int j = 0; j < vertices; j++) {
            if (i != j) {
                cout << "Shortest path to " << j  << ": ";
                printPath(next, i, j);
            }
        }
        cout << endl;
    }

     cout<<"sorted"<<endl;
    sort(vec.begin(), vec.end(), compareDescending);
            for(int i=0;i<5;i++)
    {
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }

    return 0;
}
