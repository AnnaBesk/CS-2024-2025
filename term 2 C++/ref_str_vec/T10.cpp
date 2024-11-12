#include <iostream>
#include <string>


bool isDomainName(std::string x){
    int len = x.length();
    std::string beg = x.substr(0, 4);
    if (len >= 7){
        std::string end = x.substr(len - 4);
        if (beg == "www." && end == ".com"){
            return true;
        }
    }
    return false;
}

int main()
{

	std::cout << isDomainName("www.google.com") << std::endl;         // Напечатает 1
	std::cout << isDomainName("abc") << std::endl;                    // Напечатает 0
	std::cout << isDomainName("hello.com") << std::endl;              // Напечатает 0
}