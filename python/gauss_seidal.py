import numpy as np
import matplotlib.pyplot as plt

def gauss_seidel(a, b, max_iterations, tolerance):
    n = len(b)
    # Initialize x with zeros
    x = np.zeros(n)
    mae_list = []

    print(f"{'Iteration':<10}{'xi':<10}{'yi':<10}{'zi':<10}{'x(i+1)':<10}{'y(i+1)':<10}{'z(i+1)':<10}{'ex':<10}{'ey':<10}{'ez':<10}{'mae':<10}{'mse':<10}{'rmse':<10}")

    for iteration in range(max_iterations):
        x_new = x.copy()  # Create a copy for the new values

        # Update each variable
        for i in range(n):
            sum_ax = np.dot(a[i], x_new) - a[i][i] * x_new[i]
            x_new[i] = (b[i] - sum_ax) / a[i][i]

        # Calculate errors
        ex = abs(x_new[0] - x[0]) if n > 0 else 0
        ey = abs(x_new[1] - x[1]) if n > 1 else 0
        ez = abs(x_new[2] - x[2]) if n > 2 else 0
        
        # Calculate MAE, MSE, RMSE
        mae = (ex + ey + ez) / n
        mse = (ex**2 + ey**2 + ez**2) / n
        rmse = np.sqrt(mse)

        # Print the values in a formatted table
        print(f"{iteration + 1:<10}{x[0]:<10.4f}{x[1]:<10.4f}{x[2]:<10.4f}{x_new[0]:<10.4f}{x_new[1]:<10.4f}{x_new[2]:<10.4f}{ex:<10.4f}{ey:<10.4f}{ez:<10.4f}{mae:<10.4f}{mse:<10.4f}{rmse:<10.4f}")

        # Check for convergence
        if np.linalg.norm(x_new - x) < tolerance:
            print(f'Converged after {iteration + 1} iterations.')
            break

        x = x_new
        mae_list.append(mae)

    return x, mae_list, mse, mae, rmse

def calculate_errors(true_values, estimated_values):
    mse = np.mean((true_values - estimated_values) ** 2)
    mae = np.mean(np.abs(true_values - estimated_values))
    rmse = np.sqrt(mse)
    return mse, mae, rmse

if __name__ == "__main__":
    # Prompt for the number of equations/variables
    n = int(input("Enter the number of equations (and variables): "))

    # Input the coefficients
    print(f"Enter the coefficients of the equations ({n}x{n + 1} matrix):")
    a = np.zeros((n, n))  # Coefficient matrix
    b = np.zeros(n)       # Constants vector

    for i in range(n):
        row = list(map(float, input(f'Row {i + 1} (coefficients followed by constant): ').split()))
        a[i] = row[:-1]  # Fill the coefficients
        b[i] = row[-1]   # Fill the constant term

    # Input the maximum number of iterations and tolerance
    max_iterations = int(input("Enter the maximum number of iterations: "))
    tolerance = float(input("Enter the tolerance for convergence: "))

    # Define true values (replace with actual known values)
    true_values = np.array([1, 1, 1])  # Example true values for three variables

    # Perform Gauss-Seidel iteration
    final_solution, mae_list, mse, mae, rmse = gauss_seidel(a, b, max_iterations, tolerance)

    # Calculate errors using true values
    mse, mae, rmse = calculate_errors(true_values, final_solution)

    # Print final error metrics
    print(f'Final Solution: {final_solution}')
    print(f'Mean Square Error: {mse}')
    print(f'Mean Absolute Error: {mae}')
    print(f'Root Mean Square Error: {rmse}')

    # Plotting MAE using Matplotlib
    plt.plot(mae_list, marker='o')
    plt.title('Mean Absolute Error (MAE) vs. Iteration')
    plt.xlabel('Iteration')
    plt.ylabel('Mean Absolute Error')
    plt.grid()
    plt.show()
