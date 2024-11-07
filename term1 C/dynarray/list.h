#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}

struct node 
{
    int value;
    struct node* next;
    struct node* prev;
};

typedef struct node Node;

struct list 
{
    Node* head;
    Node* tail;
    size_t size;
};
typedef struct list List;

List init(size_t n)
{
    List lt;
    if (n == 0){
        lt.head = NULL;
        lt.size = 0;
        lt.tail = NULL;
    }
    else{
        Node* node1 = (Node*)ecmalloc(sizeof(Node));
        lt.head = node1;
        lt.size = n;

        lt.head->value = 0;
        lt.head->prev = NULL;

        Node* prev = node1;
        Node* next;

        for (int i = 1; i < n; ++i){
            Node* nd = (Node*)ecmalloc(sizeof(Node));
            nd->value = 0; //задали текущее значение
            nd->prev = prev; //задали ссылку на предыдущую ячейку
            prev->next = nd; // предудущей задаем следующую 
            prev = nd;
        }

        prev->next = NULL;
        lt.tail = prev;
    }
    return lt;
}

void print(const List* pl){
    Node* cur_node = pl->head;
    for (int i = 0; i < pl->size; ++i){
        printf("%i ", cur_node->value);
        cur_node = cur_node->next;
    }
    printf("\n");
}

void push_back(List* pl, int value){
    pl->size += 1;
    Node* new_node = (Node*)ecmalloc(sizeof(Node));
    new_node->value = value;
    new_node->prev = pl->tail;
    new_node->next = NULL;

    if (pl->tail != NULL) { // Если список не пустой
        pl->tail->next = new_node;
    } else { // Если список пустой
        pl->head = new_node;
    }
    pl->tail = new_node;
}

int pop_back(List *pl){
     pl->size -= 1;
     int value = pl->tail->value;
     Node* new_last = pl->tail->prev;
     new_last->next = NULL;
     free(pl->tail);
     pl->tail = new_last;
     return value;
}

void push_front(List* pl, int value){
    pl->size += 1;
    Node* new_node = (Node*)ecmalloc(sizeof(Node));
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = pl->head;

    if (pl->head != NULL) { // Если список не пустой
        pl->head->prev = new_node;
    } else { // Если список пустой
        pl->tail = new_node;
    }

    pl->head = new_node;
}

int pop_front(List *pl){
     pl->size -= 1;
     int value = pl->head->value;
     Node* new_first = pl->head->next;
     new_first->prev = NULL;
     free(pl->head);
     pl->head = new_first;
     return value;
}

Node* erase(List* lt, Node* p) {
    if (p == NULL) {
        return NULL; // Если p - NULL, то ничего не удаляем.
    }

    if (lt->size == 0) {
        return NULL; // Если список пустой, то ничего не удаляем.
    }

    if (p == lt->head) { 
        lt->head = p->next;
        if (lt->head != NULL) { 
            lt->head->prev = NULL;
        } else {
            lt->tail = NULL; // Если это был единственный узел
        }
        lt->size -= 1;
        free(p);
        return lt->head;

    } else if (p == lt->tail) { // Удаление последнего узла
        lt->tail = p->prev;
        if (lt->tail != NULL) {
            lt->tail->next = NULL;
        } else {
            lt->head = NULL; // Если это был единственный узел
        }
        lt->size -= 1;
        free(p);
        return NULL; // Возвращаем NULL, так как удален последний узел

    } else { // Удаление узла в середине списка
        p->prev->next = p->next;
        p->next->prev = p->prev;
        lt->size -= 1;
        free(p);
        return p->next; // Возвращаем указатель на следующий узел
    }
}

void destroy(List* lt) 
{
    Node* current = lt->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    lt->head = NULL;
    lt->tail = NULL;
    lt->size = 0;
}

void splice(List* plist, Node* p, List* pother) {
    if (pother->size == 0) {
        return; // Если pother пустой, то ничего не делаем.
    }

    if (p == NULL) {
        p = plist->head; // Если p равен NULL, вставляем перед началом списка
    }

    if (pother->head == pother->tail) { // Если в pother только один элемент
        pother->tail->next = p;
        pother->tail->prev = p->prev;

        if (p->prev != NULL) {
            p->prev->next = pother->tail;
        } else {
            plist->head = pother->tail;
        }

        p->prev = pother->tail;
        plist->size += pother->size;
    } else { // В pother несколько элементов
        pother->tail->next = p;
        pother->head->prev = p->prev;

        if (p->prev != NULL) {
            p->prev->next = pother->head;
        } else {
            plist->head = pother->head;
        }

        p->prev = pother->tail;
        plist->size += pother->size;

    }

    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void advance(Node** pp, size_t n){
    if (*pp == NULL) {
        return; 
    }

    Node* p = *pp; // Создаем локальную копию указателя

    while (n > 0 && p != NULL) {
        p = p->next;
        n -= 1;
    }

    *pp = p; // Обновляем указатель, на который ссылается pp
}