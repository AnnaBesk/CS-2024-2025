#include <iostream>
#include <string>
#include <vector>
// Тут нужно написать функцию concatenate
std::string concatenate(const std::vector<std::string>& words){
    int s = words.size();
    std::string res = words[0];
    for (int i = 1; i < s; i++){
        res += words[i];
    }
    return res;

}

int main()
{
	std::vector<std::string> v {"Cat", "Dog", "Mouse", "Tiger", "Elk"};
	std::cout << concatenate(v) << std::endl; // Должно напечатать CatDogMouseTigerElk
}