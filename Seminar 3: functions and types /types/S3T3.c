#include <stdio.h>
typedef unsigned long long ull;

float yearfrac(int year, int day)
{
    if (year % 4 == 0)
        return day / 366.0;
    else
        return day / 365.0;
}
int main()
{
    int y, d;
    scanf("%i %i", &y, &d);
    printf("%.5f \n", yearfrac(y, d));
}