#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int len = strtol(argv[1], NULL, 10);
    for (int i = 0; i < len; i++)
    {
        printf("%s ", argv[2]);
    }
    printf("\n");
}