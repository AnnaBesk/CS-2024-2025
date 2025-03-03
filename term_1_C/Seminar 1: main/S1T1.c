#include <stdio.h>

int main()
{
    int number;
    scanf("%d", &number);
    if (number % 2 == 0)
    {
        if ((number >= 0 && number <= 20) || (number > 100 && number < 200))
        {
            printf("Yes \n");
        }
        else
        {
            printf("No \n");
        }
    }
    else
    {
        printf("No \n");
    }
}