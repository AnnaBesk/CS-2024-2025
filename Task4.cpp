#include <iostream>
#include <map>

int main(){
    int n;
    std::cin >> n;
    std::map<int, int> data;

    for (int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        if (data.find(x) != data.end()){
            data[x] += 1;
        }
        else{
            data[x] = 1;
        }
    }

    for (std::map<int, int>::iterator it = data.begin(); it != data.end(); ++it){
        std::cout << it->first << " ";
    }
    std::cout << std::endl;

    for (std::map<int, int>::iterator it = data.begin(); it != data.end(); ++it){
        std::cout << it->second << " ";
    }
    std::cout << std::endl;
}