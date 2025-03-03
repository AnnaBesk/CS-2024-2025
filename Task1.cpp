#include <iostream>
#include <list>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::list<int> circle(n);          // список list2 состоит из 5 чисел, каждый элемент имеет значение по умолчанию
    int count = 1;

    
    for (std::list<int>::iterator it = circle.begin(); it != circle.end(); ++it){
        *it = count;
        count += 1;
    }

    std::list<int>::iterator it = circle.begin();
    
    while (circle.size() > 1){
        for (int i = 0; i < m - 1; i++){
            ++it;
            if (it == circle.end()){
                it = circle.begin();
            }
        }

        std::cout << *it << " ";
        it = circle.erase(it);
        if (it == circle.end()) {
            it = circle.begin();
        }
    }
    
    std::cout << std::endl;
    std::cout << circle.front() << std::endl;
}

