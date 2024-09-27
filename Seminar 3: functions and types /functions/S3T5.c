#include <stdio.h>

void bin(int n)
{
    if (n == 1)
    {
        printf("%i", 1);
    }
    else
    {
        bin(n / 2);
        printf("%i", n % 2);
    }
}

int main()
{
    int a;
    scanf("%i", &a);
    bin(a);
    printf("\n");
}