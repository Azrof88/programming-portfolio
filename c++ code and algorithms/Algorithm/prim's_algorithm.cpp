#include<bits/stdc++.h>

using namespace std;

int main()
{
    int node, edge;
    cout << "Enter number of nodes & edges: ";
    cin >> node >> edge;
    vector<pair<int, int>> v[node];
    while (edge--)
    {
        int wt, from, to;
        cin >> wt >> from >> to;
        v[from].push_back({wt, to});
        v[to].push_back({wt, from});
    }

    int visit[node] = {0}; // start from vertex 0
    int parent[node] = {-1}; // start from 0
    int sum = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    int st_node;
    cout << "Enter the starting node: ";
    cin >> st_node;
    pq.push({0, {st_node, -1}});

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

                // Check if the next node is not visited
                if (visit[nextto] != 1)
                {
                    pq.push({weight, {nextto, to}});
                }
            }
        }
        else
        {
            // If we encounter a visited node, it means a cycle would be formed
            cout << "Cycle detected while processing node: " << to << endl;
        }
    }

    cout << "Minimum sum is " << sum << endl;

    // Show the path of the spanning tree
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 0; i < node; i++)
    {
        if (parent[i] != -1) // If the node has a parent
        {
            cout << parent[i] << " -- " << i << endl; // Print the edge
        }
    }
}
