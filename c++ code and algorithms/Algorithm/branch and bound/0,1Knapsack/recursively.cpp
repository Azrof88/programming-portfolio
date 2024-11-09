#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive function to solve the 0/1 Knapsack problem
int knapsackRecursive(int weights[], int costs[], int n, int maxWeight) {
    // Base case: no items left or no capacity left
    if (n == 0 || maxWeight == 0) {
        return 0;
    }

    // If the weight of the nth item is more than maxWeight, skip it
    if (weights[n - 1] > maxWeight) {
        return knapsackRecursive(weights, costs, n - 1, maxWeight);
    } else {
        // Return the maximum of two cases:
        // 1. nth item included
        // 2. nth item excluded
        return max(
            costs[n - 1] + knapsackRecursive(weights, costs, n - 1, maxWeight - weights[n - 1]),
            knapsackRecursive(weights, costs, n - 1, maxWeight)
        );
    }
}

// Function to find the items included in the optimal solution
void findIncludedItems(int weights[], int costs[], int n, int maxWeight) {
    vector<bool> included(n, false);
    int totalProfit = knapsackRecursive(weights, costs, n, maxWeight);
    int remainingWeight = maxWeight; // Track remaining weight to find included items

    // Trace back to find included items
    for (int i = n - 1; i >= 0; i--) {
        // If this item was included in the optimal solution
        if (totalProfit != knapsackRecursive(weights, costs, i, remainingWeight)) {
            included[i] = true;
            totalProfit -= costs[i]; // Deduct the cost of this item from totalProfit
            remainingWeight -= weights[i]; // Reduce remaining weight
        }
    }

    cout << "Weights of items taken: ";
    for (int i = 0; i < n; i++) {
        if (included[i]) {
            cout << weights[i] << " ";
        }
    }
    cout << "\nTotal cost: " << knapsackRecursive(weights, costs, n, maxWeight) << endl; // Correctly show total cost
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

    // Call the function to find the total cost and included items
    findIncludedItems(weights, costs, n, maxWeight);

    return 0;
}
