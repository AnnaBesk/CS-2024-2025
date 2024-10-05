#include <stdio.h>
#include <string.h>

int exchange(int *pa, int b)
{
    int temp = *pa;
    *pa = b;
    return temp;
}

int main()
{
    int a = 10;
    printf("%i \n", exchange(&a, 20));
    printf("%i \n", a);
}