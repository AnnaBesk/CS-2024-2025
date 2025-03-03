#include <iostream>
#include <string>

void addBrackets(std::string& x){
    x.push_back(']');
    x.push_back(']');
    int len = x.length();

    for (int i = len - 2; i > 0; i--){
        x[i] = x[i - 1];
    }
    x[0] = '[';
}

int main()
{
	std::string a = "Cat";
	addBrackets(a);
	std::cout << a << std::endl;  // Должно напечатать [Cat]
	
	addBrackets(a);
	std::cout << a << std::endl;  // Должно напечатать [[Cat]]
}