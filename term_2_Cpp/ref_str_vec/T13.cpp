#include <iostream>
#include <string>
#include <vector>
void print(const std::vector<std::string>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}
// Тут нужно написать функцию prefixes
std::vector<std::string> prefixes(const std::string word){
    int s = word.length();
    std::vector<std::string> output;
    for (int i = 1; i < s + 1; i++){
        output.push_back(word.substr(0, i));
    }
    return output;
}

int main()
{
    std::vector<std::string> v = prefixes("Mouse");
    print(v);  // Должно напечатать M Mo Mou Mous Mouse
}