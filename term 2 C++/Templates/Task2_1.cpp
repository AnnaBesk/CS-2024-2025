#include <iostream>

template<typename T>
T triple(const T& x)
{
	return x + x + x;
}

int main()
{
	int a = 10;
	std::cout << triple(a) << std::endl;  // Сработает, напечатает 30
	
	std::string b = "Cat";
	std::cout << triple(b) << std::endl;  // Нужно чтобы напечаталось CatCatCat
}