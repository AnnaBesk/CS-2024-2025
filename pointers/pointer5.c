#include <stdio.h>
#include <math.h>

float eps = 1e-10;

void solve_quadratic(double a, double b, double c, double *px1, double *px2)
{
    double D = b * b - 4 * a * c;
    if (D > 0)
    {
        *px1 = (-b + pow(D, 0.5)) / 2 * a;
        *px2 = (-b - pow(D, 0.5)) / 2 * a;
    }
    else if (fabs(D - 0) < eps)
    {
        *px1 = (-b) / 2 * a;
    }
}

int main()
{
    double a = 1.0, b = -2.0, c = 1.0;
    double x1, x2;
    double *sx1 = &x1;
    double *sx2 = &x2;

    solve_quadratic(a, b, c, sx1, sx2);
    printf("%lf %lf \n", *sx1, *sx2);
}