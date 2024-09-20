#include <stdio.h>

int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    int pos;
    scanf("%i", &pos);

    for (int i = pos; i < n; ++i)
        a[i] = a[i + 1];

    n -= 1;
    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);

    printf("\n");
}