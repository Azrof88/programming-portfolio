#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int minCost(int n, int k, double points[][2]) {
    vector<bool> inMST(n, false);
    vector<double> minimumCost(n, numeric_limits<double>::max());
    minimumCost[0] = 0;
    double totalCost = 0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        pair<double, int> top = pq.top();
        double cost = top.first;
        int u = top.second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalCost += cost;

        for (int v = 0; v < n; ++v) {
            if (!inMST[v]) {
                double distance = dist(points[u][0], points[u][1], points[v][0], points[v][1]);
                double newCost = min(distance, (double)(k));
                if (newCost < minimumCost[v]) {
                    minimumCost[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }
    }

    return totalCost;
}

int main() {
    int n, k;
    cin >> n >> k;

    double point[n][2];
    for (int i = 0; i < n; ++i) {
        cin >> point[i][0] >> point[i][1];
    }

    int result = minCost(n, k, point);
    cout << result << endl;

    return 0;
}
