#include <iostream>
#include "number.hpp"


int main() 
{
    Number x = "12345678"s;
    Number y = "1234567899"s;
    std::cout << x << std::endl;
    //std::cout << y << std::endl;
    //std::cout << x + y << " x + y" << std::endl;
    //x += y;
    //std::cout << x << " x += y" << std::endl;
    //std::cout << fib(100) << std::endl; //совпадает с нужным значением по таблицам
    std::cout << isEven(x) << std::endl;
    std::cout << isEven(y) << std::endl;

}