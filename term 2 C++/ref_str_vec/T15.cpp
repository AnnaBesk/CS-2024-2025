#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void print(const int* a, std::size_t n)
{
    for (std::size_t i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}
// Тут нужно написать перегрузки функции get
int& get(std::vector<int>& x, int ind){
    if (ind >= x.size()){
        std::cout << "error" << std::endl;
        std::exit(0);
    }
    return x[ind];
}

char& get(std::string& x, int ind){
    if (ind >= x.length()){
        std::cout << "error" << std::endl;
        std::exit(0);
    }
    return x[ind];
}

int& get(int x[], int size, int ind){
    if (ind >= size){
        std::cout << "error" << std::endl;
        std::exit(0);
    }
    return x[ind];
}


int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};
    get(v, 2) += 1;
    print(v);                     // Напечатает 10 20 31 40 50
    
    std::string s = "Cat";
    get(s, 0) = 'B';
    std::cout << s << std::endl;  // Напечатает Bat
    
    int a[5] = {10, 20, 30, 40, 50};
    get(a, 5, 2) += 1;
    print(a, 5);                  // Напечатает 10 20 31 40 50
    
    get(v, 10) = 0;               // Должен напечатать сообщение об ошибке и выйти из программы
}