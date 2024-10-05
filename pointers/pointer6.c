#include <stdio.h>
#include <string.h>

void set_characters(char *begin, const char *end, char c)
{
    while (begin < end)
    {
        *begin = c;
        begin++;
    }
}

int main()
{
    char s[] = "Sapere Aude";
    set_characters(&s[2], &s[8], 'b');
    printf("%s\n", s); // Напечатает Sabbbbbbude
    set_characters(s, &s[4], 'a');
    printf("%s\n", s); // Напечатает aaaabbbbude
}