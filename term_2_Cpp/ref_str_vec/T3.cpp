#include <iostream>


// Тут нужно написать функцию swap
void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	std::cout << a << " " << b << std::endl;  // Должно напечатать 10 20
	
	swap(a, b);
	std::cout << a << " " << b << std::endl;  // Должно напечатать 20 10
}