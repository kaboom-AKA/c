#include <stdio.h>
#include <stdbool.h> 
#include <math.h>

// Global variables
bool start_stop = true;

// Function declarations
void simple_trigo_and_log(void);
void Normal_calculation(void);
void Area_Under_a_Curve(void);
void Algebra(void);
void ExitProgram(void);
void simple_trigo(void);
void simple_log_and_expo(void);

int main() {
    while (start_stop) 
    {
        int user_choice;
        printf("\n1. Simple trigonometry\n2. Logarithms and Exponents\n3. Normal calculation\n4. Area Under a Curve\n5. Up to 3 Algebraic expressions\n6. Exit\nEnter your option: ");
        scanf("%d", &user_choice); 
        switch(user_choice) {
            case 1:
                simple_trigo();
                break;
            case 2:
                simple_log_and_expo();
                break;
            case 3:
                Normal_calculation();
                break;
            case 4:
                Area_Under_a_Curve();
                break;
            case 5:
                Algebra();
                break;
            case 6:
                ExitProgram();
                break;
            default:
                printf("\n\nInvalid Input! Please Enter Again\n");
        }
    }
    return 0;
}

void ExitProgram()
{
    char yes_no;
    printf("\n\nAre you sure you want to end the program?\n[type 'Y' to confirm]: ");
    scanf(" %c", &yes_no);  // The space before %c ensures it skips any whitespace
    
    if (yes_no == 'Y' || yes_no == 'y') {  
        printf("\nThis is the end of the program.\n");
        start_stop = false;
    }
}

void simple_trigo()
{
    bool Start_Stop2 = true;
    int Trigo;
    double answer;

    // Find out the coefficient of the Trigonometric function
    double coefficient;
    printf("Enter your coefficient: ");
    scanf("%lf", &coefficient);

    // Find out the angle
    double angle;
    printf("Enter your angle (in degrees): ");
    scanf("%lf", &angle);
    double radians = angle * (M_PI / 180.0);  // Convert degrees to radians

    // Get user choice for trigonometric function
    printf("1. Sin \n2. Cos \n3. Tan \n4. Csc \n5. Sec \n6. Cot \nChoose your option: ");
    scanf("%d", &Trigo); 

    // Perform the chosen calculation
    while (Start_Stop2)
    {
        switch (Trigo)
        {
            case 1 : 
                answer = coefficient * sin(radians);
                printf("\n%.2f * sin(%.2f) = %.2f\n", coefficient, angle, answer);
                Start_Stop2 = false;
                break;
            case 2 : 
                answer = coefficient * cos(radians);
                printf("\n%.2f * cos(%.2f) = %.2f\n", coefficient, angle, answer);
                Start_Stop2 = false;
                break;
            case 3 : 
                answer = coefficient * tan(radians);
                printf("\n%.2f * tan(%.2f) = %.2f\n", coefficient, angle, answer);                            
                Start_Stop2 = false;
                break;                        
            case 4 : 
                answer = coefficient / sin(radians);
                printf("\n%.2f * csc(%.2f) = %.2f\n", coefficient, angle, answer);                           
                Start_Stop2 = false;
                break; 
            case 5 : 
                answer = coefficient / cos(radians);
                printf("\n%.2f * sec(%.2f) = %.2f\n", coefficient, angle, answer);                           
                Start_Stop2 = false;
                break;
            case 6 :
                answer = coefficient / tan(radians);
                printf("\n%.2f * cot(%.2f) = %.2f\n", coefficient, angle, answer);                           
                Start_Stop2 = false;
                break;                                  
            default:
                printf("\nInvalid Input! Please Enter Again\n");
                scanf("%d", &Trigo);
        }
    }
}

void simple_log_and_expo()
{
    double answer;
    bool Start_Stop2 = true;
    double coefficient;
    double base;

    // Find out if user wants to calculate log or exponent
    int log_and_expo;
    printf("\n\n1. Logarithm\n2. Exponent\nChoose your option: ");
    scanf("%d", &log_and_expo); 

    while (Start_Stop2)
    {
        switch (log_and_expo)
        {
            case 1:
                // Get the coefficient          
                printf("Enter your coefficient: ");
                scanf("%lf", &coefficient);
                
                // Get the base 
                printf("Enter your base: ");
                scanf("%lf", &base);

                // Get the argument for the logarithm
                double argument;
                printf("Enter your argument: ");
                scanf("%lf", &argument);

                // Calculate the answer and print it
                answer = coefficient * log(argument) / log(base);
                printf("\n%.1f * log%.1f(%.1f) = %.5f\n", coefficient, base, argument, answer);

                Start_Stop2 = false;
                break;

            case 2:
                // Get the coefficient          
                printf("Enter your coefficient: ");
                scanf("%lf", &coefficient);
                
                // Get the base 
                printf("Enter your base: ");
                scanf("%lf", &base);

                // Get the exponent
                double exponent;
                printf("Enter your exponent: ");
                scanf("%lf", &exponent);

                // Calculate the answer and print it
                answer = coefficient * pow(base, exponent);
                printf("\n%.1f * (%.1f^%.1f) = %.5f\n", coefficient, base, exponent, answer);

                Start_Stop2 = false;
                break;

            default:
                printf("\nInvalid Input! Please Enter Again\n");
                scanf("%d", &log_and_expo);
        } 
    }
}

void Normal_calculation()
{
    double num1, num2, result;
    char operator;
    char continue_choice;
    bool start_stop2 = true;

    while (start_stop2) 
    {
        printf("\nEnter the first number: ");
        scanf("%lf", &num1);
        
        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &operator);  // The space before %c is important to consume any newline character
        
        printf("Enter the second number: ");
        scanf("%lf", &num2);

        // Perform the arithmetic operation
        switch (operator)
        {
            case '+':
                result = num1 + num2;
                printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case '/':
                if (num2 != 0) 
                {
                    result = num1 / num2;
                    printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
                } 
                else 
                {
                    printf("\nError! Division by zero.\n");
                }
                break;
            default:
                printf("\nInvalid operator!\n");
        }

        // Ask the user if they want to continue or exit
        printf("\nWould you like to perform another calculation? (Y/N): ");
        scanf(" %c", &continue_choice);

        if (continue_choice == 'N' || continue_choice == 'n') {
            start_stop2 = false;
        }
    }
}

void Area_Under_a_Curve()
{
    double a, b;
    int n;
    double area = 0.0, h, x;

    // Input values for range and number of intervals
    printf("\nEnter the lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);

    // Trapezoidal rule to calculate area under curve f(x) = x^2
    h = (b - a) / n;  // Step size
    for (int i = 0; i <= n; i++)
    {
        x = a + i * h;
        if (i == 0 || i == n) {
            area += x * x;  // Endpoints
        } else {
            area += 2 * (x * x);  // Midpoints
        }
    }
    area = (h / 2) * area;

    printf("\nThe approximate area under the curve y = x^2 between %.2f and %.2f is %.4f\n", a, b, area);
}

void Algebra()
{
    double a1, b1, c1, d1;
    double a2, b2, c2, d2;
    double a3, b3, c3, d3;
    double x, y, z, det;

    printf("\nSolve for 3 variables (x, y, z) from 3 equations\n");
    
    // Input coefficients for the three equations
    printf("Enter coefficients for equation 1 (a1*x + b1*y + c1*z = d1): ");
    scanf("%lf %lf %lf %lf", &a1, &b1, &c1, &d1);
    printf("Enter coefficients for equation 2 (a2*x + b2*y + c2*z = d2): ");
    scanf("%lf %lf %lf %lf", &a2, &b2, &c2, &d2);
    printf("Enter coefficients for equation 3 (a3*x + b3*y + c3*z = d3): ");
    scanf("%lf %lf %lf %lf", &a3, &b3, &c3, &d3);

    // Calculate determinant of the coefficient matrix
    det = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
    if (det == 0) {
        printf("\nThe system of equations has no unique solution (det = 0).\n");
    } else {
        // Using Cramer's rule to solve for x, y, z
        x = (d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2)) / det;
        y = (a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2)) / det;
        z = (a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2)) / det;

        printf("\nThe solution is:\n x = %.4f\n y = %.4f\n z = %.4f\n", x, y, z);
    }
}
