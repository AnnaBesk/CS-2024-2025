#include <stdio.h>

int main()
{
    int n;
    int i;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("%3d -> %3d -> %3d \n", i, i * i, i * i * i);
    }

    printf("\n");
}