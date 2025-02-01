#include <iostream>
#include <vector>
#include <array>
#include <string>

template<typename T1, typename T2>
bool hasMoreElements(T1 x, T2 y){
    size_t sx = x.size();
    size_t sy = y.size();
    if (sx > sy){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
	std::vector<int> a {10, 20, 30, 40, 50};
	std::string b = "Cat";
	std::string c = "Elephant";
	std::array<int, 3> d {10, 20, 30};
    
	std::cout << hasMoreElements(a, b) << std::endl;  // Должно напечатать 1
	std::cout << hasMoreElements(a, c) << std::endl;  // Должно напечатать 0
	std::cout << hasMoreElements(a, d) << std::endl;  // Должно напечатать 1
    
}