#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    char word1[50], word2[50];
    int i, j = 0;

    fgets(input, 100, stdin);
    for (i = 0; input[i] != ' ' && input[i] != '\0'; i++)
    {
        word1[i] = input[i];
    }
    word1[i] = '\0';

    i++;

    for (j = 0; input[i] != '\0'; i++, j++)
    {
        word2[j] = input[i];
    }
    word2[j] = '\0';

    i = 0;
    j = 0;

    while (word1[i] != '\0' && word1[i] != '\n' && word2[j] != '\0' && word2[j] != '\n')
    {
        printf("%c", word1[i]);
        printf("%c", word2[j]);
        i += 1;
        j += 1;
    }

    if (word1[i] == '\0')
    {
        while (word2[j] != '\0')
        {
            printf("%c", word2[j]);
            j += 1;
        }
    }

    else
    {
        printf("%c", word1[i]);
        while (word1[i] != '\0')
        {
            printf("%c", word1[i]);
            i += 1;
        }
    }
    printf("\n");
}