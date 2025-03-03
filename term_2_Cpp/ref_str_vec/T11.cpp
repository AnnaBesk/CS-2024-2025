#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void doubling(std::vector<int>& x){
    int len = x.size();
    for (int i = 0; i < len; i++){
        x.push_back(x[i]);
    }

}

int main()
{
    std::vector<int> v {10, 20, 30} ;
    doubling(v);
    print(v); 
}