#include <iostream>
#include <string>

using namespace std::string_literals;

std::string& operator+(const int& n, std::string& b) 
{
    std::string result = ""s;
	for (int i = 0; i < n; i ++){
		result += result;
	}
    return result;
}

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