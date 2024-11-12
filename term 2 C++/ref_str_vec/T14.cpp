#include <iostream>
#include <string>
#include <vector>
void print(const std::vector<std::size_t>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}
// Тут нужно написать функцию substringIndexes
std::vector<std::size_t> substringIndexes(const std::string word1, const std::string word2){
    int s1 = word1.length();
    int s2 = word2.length();

    std::string word = word1;
    std::vector<std::size_t> output;
    int ind = 0;
    int cur = 0;
     if (word.find(word2) == -1){
        std::vector<std::size_t> output1;
        return output1;
    }
    while (s1 > ind && ind != -1){
        ind = word.find(word2);
        if (ind != -1){
            output.push_back(ind + cur);
        }
        cur += ind + 1;
        word = word.substr(ind + 1);
        s1 = word.length();
    }
    return output;
}

int main()
{
    std::vector<std::size_t> v1 = substringIndexes("cat and dog and cat", "cat");
    print(v1);  // Должно напечатать 0 16
    
    std::vector<std::size_t> v2 = substringIndexes("look, cats were here", "cat");
    print(v2);  // Должно напечатать 6
  
    std::vector<std::size_t> v3 = substringIndexes("catcatcatcatcatcat", "cat");
    print(v3);  // Должно напечатать 0 3 6 9 12 15
    
    std::vector<std::size_t> v4 = substringIndexes("dog mouse elephant", "cat");
    print(v4);  // Не должно ничего печатать

    
}