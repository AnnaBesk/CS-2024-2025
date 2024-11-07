#include "dynarray.h"

int main() 
{
    Dynarray a;
    init(&a, 0);
    for (size_t i = 0; i < 100; ++i)
    {
        push_back(&a, i);
    }
    /*printf("%i \n", pop_back(&a));
    print(&a);  // тестируем pop_back */
    
    /*resize(&a, 10); // тестим resize()
    print(&a);  
    printf("size: %zu, capacity:  %zu \n", a.size, a.capacity);*/
    
    /*
    printf("size: %zu, capacity:  %zu \n", a.size, a.capacity);
    shrink_to_fit(&a); //тестим shrink_to_fit
    printf("size: %zu, capacity:  %zu \n", a.size, a.capacity);     */

    /* 
    Dynarray r = shallow_copy(&a);
    print(&r);
    set(&a, 5, 898); //тестим, что массив изменяется, если меняем а
    print(&r);
    */

    /*
    Dynarray t = deep_copy(&a);
    print(&t);
    set(&a, 5, 898); //тестим, что массив НЕ изменяется, если меняем а
    print(&t);
    */

    print(&a);
    destroy(&a);
}