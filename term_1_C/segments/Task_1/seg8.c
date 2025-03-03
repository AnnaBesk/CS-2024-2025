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
    Book* p = (Book*)malloc(sizeof(Book*));
    p->title = (char*)malloc(sizeof(char)*100);
    strcpy(p->title, "Don Quixote");
    p->pages = 1000;
    p->price = 750;

    print_book(*p);

    free(p->title);
    free(p);
}