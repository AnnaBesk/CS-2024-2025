#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int count = argc - 1;
    for (int i = 2; i < count + 1; ++i)
    {
        for (int j = 1; j < count + 1 - i; ++j)
        {
            if (strcmp(argv[j], argv[j + 1]) > 0)
                printf("fff \n");
            {
                char *temp = argv[j];
                strcpy(temp, argv[j]);
                strcpy(argv[j], argv[j + 1]);
                strcpy(argv[j + 1], temp);
            }
        }
    }

    for (int i = 1; i < count + 1; ++i)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
}