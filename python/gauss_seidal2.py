import numpy as np
import matplotlib.pyplot as plt

def gauss_seidel(a, b, max_iterations, tolerance):
    n = len(b)
    # Initialize x, y, z with zeros
    x = np.zeros(n)
    mae_list = []

    print(f"{'Iteration':<10}{'xi':<10}{'yi':<10}{'zi':<10}{'x(i+1)':<10}{'y(i+1)':<10}{'z(i+1)':<10}{'ex':<10}{'ey':<10}{'ez':<10}{'mae':<10}{'mse':<10}{'rmse':<10}")

    for iteration in range(max_iterations):
        x_new = x.copy()  # Create a copy for the new values

        # First iteration: Set y and z to 0
        if iteration == 0:
            y = 0
            z = 0
            x_new[0] = (b[0] - (a[0][1] * y + a[0][2] * z)) / a[0][0]
            x_new[1] = y  # y remains 0
            x_new[2] = z  # z remains 0
        else:
            # Use previous iteration values
            y = x_new[1]  # Previous y
            z = x_new[2]  # Previous z
            
            # Calculate new x
            x_new[0] = (b[0] - (a[0][1] * y + a[0][2] * z)) / a[0][0]
            
            # Calculate new z using the latest x and previous y
            x_new[2] = (b[2] - (a[2][0] * x_new[0] + a[2][1] * y)) / a[2][2]
            
            # Calculate new y using the latest x and z
            x_new[1] = (b[1] - (a[1][0] * x_new[0] + a[1][2] * x_new[2])) / a[1][1]

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

    return x, mae_list

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

    # Perform Gauss-Seidel iteration
    final_solution, mae_list = gauss_seidel(a, b, max_iterations, tolerance)

    # Plotting MAE using Matplotlib
    plt.plot(mae_list, marker='o')
    plt.title('Mean Absolute Error (MAE) vs. Iteration')
    plt.xlabel('Iteration')
    plt.ylabel('Mean Absolute Error')
    plt.grid()
    plt.show()
