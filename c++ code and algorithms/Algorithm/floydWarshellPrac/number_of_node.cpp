#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;


const int INF = numeric_limits<int>::max(); // Define infinity

void printPath(const vector<vector<int>>& next, int u, int v,vector<int>&visitCount) {
    if (next[u][v] == -1) {
        cout << "No path from " << u  << " to " << v  << endl;
        return;
    }
    cout << u ;
    visitCount[u]++;// Print the source node
    while (u != v) {
        u = next[u][v];
        cout << " -> " << u ;
        visitCount[u]++;// Print the path
    }
    cout << endl;
}

int main() {
    int vertices,edges ;
    cout<<"Enter the nodes and edge number"<<endl;
    cin>>vertices>>edges;
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, INF));
    vector<vector<int>> next(vertices, vector<int>(vertices, -1));
    vector<int> visitCount(vertices, 0);// To store the path
    // To count visits of each node
    cout<<"Enter edges"<<endl;
while(edges--)
{
    int u,v,w;
    cin>>u>>v>>w;
    adjMatrix[u][v]=w;
}
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
                if(adjMatrix[i][j]!=INF)
cout<<adjMatrix[i][j]<<" ";
else
    cout<<99<<" ";// Set next node
            }
            cout<<endl;
        }



    // Initialize next array for path reconstruction
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i != j && adjMatrix[i][j] < INF) {
                next[i][j] = j; // Set next node
                //If both conditions are satisfied, next[i][j] = j; indicates that the next vertex
                //on the path from i to j is j itself.
                //This means that if you want to go from i to j, you can directly go to j.
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {

cout<<next[i][j]<<" ";

            }
            cout<<endl;
        }

    // Floyd-Warshall algorithm
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (adjMatrix[i][k] < INF && adjMatrix[k][j] < INF &&
                    adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j]) {
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                    next[i][j] = next[i][k]; // Update path

                }
            }
        }
    }

    // Print the shortest paths from each source node
    for (int i = 0; i < vertices; i++) {
        cout << "From node " << i << ":\n";
        for (int j = 0; j < vertices; j++) {
            if (i != j) {
                cout << "Shortest path to " << j  << ": ";
                printPath(next, i, j,visitCount);
            }
        }
        cout << endl;
    }

    // Print the visit count for each node
    cout << "Visit count for each node:\n";
    for (int k = 0; k < vertices; k++) {
        cout << "Node " << k  << " was used in shortest paths: " << visitCount[k] << " times\n";
    }

    return 0;
}
/*

0 1 6
0 2 7
1 3 5
2 3 -10
1 4 -2
3 4 -1
2 0 2

*/
