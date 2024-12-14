#include <cstdio> //библитоека ввода-вывода - printf, fgets etc
#include <iostream> // cin, cout etc
#include <string> //std::string
#include <cctype> // для работы с симсволами char
// using namespace std::string_literals; - чтобы вставлять литералы stringa как "Cat"s
#include <vector> // для работы с массивами

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>

template <typename T>
std::vector<std::pair<typename T::value_type, typename T::value_type>> pairing(const T& data){
    std::vector<std::pair<typename T::value_type, typename T::value_type>> answer;
    size_t len = std::size(data);
    if(len % 2 == 0){
        for (int i = 0; i < len / 2; i++){
            std::pair<typename T::value_type, typename T::value_type> p = std::make_pair(data[2 * i], data[2 * i + 1]);
            answer.push_back(p);
        }
    }
    else{
        for (int i = 0; i <  len / 2; i++){
            std::pair<typename T::value_type, typename T::value_type> p = std::make_pair(data[2 * i], data[2 * i + 1]);
            answer.push_back(p);
        }

        typename T::value_type x{};
        std::pair<typename T::value_type, typename T::value_type> p = std::make_pair(data.back(), x);
        answer.push_back(p);
    }

    return answer;
}


int main() {
    std::vector<int> a = {10, 20, 30, 40, 50};
    std::vector<std::pair<int, int>> result_a = pairing(a);
    for (const auto& p : result_a) {
        std::cout << "{" << p.first << ", " << p.second << "} ";
    }
    std::cout << std::endl;


    std::list<std::string> b = {"cat", "dog", "mouse", "lion"};
    std::vector<std::pair<std::string, std::string>> result_b = pairing(b);
    for (const auto& p : result_b) {
        std::cout << "{" << p.first << ", " << p.second << "} ";
    }
    std::cout << std::endl;

    /*
    std::string c = "Hello";
    std::vector<std::pair<char, char>> result_c = pairing(c);
    for (const auto& p : result_c) {
        std::cout << "{" << p.first << ", " << p.second << "} ";
    }
    std::cout << std::endl;
    */
   
    return 0;
}
