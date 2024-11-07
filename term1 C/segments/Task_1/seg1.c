#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t* p = (size_t*)malloc(sizeof(size_t));
    scanf("%zu", &*p);
    printf("%zu \n", *p);
    free(p);
}