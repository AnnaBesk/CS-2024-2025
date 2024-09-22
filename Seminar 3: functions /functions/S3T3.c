#include <stdio.h>

void print_even(int l, int r)
{
    for (int i = l; i <= r; ++i)
    {
        if (i % 2 == 0)
        {
            printf("%i ", i);
        }
    }
    printf("\n");
}

int main()
{
    int a, b;
    scanf("%i %i", &a, &b);
    print_even(a, b);
}