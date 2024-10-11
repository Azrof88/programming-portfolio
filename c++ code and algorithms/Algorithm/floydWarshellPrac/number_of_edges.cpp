#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

const int INF = numeric_limits<int>::max(); // Define infinity

void printPath(const vector<vector<int>>& next, int u, int v,vector<int>& visitCount,vector< vector<int> >& edgeCount)
{
    if (next[u][v] == -1)
    {
        cout << "No path from " << u+1  << " to " << v+1 << endl;
        return;
    }
    cout << u +1;
    visitCount[u]++; // Print the source node
    while (u != v)
    {
        edgeCount[u][next[u][v]]++;
        u = next[u][v];
        visitCount[u]++;
        cout << " -> " << u+1 ; // Print the path
    }
    cout << endl;
}

int main()
{
    int vertices,edges; ; // Number of vertices
        cout<<"Enter number of vertices & edges"<<endl;
    cin>>vertices>>edges;
    vector<vector<int> > adjMatrix(vertices, vector<int>(vertices, INF));
    vector<vector<int> > next(vertices, vector<int>(vertices, -1));
    vector<vector<int> > edgeCount(vertices, vector<int>(vertices, 0)); //
    vector<int> visitCount(vertices, 0); // To store the path
//To count visits of each node
    //To count edge usage

    while(edges--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adjMatrix[x][y]=z;
    }





    // Initialize next array for path reconstruction
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i != j && adjMatrix[i][j] < INF)
            {
                next[i][j] = j; // Set next node
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (adjMatrix[i][k] != INF && adjMatrix[k][j] != INF &&
                        adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
                {
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                    next[i][j] = next[i][k]; // Update path
                    //   visitCount[k]++; // Increment visit count for node k
                    //  visitCount[i]++; // Increment visit count for source node i
                    //    visitCount[j]++; // Increment visit count for destination node j
                    // edgeCount[i][j]++; // Increment edge usage count from i to j
                }
            }
        }
    }

    // Print the shortest paths from each source node
    for (int i = 0; i < vertices; i++)
    {
        cout << "From node " << i +1 << ":\n";
        for (int j = 0; j < vertices; j++)
        {
            if (i != j)
            {
                cout << "Shortest path to " << j +1<< ": ";
                printPath(next, i, j,visitCount,edgeCount);
            }
        }
        cout << endl;
    }

    // Print the visit count for each node
    cout << "Visit count for each node:\n";
    for (int k = 0; k < vertices; k++)
    {
        cout << "Node " << k+1 << " was used in shortest paths: " << visitCount[k] << " times\n";
    }

    // Print edge usage counts
    cout << "Edge usage counts:\n";
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (edgeCount[i][j] > 0)
            {
                cout << "Edge from " << i+1 << " to " << j+1  << ": " << edgeCount[i][j] << " times\n";
            }
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout<<next[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

/*
0 1 4
0 2 1
1 2 2
1 3 5
2 3 3

*/
