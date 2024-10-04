#include <stdio.h>
#include <string.h>

void encrypt(char *str, int k)
{
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
        if (65 <= str[i] && str[i] <= 90)
        {
            if (str[i] + k <= 90)
            {
                str[i] = str[i] + k;
            }
            else
            {
                str[i] = str[i] + k - 26;
            }
        }
        if (97 <= str[i] && str[i] <= 122)
        {
            if (str[i] + k <= 122)
            {
                str[i] = str[i] + k;
            }
            else
            {
                str[i] = str[i] + k - 26;
            }
        }
    }
}

int main()
{
    int s;
    scanf("%i", &s);
    char str[50];
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = '\0';
    encrypt(str, s);
    printf("%s \n", str);
}