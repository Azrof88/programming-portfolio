import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import csv

# Differential equation dy/dx = x - y
def dydx(x, y):
    return x - y

# Exact solution of the differential equation
def exact_solution(x):
    return x - 1 + np.exp(-x)  # Derived from the equation

# Finds value of y for a given x using step size h
def runge_kutta(x0, y0, x, h):
    n = int((x - x0) / h)
    y = y0

    for _ in range(n):
        k1 = h * dydx(x0, y)
        k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1)
        k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2)
        k4 = h * dydx(x0 + h, y + k3)

        y += (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4)
        x0 += h

    return y

# Driver Code
x0 = 0
y0 = 1
x_end = 10
h = 0.1
mean_error = 0.0
steps = int((x_end - x0) / h)

# Arrays to store values for plotting
x_values = []
y_values = []
ye_values = []
errors = []

# Open a CSV file to write output
with open('output.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["X", "Y", "Ye", "abs(Y - Ye)"])  # Write header

    for i in range(steps + 1):
        current_x = x0 + i * h
        Y = runge_kutta(x0, y0, current_x, h)
        Ye = exact_solution(current_x)
        error = abs(Y - Ye)

        # Write data to CSV
        writer.writerow([current_x, Y, Ye, error])

        x_values.append(current_x)
        y_values.append(Y)
        ye_values.append(Ye)
        errors.append(error)

        mean_error += error

mean_error /= (steps + 1)  # Calculate mean error
print(f"Mean Error: {mean_error:.6f}")

# Write mean error to the CSV
with open('output.csv', mode='a', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["Mean Error", "", "", mean_error])  # Write mean error row

# Plotting
with PdfPages('output_graphs.pdf') as pdf:
    # First graph: X vs Y (Runge-Kutta Approximation)
    plt.figure()
    plt.plot(x_values, y_values, label='Runge-Kutta Approximation', color='blue')
    plt.plot(x_values, ye_values, label='Exact Solution', color='orange', linestyle='dashed')
    plt.title('Runge-Kutta Approximation and Exact Solution vs X')
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.legend()
    plt.grid()
    pdf.savefig()  # Save the current figure into the PDF
    plt.close()

    # Second graph: X vs abs(Y - Ye) (Error)
    plt.figure()
    plt.plot(x_values, errors, label='Absolute Error', color='red')
    plt.title('Absolute Error vs X')
    plt.xlabel('X')
    plt.ylabel('abs(Y - Ye)')
    plt.legend()
    plt.grid()
    pdf.savefig()  # Save the current figure into the PDF
    plt.close()

print("Graphs have been saved to 'output_graphs.pdf'.")
