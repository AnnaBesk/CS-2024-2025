#include <stdio.h>
#include <string.h>

void trim_after_first_space(char *input)
{
    int i = 0;
    int len = strlen(input);
    while (input[i] != ' ')
    {
        i += 1;
    }
    input[i] = '\0';
}

int main()
{
    char a[] = "Cats and Dogs";
    printf("%s \n", a);
    trim_after_first_space(a);
    printf("%s\n", a);
}