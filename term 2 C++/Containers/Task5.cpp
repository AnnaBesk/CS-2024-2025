#include <iostream>
#include <set>
#include <algorithm>


int main() {
    int n, k;
    std::cin >> n >> k;

    std::set<int> cuts;
    std::multiset<int> length;

    length.insert(n);
    cuts.insert(0);
    cuts.insert(n);



    for (int i = 0; i < k; ++i) {
        int cut_pos;
        std::cin >> cut_pos;
        
        auto it = cuts.upper_bound(cut_pos);

        if (it != cuts.begin()) {
            auto prev_it = prev(it);
            int len1 = *it - cut_pos; 
            int len2 = cut_pos - *prev_it; 
            int len_initial = *it - *prev_it;
            
            length.erase(length.find(len_initial)); 

            cuts.insert(cut_pos);


            length.insert(len1);
            length.insert(len2);

        } else {
            int len = *cuts.begin();

            length.erase(len); 
            length.insert(cut_pos);
            length.insert(len - cut_pos);

            cuts.insert(cut_pos);

        }
        std::cout << *prev(length.end()) << " ";
    }
    std::cout << std::endl;
}
