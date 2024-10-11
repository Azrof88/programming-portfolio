#include<bits/stdc++.h>

using namespace std;


int main()
{

    int node,edge;
    cin>>node>>edge;
    
    // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Adjacency list for weighted graph

while(edge--)
{
    int x,y,z;
    cin>>x>>y>>z;
    adjList[x].push_back({y,z});

}

    // Convert adjacency list to adjacency matrix
    vector<vector<int>> adjMatrix(node, vector<int>(node, 0));

    // Initialize adjacency matrix with a high value for no direct edge
    const int INF = numeric_limits<int>::max();
    for (int i = 0; i < node; i++) {
        for (int j = 0; j <node; j++) {
            if (i != j) {
                adjMatrix[i][j] = INF; // No edge initially
            }
        }
    }

    // Fill the adjacency matrix with weights
    for (int i = 0; i < node; i++) {
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

    


//floyed warshell
    for(int via=0;via<node;via++)
    {
        for(int i=0;i<node;i++)
        {
            for(int j=0;j<node;j++)
            {
                if (adjMatrix[i][j] > (adjMatrix[i][via] + adjMatrix[via][j])
                    && (adjMatrix[via][j] != INF
                        && adjMatrix[i][via] != INF))
                    adjMatrix[i][j] = adjMatrix[i][via] + adjMatrix[via][j];

            }
        }
    }


}
