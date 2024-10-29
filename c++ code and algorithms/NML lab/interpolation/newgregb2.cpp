#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the backward difference table
void backwardDifferenceTable(const vector<double>& y, vector<vector<double>>& diffTable) {
    int n = y.size();
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
        }
    }
}

// Function to perform Newton-Gregory Backward Interpolation
double newtonGregoryBackwardInterpolation(const vector<double>& x, const vector<double>& y, double xValue) {
    int n = x.size();
    vector<vector<double>> diffTable(n, vector<double>(n));
    backwardDifferenceTable(y, diffTable);

    double h = x[1] - x[0]; // Assuming uniform spacing
    double u = (xValue - x[n - 1]) / h; // Using the last x value
    double result = diffTable[n - 1][0];

    for (int i = 1; i < n; i++) {
        double term = diffTable[n - 1][i];
        for (int j = 0; j < i; j++) {
            term *= (u + j) / (i - j);
        }
        result += term;
    }

    return result;
}

int main() {
    // Example data points for x in degrees and sin(x)
    vector<double> x = {10, 20, 30, 40, 50}; // x values in degrees
    vector<double> y = {
        sin(10 * M_PI / 180),
        sin(20 * M_PI / 180),
        sin(30 * M_PI / 180),
        sin(40 * M_PI / 180),
        sin(50 * M_PI / 180)
    }; // sin(x) values in radians

    double xValue = 25; // Value to interpolate
    cout << "Interpolating for x = " << xValue << " degrees..." << endl;

    double interpolatedValue = newtonGregoryBackwardInterpolation(x, y, xValue);
    cout << "Interpolated value at x = " << xValue << " degrees (Backward) is " << interpolatedValue << endl;

    return 0;
}
