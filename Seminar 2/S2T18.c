#include <stdio.h>

int main()
{
    int a[1000];
    int b[1000];
    int n;
    scanf("%i", &n);

    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);
    int k;
    scanf("%i", &k);

    for (int i = 0; i < n; ++i)
        b[(i + k) % n] = a[i];
    for (int i = 0; i < n; ++i)
        a[i] = b[i];
    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);

    printf("\n");
}