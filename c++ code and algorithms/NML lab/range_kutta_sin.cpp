#include <bits/stdc++.h>
using namespace std;

// Differential equation "dy/dx = sin(x)"
float dydx(float x, float y)
{
    return sin(x);
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
void rungeKutta(float x0, float y0, float x_end, float h)
{
    // Count number of iterations using step size or
    // step height h
    int n = (int)((x_end - x0) / h);

    float k1, k2, k3, k4;

    // Iterate for number of iterations
    float y = y0;
    cout << "x\t\ty" << endl; // Header for the output
    cout << fixed << setprecision(4); // Set precision for output

    for (int i = 0; i <= n; i++)
    {
        // Print the current value of x and y
        cout << x0 << "\t\t" << y << endl;

        // Apply Runge Kutta Formulas to find next value of y
        k1 = h * dydx(x0, y);
        k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * dydx(x0 + h, y + k3);

        // Update next value of y
        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);

        // Update next value of x
        x0 = x0 + h;
    }
}

// Driver Code
int main()
{
    float x0 = 0, y = 0, x_end = 4 * M_PI, h = 0.1; // Initial condition y(0) = 0
    rungeKutta(x0, y, x_end, h);

    return 0;
}
