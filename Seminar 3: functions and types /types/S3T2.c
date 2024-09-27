#include <stdio.h>
typedef unsigned long long ull;

ull raz(int n, int k)
{
    ull result = 1;
    for (int i = n - k + 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}
int main()
{
    int n, k;
    scanf("%i %i", &n, &k);
    printf("%llu \n", raz(n, k));
}