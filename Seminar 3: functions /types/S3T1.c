#include <stdio.h>

size_t fact(int n)
{
    size_t result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}
int main()
{
    int k;
    scanf("%i", &k);
    printf("%zu\n", fact(k));
}