#include <stdio.h>

int cube(int a)
{
    a = a * a * a;
    return a;
}

int main()
{
    printf("%i\n", cube(5));
}