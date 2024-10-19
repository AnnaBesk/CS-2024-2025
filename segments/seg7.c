#include <stdio.h>
#include <math.h>

// Тут нужно написать функцию count_if и функции - предикаты:
//     is_negative  - проверяет, является ли число отрицательным
//     is_even      - проверяет, является ли число чётным

int is_negative(int a)
{
    if (a < 0)
        return 1;
    else
        return 0;
}

int is_even(int a)
{
    if (a % 2 == 0)
        return 1;
    else
        return 0;
}

int is_square(int a)
{
    double sqr = pow((double)a, 0.5) + 1;
    for (int i = 0; i <= sqr; ++i){
        if (i * i == a){
            return 1;
        }
    }
    return 0;
}

size_t count_if(int* a, size_t n, int (*pred)(int))
{
    int count = 0;
    for (size_t i = 0; i < n; ++i){
        if (pred(a[i])){
            count += 1;
        }
    }
    return count;
}

int main()
{
    int a[] = {89, 81, 28, 52, 44, 16, -64, 49, 52, -79};
    
    printf("%zu\n", count_if(a, 10, is_negative));  // Должен напечатать 2
    printf("%zu\n", count_if(a, 10, is_even));      // Должен напечатать 6
    printf("%zu\n", count_if(a, 10, is_square));    // Должен напечатать 3
}