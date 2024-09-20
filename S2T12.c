#include <stdio.h>

int main()
{
    int a[1000];
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);

    int el, pos;
    scanf("%i", &el);
    scanf("%i", &pos);

    for (int i = n + 1; i > pos + 1; --i)
    {
        a[i] = a[i - 1];
    }
    a[pos + 1] = el;
    n += 1;

    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);

    printf("\n");
}