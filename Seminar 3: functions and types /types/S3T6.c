#include <stdio.h>
#include <math.h>

size_t fact(int n)
{

    size_t result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

double fun(int t, int x)
{
    return pow(t, x - 1) * exp(-t);
}

double gamma(double x)
{
    const double step = 1e-2;
    const double eps = 1e-10;

    if (floor(x) == x)
    {
        return fact((int)x - 1);
    }
    else
    {
        printf("here\n");
        double gm = 0;
        double t = 0;
        while (fabs(fun(t, x) - 0) > eps)
        {
            gm += (fun(t, x) + fun(t + step, x)) * 0.5;
            printf("%lf \n", fun(t, x) + fun(t + step, x));
            t += step;
        }
        return gm;
    }
}

int main()
{
    double x;
    scanf("%lf", &x);
    printf("%lf \n", gamma(x));
}