#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    int len;
    scanf("%99s", word);
    len = strlen(word);
    int ch = len / 2;
    int state = 0;

    for (int i = 0; i < ch; ++i)
    {
        if (word[len - 1 - i] != word[i])
        {
            state += 1;
        }
    }
    if (state == 0)
    {
        printf("Yes \n");
    }
    else
    {
        printf("No \n");
    }
}