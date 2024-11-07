#include <stdio.h>

float pi(int n)
{
    float pi4 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 == 0)
        {
            pi4 += -1.0 / (2 * i - 1);
        }
        else
        {
            pi4 += 1.0 / (2 * i - 1);
        }
    }
    return 4 * pi4;
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%.5f \n", pi(n));
}