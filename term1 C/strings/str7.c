#include <stdio.h>
#include <string.h>

void safe_strcpy(char *new, size_t len, const char *old)
{
    int i = 0;
    while (i < len - 1 && old[i] != '\0')
    {
        new[i] = old[i];
        i++;
    }
    new[i] = '\0';
}

int main()
{
    char a[10] = "Mouse";
    char b[50] = "LargeElephant";
    safe_strcpy(a, 10, b);
    printf("lala \n");
    printf("%s", a);
    return 0;
}