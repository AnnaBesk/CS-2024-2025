#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);

    int a[10000];
    for (int i = 0; i < n; ++i)
    {
        scanf("%i", &a[i]);
    }

    for (int j = 0; j < n; ++j)
    {
        int min_index = j;
        for (int i = j + 1; i < n; ++i)
        {
            int s_i = 0;
            int n_i = a[i];
            while (n_i > 0)
            {
                s_i += n_i % 10;
                n_i /= 10;
            }

            int s_min = 0;
            int n_min = a[min_index];
            while (n_min > 0)
            {
                s_min += n_min % 10;
                n_min /= 10;
            }

            if (s_i < s_min)
                min_index = i;
        }

        int temp = a[j];
        a[j] = a[min_index];
        a[min_index] = temp;
    }

    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
    printf("\n");
}