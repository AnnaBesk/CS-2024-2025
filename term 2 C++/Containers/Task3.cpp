#include <iostream>
#include <set> 

int main(){
    int n;
    std::cin >> n;
    std::multiset<int> data; 
    for (int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        data.insert(x);
    }

    for(std::multiset<int>::iterator it = data.begin(); it != data.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}