#include <stdio.h>

int main()
{
    char sym;
    scanf("%c", &sym);
    if (('A' <= sym && sym <= 'Z') || (97 <= sym && sym <= 122))
    {
        printf("Letter\n");
    }
    else if ('0' <= sym && sym <= '9')
    {
        printf("Digit\n");
    }
    else
    {
        printf("Other\n");
    }
}