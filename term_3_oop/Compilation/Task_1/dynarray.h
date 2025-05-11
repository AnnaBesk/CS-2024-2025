#pragma once

void* ecmalloc(size_t);

struct dynarray 
{
    int* data;
    size_t size;
    size_t capacity;
};
typedef struct dynarray Dynarray;

void clear(Dynarray*);
void init(Dynarray*, size_t);
void reserve(Dynarray*, size_t);
void push_back(Dynarray*, int); 
int get(const Dynarray*, size_t);
void set(Dynarray*, size_t, int);
void print(const Dynarray*);
void destroy(Dynarray*);





