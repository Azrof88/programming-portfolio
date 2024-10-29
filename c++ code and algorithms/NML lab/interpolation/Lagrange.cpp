#include <iostream>
#include <vector>

using namespace std;

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
    vector<int> months = {0, 2, 3, 5, 6};
    vector<double> weights = {5, 7, 8, 10, 12};

    int targetMonth = 12;

    double estimatedWeight = lagrangeInterpolation(months, weights, targetMonth);

    cout << "Estimated weight at " << targetMonth << " months: " << estimatedWeight * 0.453592 << " Kg" << endl;

    return 0;
}
