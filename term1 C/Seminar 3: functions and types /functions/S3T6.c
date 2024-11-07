#include <stdio.h>

int base[1000];
int trib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        if (base[n] == 0)
        {
            base[n] = trib(n - 3) + trib(n - 2) + trib(n - 1);
        }
        return base[n];
    }
}

int main()
{
    int a;
    scanf("%i", &a);
    printf("%i \n", trib(a));
}