#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// Function to calculate the upper bound for a given node
double calculateBound(int level, int profit, int weight, int maxWeight, int weights[], int costs[], int n) {
    if (weight >= maxWeight) return 0; // Weight exceeded

    double profitBound = profit;
    int j = level + 1;
    int remainingWeight = maxWeight - weight;

    // Greedily add items to the profit bound
    while (j < n && weights[j] <= remainingWeight) {
        remainingWeight -= weights[j];
        profitBound += costs[j];
        j++;
    }

    // Add fraction of the next item if possible
    if (j < n) {
        profitBound += costs[j] * ((double)remainingWeight / weights[j]);
    }

    return profitBound;
}

// Function to solve the 0/1 Knapsack problem using Branch and Bound
void knapsack(int maxWeight, int weights[], int costs[], int n) {
    priority_queue<pair<double, tuple<int, int, int>>> pq; // Max-heap for nodes: (bound, (level, profit, weight))

    pq.push({calculateBound(-1, 0, 0, maxWeight, weights, costs, n), {-1, 0, 0}});

    int maxProfit = 0;
    vector<bool> bestTaken(n, false); // To store the best items taken

    // Explore the nodes
    while (!pq.empty()) {
        pair<double, tuple<int, int, int>> topElement = pq.top();
        pq.pop();

        double bound = topElement.first;
        tuple<int, int, int> state = topElement.second;

        int level = get<0>(state);
        int profit = get<1>(state);
        int weight = get<2>(state);

        // If this node is promising
        if (bound > maxProfit) {
            // Check the next level (include the next item)
            if (level + 1 < n) {
                int newLevel = level + 1;
                int newWeight = weight + weights[newLevel];
                int newProfit = profit + costs[newLevel];

                // Track the best items taken
                vector<bool> currentTaken = bestTaken; // Copy the bestTaken vector
                currentTaken[newLevel] = true; // Mark the current item as taken

                // Update if this solution is better
                if (newWeight <= maxWeight && newProfit > maxProfit) {
                    maxProfit = newProfit;
                    bestTaken = currentTaken; // Store the best items
                }

                double newBound = calculateBound(newLevel, newProfit, newWeight, maxWeight, weights, costs, n);
                if (newWeight <= maxWeight && newBound > maxProfit) {
                    pq.push({newBound, {newLevel, newProfit, newWeight}});
                }
            }

            // Check the next level (exclude the next item)
            int newLevel = level + 1;
            double excludeBound = calculateBound(newLevel, profit, weight, maxWeight, weights, costs, n);
            if (excludeBound > maxProfit) {
                pq.push({excludeBound, {newLevel, profit, weight}});
            }
        }
    }

    // Output the result
    cout << "Weights of items taken: ";
    for (int i = 0; i < n; i++) {
        if (bestTaken[i]) {
            cout << weights[i] << " ";
        }
    }
    cout << "\nTotal cost: " << maxProfit << endl;
}

int main() {
    int n; // Number of items
    int maxWeight; // Maximum weight of the knapsack

    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n], costs[n];

    // Input weights and costs
    cout << "Enter weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter costs of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> maxWeight;

    // Call knapsack function
    knapsack(maxWeight, weights, costs, n);

    return 0;
}
