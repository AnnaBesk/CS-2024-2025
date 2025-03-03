#include <stdio.h>

int c_even(int a[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 == 0)
            count += 1;
    }
    return count;
}

int main()
{
    int n;
    scanf("%i", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%i", &arr[i]);
    }

    printf("%i \n", c_even(arr, n));
}