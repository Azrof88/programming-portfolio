import numpy as np
import matplotlib.pyplot as plt

def jacobi_iteration(a, b, x_init, max_iterations, tolerance):
    n = len(b)
    x = x_init.copy()
    errors = []

    for iteration in range(max_iterations):
        x_new = np.zeros(n)

        for i in range(n):
            sum_ax = np.dot(a[i], x) - a[i][i] * x[i]
            x_new[i] = (b[i] - sum_ax) / a[i][i]

        # Calculate errors
        error = np.linalg.norm(x_new - x)
        errors.append(error)

        # Check for convergence
        if error < tolerance:
            print(f'Converged after {iteration + 1} iterations.')
            break

        x = x_new
        print(f'Iteration {iteration + 1}: {x}')

    return x, errors

def calculate_errors(true_values, estimated_values):
    mse = np.mean((true_values-estimated_values) ** 2)
    mae = np.mean(np.abs(true_values-estimated_values))
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

    # Initial guess
    x_init = np.zeros(n)

    # Perform Jacobi iteration
    final_solution, errors = jacobi_iteration(a, b, x_init, max_iterations, tolerance)

    # Calculate errors
    true_values = np.array([1] * n)  # Replace with actual true values if known
    mse, mae, rmse = calculate_errors(true_values, final_solution)

    print(f'Mean Square Error: {mse}')
    print(f'Mean Absolute Error: {mae}')
    print(f'Root Mean Square Error: {rmse}')

    # Plotting the errors using Matplotlib
    plt.plot(errors, marker='o')
    plt.title('Jacobi Iteration Errors')
    plt.xlabel('Iteration')
    plt.ylabel('Error')
    plt.yscale('log')  # Log scale for better visibility
    plt.grid()
    plt.show()
