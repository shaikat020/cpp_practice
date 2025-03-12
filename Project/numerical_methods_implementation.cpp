#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

#define f1_case1(x, y, z) (85 - 6 * y + z) / 27
#define f2_case1(x, y, z) (72 - 6 * x - 3 * z) / 15
#define f3_case1(x, y, z) (110 - x - y) / 54

#define f1_case2(x, y, z) (12.6 - 2 * y + 2 * z) / 26
#define f2_case2(x, y, z) (-14.3 - 3 * x - z) / 27
#define f3_case2(x, y, z) (6.01 - 2 * x - 3 * y) / 17

double Bisection_method(double (*f)(double), double a, double b, double tol = 1e-10, int maxIter = 100);
double Newton_raphson_method(double (*f)(double), double (*df)(double), double x0, double tol = 1e-10, int maxIter = 100);
double Secant_method(double (*f)(double), double x0, double x1, double tol = 1e-10, int maxIter = 100);
double Fixed_point_Iteration(double (*g)(double), double x0, double tol = 1e-10, int maxIter = 100);
double f(double x);
double df(double x);
double g(double x);

// Function prototypes
void gaussianElimination(double matrix[10][11], double result[10], int n);
void gaussJordan(double matrix[10][11], double result[10], int n);
void jacobiMethod();
void gaussSeidelMethod(int choice);


int main() {
    int choice, equationChoice;
    while(1)
    {

    cout <<endl<< "Choose the type of equation:\n";
    cout << "1. Linear Equation\n";
    cout << "2. Non-Linear Equation\n";
    cout<< "3. Exit"<<endl<<endl<<endl;
    cin >> choice;

    if (choice == 1) {
        cout << "Choose the numerical method for Linear Equations:\n";
        cout << "1. Gaussian Elimination\n";
        cout << "2. Gauss-Jordan Elimination\n";
        cout << "3. Gauss-Seidel Method\n"<<endl<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
            {
                int n;
                double matrix[10][11], result[10];
                cout << "Enter the number of equations: ";
                cin >> n;
                cout << "Enter the coefficients and constants (row-wise):" << endl;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n + 1; j++)
                    {
                        cout<<"a["<< i<<"]"<< j<<"]= ";
                        cin >> matrix[i][j];
                    }
                }
                gaussianElimination(matrix, result, n);

                cout << "The solution is:" << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << "x" << i + 1 << " = " << result[i] << endl;
                }
                break;
            }
            case 2:
                cout << "Gauss-Jordan Elimination Method selected.\n";
                int n;
                double matrix[10][11], result[10];
                cout << "Enter the number of equations: ";
                cin >> n;
                cout << "Enter the coefficients and constants (row-wise):" << endl;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n + 1; j++)
                    {
                        cin >> matrix[i][j];
                    }
                }
                gaussJordan(matrix, result, n);

                cout << "The solution is:" << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << "x" << i + 1 << " = " << static_cast<int>(round(result[i])) << endl;
                }
            break;
            case 3:
            {
                cout << "Gauss-Seidel Method selected.\n";
                cout << "Choose the set of linear equations:\n";
                cout << "1. 27x + 6y - z = 85\n   6x + 15y + 3z = 72\n   x + y + 54z = 110\n";
                cout << "2. 26x + 2y + 2z = 12.6\n   3x + 27y + z = -14.3\n   2x + 3y + 17z = 6.01\n";
                cout << endl<<endl<< "Enter your choice (1 or 2): ";
                cin >> equationChoice;
                gaussSeidelMethod(equationChoice);
                break;
            }
            default: cout << "Invalid choice!\n"; break;
        }
    }
    else if (choice == 2)
    {
        int choice;
        double a, b, x0, x1, root;

        cout<<endl<<"Let,\nThe equation is 3x - cos x -1"<<endl<<endl;

        cout << "Select a method for solving the non-linear equation:" << endl;
        cout << "1. Bisection Method" << endl;
        cout << "2. Newton-Raphson Method" << endl;
        cout << "3. Secant Method" << endl;
        cout << "4. Fixed Point Iteration" << endl<<endl<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the interval [a, b]: ";
                cin >> a >> b;
                root = Bisection_method(f, a, b);
                break;
            case 2:
                cout << "Enter the initial guess x0: ";
                cin >> x0;
                root = Newton_raphson_method(f, df, x0);
                break;
            case 3:
                cout << "Enter the initial guesses x0 and x1: ";
                cin >> x0 >> x1;
                root = Secant_method(f, x0, x1);
                break;
            case 4:
                cout << "Enter the initial guess x0: ";
                cin >> x0;
                root = Fixed_point_Iteration(g, x0);
                break;
            default:
                cout << "Invalid choice." << endl;
            //return;
        }


        cout << "The root is: " << root << endl;
    }
    else if(choice == 3)
    {
        cout<<"Thank you."<<endl;
        return 0;
    }
    else
    {
        cout<<"Invalid!!";
    }
    }
}

// Implementations of the methods
void gaussianElimination(double matrix[10][11], double result[10], int n) {
    // Implementation of Gaussian Elimination
    cout << "Gaussian Elimination method selected.\n";
        int stepCount = 0; // Initialize step counter

    // Forward elimination process
    for (int i = 0; i < n; i++)
    {
        // Partial pivoting: find the maximum element in the current column
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i]))
            {
                maxRow = k;
            }
        }

        // Swap the maximum row with the current row
        for (int k = 0; k < n + 1; k++)
        {
            swap(matrix[maxRow][k], matrix[i][k]);
        }
        stepCount++; // Count the swap as a step

        // Make the diagonal element 1 (normalization)
        double diag = matrix[i][i];
        for (int j = i; j < n + 1; j++)
        {
            matrix[i][j] /= diag;
        }
        stepCount++; // Count the normalization as a step

        // Eliminate the elements below the pivot
        for (int k = i + 1; k < n; k++)
        {
            double factor = matrix[k][i];
            for (int j = i; j < n + 1; j++)
            {
                matrix[k][j] -= factor * matrix[i][j];
            }
            stepCount++; // Count each row elimination as a step
        }
    }

    // Back substitution process
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++)
        {
            result[i] -= matrix[i][j] * result[j];
        }
        stepCount++; // Count each step in the back substitution as a step
    }

    // Output the total step count
    cout << endl
         << "Total steps needed: " << stepCount << endl;

}

void gaussJordan(double matrix[10][11], double result[10], int n)
{
    int stepCount = 0; // Initialize step counter

    // Forward elimination process
    for (int i = 0; i < n; i++)
    {
        // Partial pivoting: find the maximum element in the current column
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i]))
            {
                maxRow = k;
            }
        }

        // Swap the maximum row with the current row
        for (int k = 0; k < n + 1; k++)
        {
            swap(matrix[maxRow][k], matrix[i][k]);
        }
        stepCount++; // Count the swap as a step

        // Normalize the current row
        double diag = matrix[i][i];
        if (fabs(diag) < 1e-10)
        {
            cout << "Matrix is singular or nearly singular." << endl;
            return;
        }
        for (int j = 0; j < n + 1; j++)
        {
            matrix[i][j] /= diag;
        }
        stepCount++; // Count the normalization as a step

        // Eliminate all other rows
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = matrix[k][i];
                for (int j = 0; j < n + 1; j++)
                {
                    matrix[k][j] -= factor * matrix[i][j];
                }
                stepCount++; // Count the row elimination as a step
            }
        }
    }

    // Output the result and the step count
    cout << endl
         << "Total steps needed: " << stepCount << endl;

    // Extract the results from the matrix
    for (int i = 0; i < n; i++)
    {
        result[i] = matrix[i][n];
    }
}



void gaussSeidelMethod(int choice)
{
    const float EPSILON = 0.001; // Define the epsilon value
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3;
    int step = 1;
    bool continueIteration = true;

    cout << fixed << setprecision(3);

    do
    {
        switch (choice)
        {
        case 1:
            x1 = f1_case1(x0, y0, z0);
            y1 = f2_case1(x1, y0, z0); // Use the updated x1 for y1 calculation
            z1 = f3_case1(x1, y1, z0); // Use the updated x1 and y1 for z1 calculation
            break;
        case 2:
            x1 = f1_case2(x0, y0, z0);
            y1 = f2_case2(x1, y0, z0); // Use the updated x1 for y1 calculation
            z1 = f3_case2(x1, y1, z0); // Use the updated x1 and y1 for z1 calculation
            break;
        default:
            cout << "Invalid equation choice!" << endl;
            return;
        }

        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);

        if (e1 <= EPSILON && e2 <= EPSILON && e3 <= EPSILON)
        {
            continueIteration = false;
        }
        x0 = x1;
        y0 = y1;
        z0 = z1;
        step++;

    } while (continueIteration);
    cout << endl<< "Solution: x = " << x1 << ", y = " << y1 << " and z = " << z1 << endl;
    cout << endl<< "Total steps needed to converge: " << step - 1 << endl;
    cout << endl;
}

double Bisection_method(double (*f)(double), double a, double b, double tol, int maxIter) {
    if (f(a) * f(b) >= 0) {
        cout << "Bisection method fails." << endl;
        return -1;
    }

    double c = a;
    for (int i = 0; i < maxIter; i++) {
        c = (a + b) / 2;
        if (f(c) == 0 || (b - a) / 2 < tol)
            return c;

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}
double Newton_raphson_method(double (*f)(double), double (*df)(double), double x0, double tol, int maxIter) {
    double x = x0;
    for (int i = 0; i < maxIter; i++) {
        double dx = f(x) / df(x);
        x -= dx;
        if (abs(dx) < tol)
            return x;
    }
    return x;
}
double Secant_method(double (*f)(double), double x0, double x1, double tol, int maxIter) {
    double x2;
    for (int i = 0; i < maxIter; i++) {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        if (abs(x2 - x1) < tol)
            return x2;
        x0 = x1;
        x1 = x2;
    }
    return x2;
}
double Fixed_point_Iteration(double (*g)(double), double x0, double tol, int maxIter) {
    double x = x0;
    for (int i = 0; i < maxIter; i++) {
        double x_new = g(x);
        if (abs(x_new - x) < tol)
            return x_new;
        x = x_new;
    }
    return x;
}
double f(double x)
{
    return 3*x - cos(x) -1;
}
double df(double x)
{
    return 3+sin(x);
}
double g(double x)
{
    return (cos(x)+1)/3;
}

