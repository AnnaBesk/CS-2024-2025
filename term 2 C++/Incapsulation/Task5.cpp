#include <iostream>
#include <string>
using namespace std::string_literals;


int sumNum(const std::string& str) {
    if (str.length() < 2 || str[0] != '[' || str.back() != ']') {
        throw std::invalid_argument("Incorrect input string format");
	}

    std::string ss = str.substr(1, str.length() - 2);

	int length = ss.size();
	int sum = 0;
	int cur_num;
	std::string cur;
	for (int i = 0; i < length; i++){
		if (ss[i] == ' '){
			continue;
		}
		else if (ss[i] == ','){
			sum += std::stoi(cur);
			cur = ""s;
		}
		else{
			cur.push_back(ss[i]);
		}
	}
	if(cur != ""s){
		sum += std::stoi(cur);
	}
	
	return sum;
}

int main() {
	std::string s1 = "[10, 20, 30, 40, 50]"s; //150
	std::string s2 = "[4, 8, 15, 16, 23, 42]"s; //108
	std::string s3 = "[20]"s; //20
	std::string s4 = "[]"s; //0
    try {
        std::cout << "Сумма чисел: " << sumNum(s1) << std::endl;
		std::cout << "Сумма чисел: " << sumNum(s2) << std::endl;
		std::cout << "Сумма чисел: " << sumNum(s3) << std::endl;
		std::cout << "Сумма чисел: " << sumNum(s4) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}