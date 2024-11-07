#include <stdio.h>

int sum_of_digits(int n)
{
    int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%i \n", sum_of_digits(n));
}