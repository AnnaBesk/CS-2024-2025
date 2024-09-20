#include <stdio.h>

int main()
{
    int a[1000];
    a[0] = 0;

    int n, m;
    scanf("%i %i", &n, &m);

    int cur;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%i", &cur);
            a[j] += cur;
        }
    }

    for (int i = 0; i < m; ++i)
        printf("%i ", a[i]);

    printf("\n");
}