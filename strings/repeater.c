#include <stdio.h>

int main(int argc, char **argv)
{
    char a = argv;
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", a);
    }
}