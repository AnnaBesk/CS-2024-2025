#include <stdio.h>

void mult2(int *p, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] *= 2;
    }
}

int main()
{
    int a[] = {2, 3, 4, 5};

    mult2(&a[0], 4);
    for (int i = 0; i < 4; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
}