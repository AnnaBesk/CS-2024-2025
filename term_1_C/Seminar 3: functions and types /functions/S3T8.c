#include <stdio.h>

void reverse(int a[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = a[i];
        a[i] = a[size - i - 1];
        a[size - i - 1] = temp;
    }
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

    reverse(arr, n);

    for (int i = 0; i < n; ++i)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}