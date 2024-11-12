#include <cstdio>
#include <iostream>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& book){
    if (book.price > 1000){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Book p = {"Rules", 100, 10};
    Book q = {"Manual", 120, 1110};
    
    std::cout << isExpensive(p) << " " << isExpensive(q) << std::endl;
}