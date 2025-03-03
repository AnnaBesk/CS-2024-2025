#include <stdio.h>
struct cat
{
    char x;
    size_t y;
};

struct dog
{
    size_t y;
    char x;
};

struct mouse
{
    char x;
    char y;
    size_t z;
};

struct rat
{
    char x;
    size_t z;
    char y;
};

struct fox
{
    char x;
    struct mouse y;
};
int main()
{
    printf("Size of char   = %zu\n", sizeof(char));
    printf("Size of int    = %zu\n", sizeof(int));
    printf("Size of size_t = %zu\n", sizeof(size_t));
    printf("Size of cat    = %zu\n", sizeof(struct cat));
    printf("Size of dog    = %zu\n", sizeof(struct cat));
    printf("Size of mouse  = %zu\n", sizeof(struct mouse));
    printf("Size of rat    = %zu\n", sizeof(struct rat));
    printf("Size of fox    = %zu\n", sizeof(struct fox));
}