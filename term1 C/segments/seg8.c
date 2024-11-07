#include <stdio.h>
// Тут нужно написать функцию adder

int count = 0;

int adder(int a){
    count += a;
    return count;
}

int main()
{
    printf("%i\n", adder(10));  // Должен напечатать 10
    printf("%i\n", adder(15));  // Должен напечатать 25
    printf("%i\n", adder(70));  // Должен напечатать 95
}