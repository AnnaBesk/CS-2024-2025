#include <stdio.h>

#define MAX 10

void transpose(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; j++)
        {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

void print(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%i ", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int n;
    scanf("%i", &n);
    int a[n][n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%i", &a[i][j]);
        }
    }
    transpose(a, n);
    print(a, n);
}