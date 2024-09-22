#include <stdio.h>

int sum_of_digits_rec(int n, int s)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        s = sum_of_digits_rec(n / 10, s);
        s += n % 10;
    }
    return s;
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%i \n", sum_of_digits_rec(n, 0));
}