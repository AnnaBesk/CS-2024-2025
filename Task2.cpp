#include <iostream>
#include <set>

int main(){
    std::set<int> st;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        st.insert(x);
    }

    for(std::set<int>::iterator it = st.begin(); it != st.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}