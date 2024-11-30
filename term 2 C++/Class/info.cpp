#include <cstdio> //библитоека ввода-вывода - printf, fgets etc
#include <iostream> // cin, cout etc
#include <string> //std::string
#include <cctype> // для работы с симсволами char
// using namespace std::string_literals; - чтобы вставлять литералы stringa как "Cat"s
#include <vector> // для работы с массивами

int main(){
    std::string str = "12345678";
    int dl = str.size();
    for(int i = 0; i < dl; i += 2) 
        {
            std::string sa = str.substr(i, 2);
            int a = std::stoi(sa);
            std::cout << a << std::endl;
    }
}

