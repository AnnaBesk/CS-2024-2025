#include <stdio.h>

int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    int shift = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0)
            shift += 1;
        else
            a[i - shift] = a[i];
    }
    for (int i = n - shift; i < n; ++i)
        a[i] = 0;

    n -= shift;

    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);

    printf("\n");
}