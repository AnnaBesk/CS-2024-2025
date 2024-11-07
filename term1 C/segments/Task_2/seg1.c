#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings(){
    char** p = (char**)malloc(sizeof(char*) * 4);

    p[0] = (char*)malloc(sizeof(char) * 4);
    strcpy(p[0], "Cat");

    p[1] = (char*)malloc(sizeof(char) * 6);
    strcpy(p[1], "Mouse");

    p[2] = (char*)malloc(sizeof(char) * 9);
    strcpy(p[2], "Elephant");

    p[3] = NULL;

    return p;
}

void print_strings(FILE* stream, char** string_array){
    int i = 0;
    while (string_array[i] != NULL){
        printf("%s \n", string_array[i]);
        i += 1;
    }
}

int main()
{
    char** p = get_test_strings();
    print_strings(stdout, p);

    for (int i = 0; i < 4; ++i){
        free(p[i]);
        p[i] = NULL;
    }
    free(p);
    p = NULL;   
}