#include <stdio.h>

int main()
{

    int n, m;
    scanf("%i %i", &n, &m);
    int a[n][m];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%i", &a[i][j]);
        }
    }

    for (int j = 0; j < m; ++j)
    {
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n - 1 - k; ++l)
            {
                if (a[l][j] > a[l + 1][j])
                {
                    int temp = a[l][j];
                    a[l][j] = a[l + 1][j];
                    a[l + 1][j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
}