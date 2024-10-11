#include <bits/stdc++.h>

using namespace std;

int main()
{
    int node, edge;
    cout << "Enter number of nodes & edges: ";
    cin >> node >> edge;

    vector<pair<int, int>> v[node+1]; // adjacency list
    vector<pair<int, pair<int, int>>> edges; // to store all edges with weights

    cout << "Enter edges (weight from to):" << endl;
    for (int i = 0; i < edge; i++)
    {
        int wt, from, to;
        cin >> from >> to>>wt;
        v[from].push_back({wt, to});
        v[to].push_back({wt, from});
        edges.push_back({wt, {from, to}});
    }

    // Input for required edges
    int k;
    cout << "Enter number of required edges: ";
    cin >> k;

    vector<int> requiredEdges(k);
    cout << "Enter the indices of required edges (1-based): ";
    for (int i = 0; i < k; i++)
    {
        cin >> requiredEdges[i];
       requiredEdges[i]--; // Convert to 0-based index for internal processing
    }

    // Mark required edges in a set for easy access
    set<pair<int, int>> requiredSet;
    for (int index : requiredEdges) {
        requiredSet.insert(edges[index].second); // add (from, to) pair
        requiredSet.insert({edges[index].second.second, edges[index].second.first}); // add (to, from) pair
    }
    for(auto it:requiredSet)
    {

        cout<<it.first<<" "<<it.second;
        cout<<endl;
    }

    int visit[node] = {0}; // visited array
    int parent[node] = {-1}; // parent array
    int sum = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Include required edges first
    for (int index : requiredEdges) {
        int wt = edges[index].first;
        int from = edges[index].second.first;
        int to = edges[index].second.second;

        if (visit[from] == 0 && visit[to] == 0) {
            // If both nodes are unvisited, we can add this edge
            pq.push({wt, {to, from}});
            visit[to] = 1; // Mark one of the nodes as visited
            parent[to] = from;
            sum += wt;
        } else if (visit[from] == 1 && visit[to] == 0) {
            // If 'from' is visited but 'to' is not
            pq.push({wt, {to, from}});
            visit[to] = 1; // Mark 'to' as visited
            parent[to] = from;
            sum += wt;
        } else if (visit[to] == 1 && visit[from] == 0) {
            // If 'to' is visited but 'from' is not
            pq.push({wt, {from, to}});
            visit[from] = 1; // Mark 'from' as visited
            parent[from] = to;
            sum += wt;
        } else {
            // If both are visited, this edge would create a cycle
            cout << "-1" << endl;
            return 0;
        }
    }

    // Continue with Prim's algorithm
    while (!pq.empty())
    {
        auto it = pq.top();
        int wt = it.first;
        int to = it.second.first;
        int from = it.second.second;
        pq.pop();

        if (visit[to] != 1)
        {
            visit[to] = 1;
            parent[to] = from;
            sum += wt;

            for (auto edges : v[to])
            {
                int weight = edges.first;
                int nextto = edges.second;

                if (visit[nextto] != 1)
                {
                    pq.push({weight, {nextto, to}});
                }
            }
        }
    }

    // Check if all nodes are visited (connected graph)
    for (int i = 0; i < node; i++) {
        if (visit[i] == 0) {
            cout << "-1" << endl; // Not all nodes are connected
            return 0;
        }
    }

    cout << "Total weight of MST including required edges: " << sum << endl;

    // Show the path of the spanning tree
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 0; i < node; i++)
    {
        if (parent[i] != -1) // If the node has a parent
        {
            cout << parent[i] << " -- " << i << endl; // Print the edge
        }
    }

    return 0;
}
/*
1 2 2
1 3 3
2 3 1
3 4 4
4 5 5
2 5 8
5 6 6
4 6 7

*/
