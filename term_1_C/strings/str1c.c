#include <stdio.h>
#include <ctype.h>

int main()
{
    char sym;
    scanf("%c", &sym);
    if (isalpha(sym) != 0)
    {
        printf("Letter\n");
    }
    else if (isdigit(sym) != 0)
    {
        printf("Digit\n");
    }
    else
    {
        printf("Other\n");
    }
}