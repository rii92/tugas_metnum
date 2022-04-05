// bisection method for finding root of a function

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x * x - x - 1;
}

double f_prime(double x)
{
    return 3 * x * x - 1;
}

double bisection(double a, double b, double epsilon)
{
    double c, fc;
    int i = 0;
    do
    {
        c = (a + b) / 2;
        fc = f(c);
        if (f(a) * fc < 0)
            b = c;
        else
            a = c;
        i++;
    } while (fabs(fc) > epsilon);
    printf("%d\n", i);
    return c;
}

int main()
{
    double a, b, epsilon;
    printf("Input a: ");
    scanf("%lf", &a);
    printf("Input b: ");
    scanf("%lf", &b);
    printf("Input epsilon: ");
    scanf("%lf", &epsilon);
    printf("Root of f(x) = x^3 - x - 1 is %lf\n", bisection(a, b, epsilon));
    return 0;
}
