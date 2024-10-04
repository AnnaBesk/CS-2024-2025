#include <stdio.h>

int main()
{
    char sym;
    scanf("%c", &sym);
    if ((65 <= sym && sym <= 90) || (97 <= sym && sym <= 122))
    {
        printf("Letter\n");
    }
    else if (48 <= sym && sym <= 57)
    {
        printf("Digit\n");
    }
    else
    {
        printf("Other\n");
    }
}