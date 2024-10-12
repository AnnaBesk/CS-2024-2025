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


struct library 
{
    Book* books;
    int number_of_books;
};

typedef struct library Library;

void library_create(Library* lib, int number){
    (*lib).books = (Book*)malloc(sizeof(Book) * number);
    lib->number_of_books = number;
}

void library_set(Library lib, int i, char* title, int pages, float price){
    (lib.books[i]).title = (char*)malloc(sizeof(char)*100);
    strcpy(lib.books[i].title, title);
    (lib.books[i]).pages = pages;
    (lib.books[i]).price = price;
}

Book* library_get(Library lib, int i){
    return &lib.books[i];
}

void print_book(struct book* b) 
{
    printf("Book info:\n");
    printf("Title: %s\nPages: %d\nPrice: %g\n\n", b->title, b->pages, b->price);
}

void library_print(Library lib){
    for (int j = 0; j < lib.number_of_books; ++j){
        print_book(&lib.books[j]); // Передаём адрес элемента массива
    }
}

void library_destroy(Library* lib){
    for (int j = 0; j < lib->number_of_books; ++j){
        free(lib->books[j].title);
    }
    free(lib->books);
}

int main()
{
    Library a;
    library_create(&a, 3);

    library_set(a, 0, "Don Quixote", 1000, 750.0);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);

    library_print(a);
    
    print_book(library_get(a, 1));

    library_destroy(&a);
}
