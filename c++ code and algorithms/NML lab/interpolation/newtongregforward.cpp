
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the forward difference table
void forwardDifferenceTable(const vector<double>& x, const vector<double>& y, vector<vector<double>>& diffTable) {
    int n = y.size();
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }
}

// Function to perform Newton-Gregory Forward Interpolation
double newtonGregoryForwardInterpolation(const vector<double>& x, const vector<double>& y, double xValue) {
    int n = x.size();
    vector<vector<double>> diffTable(n, vector<double>(n));
    forwardDifferenceTable(x, y, diffTable);

    double h = x[1] - x[0];
    double u = (xValue - x[0]) / h;
    double result = diffTable[0][0];

    for (int i = 1; i < n; i++) {
        double term = diffTable[0][i];
        for (int j = 0; j < i; j++) {
            term *= (u - j) / (i - j);
        }
        result += term;
    }

    return result;
}

int main() {
    // Example data points
    vector<double> x = {0, 1, 2, 3};
    vector<double> y = {1, 2, 0, 5};

    double xValue;
    cout << "Enter the value of x to interpolate (Forward): ";
    cin >> xValue;

    double interpolatedValue = newtonGregoryForwardInterpolation(x, y, xValue);
    cout << "Interpolated value at x = " << xValue << " (Forward) is " << interpolatedValue << endl;

    return 0;
}
