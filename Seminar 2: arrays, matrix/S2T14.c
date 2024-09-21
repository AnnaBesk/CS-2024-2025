#include <stdio.h>

int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    int l, r;
    scanf("%i", &l);
    scanf("%i", &r);

    int delta = r - l;

    for (int i = l; i < n - delta; i++)
        a[i] = a[i + delta];
    for (int i = n - delta; i < n; i++)
        a[i] = 0;

    n -= delta;
    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);

    printf("\n");
}