#include <stdio.h>

int main()
{
    int a[1000];

    int odd[1000];
    int even[1000];

    int odd_c = 0;
    int even_c = 0;

    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            even[even_c] = a[i];
            even_c += 1;
        }
        else
        {
            odd[odd_c] = a[i];
            odd_c += 1;
        }
    }

    for (int i = 0; i < odd_c; ++i)
    {
        a[i] = odd[i];
    }

    for (int i = odd_c; i < n; ++i)
    {
        a[i] = even[i - odd_c];
    }

    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);

    printf("\n");
}