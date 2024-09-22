#include <stdio.h>

void bob(int n);

void alice(int n)
{
    n = n * 3 + 1;
    printf("Alice: %i \n", n);
    bob(n);
}

void bob(int n)
{
    while (n % 2 != 1)
    {
        n = n / 2;
        printf("Bob %i \n", n);
    }

    if (n != 1)
    {
        alice(n);
    }
}

int main()
{
    alice(13);
}