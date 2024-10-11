
#include <bits/stdc++.h>>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>

using namespace std;

struct Point {
    double x, y;
};

// Function to calculate Euclidean distance between two points
double euclideanDistance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to find the minimum cost to connect all points
int minCostConnectPoints(vector<Point>& points, int k) {
    int n = points.size();
    vector<bool> inMST(n, false);
    vector<double> minCost(n, INT_MAX);
    minCost[0] = 0; // Start from the first point
    int totalCost = 0;

    for (int i = 0; i < n; ++i) {
        double minEdge = INT_MAX;
        int u = -1;

        // Find the point with the minimum cost to add to the MST
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && minCost[j] < minEdge) {
                minEdge = minCost[j];
                u = j;
            }
        }

        // If we couldn't find a valid point, break out (shouldn't happen)
        if (u == -1) break;

        // Add the selected point to the MST
        inMST[u] = true;
        totalCost += minEdge;

        // Update the costs of connecting other points to the MST
        for (int v = 0; v < n; ++v) {
            if (!inMST[v]) {
                double distance = euclideanDistance(points[u], points[v]);
                // Choose the minimum cost between direct connection and special connection
                double cost = min(distance, static_cast<double>(k));
                minCost[v] = min(minCost[v], cost);
            }
        }
    }

    return totalCost;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    int result = minCostConnectPoints(points, k);
    cout << result << endl;

    return 0;
}
