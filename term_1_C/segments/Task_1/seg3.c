#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char** p = (char**)malloc(sizeof(char*));
    *p = (char*)malloc(sizeof(char) * 14);
    strcpy(*p, "hello");

    printf("%s\n", *p);
    free(*p);
    free(p);
}