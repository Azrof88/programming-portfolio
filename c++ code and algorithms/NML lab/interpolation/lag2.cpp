#include <iostream>
#include <vector>

using namespace std;

// Function to perform Lagrange interpolation
double lagrangeInterpolation(const vector<int>& months, const vector<double>& weights, int targetMonth) {
    double result = 0.0;
    int n = months.size();

    for (int i = 0; i < n; i++) {
        double term = weights[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (static_cast<double>(targetMonth) - months[j]) / (months[i] - months[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    // Input known month-weight pairs
    int n;
    cout << "Enter the number of known data points (months and weights): ";
    cin >> n;

    vector<int> months(n);
    vector<double> weights(n);

    cout << "Enter the month (0-12) and corresponding weight (in pounds):\n";
    for (int i = 0; i < n; i++) {
        cout << "Data point " << (i + 1) << ": ";
        cin >> months[i] >> weights[i];
    }

    // Estimate weight at 12 months
    int targetMonth = 12;
    double estimatedWeight = lagrangeInterpolation(months, weights, targetMonth);

    cout << "Estimated weight at " << targetMonth << " months: " << estimatedWeight << " pounds" << endl;

    return 0;
}
