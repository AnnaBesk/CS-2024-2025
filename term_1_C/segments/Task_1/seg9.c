#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book 
{
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

void print_book(struct book b) 
{
    printf("Book info:\n");
    printf("Title: %s\nPages: %d\nPrice: %g\n\n", b.title, b.pages, b.price);
}

int main()
{
    Book* p = (Book*)malloc(sizeof(Book)*3);
    
    p[0].title = (char*)malloc(sizeof(char)*100);
    strcpy(p[0].title, "Don Quixote");
    p[0].pages =  1000;
    p[0].price = 750.0;
    print_book(p[0]);

    p[1].title = (char*)malloc(sizeof(char)*100);
    strcpy((p[1]).title, "Oblomov");
    p[1].pages =  400;
    p[1].price = 250.0;
    print_book(p[1]);

    p[2].title = (char*)malloc(sizeof(char)*100);
    strcpy((p[2]).title, "The Odyssey");
    p[2].pages =  500;
    p[2].price = 500.0;
    print_book(p[2]);

    for (int i = 0; i < 3; ++i){
        free(p[i].title);
    }
    free(p);
}