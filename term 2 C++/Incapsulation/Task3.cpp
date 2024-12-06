#include <iostream> // cin, cout etc
#include <cstdlib>
#include <vector>
#include <string> //std::string


int main(){
	int* p1 = new int{123};
	std::string* p2 = new std::string{"Cats and Dogs"};
	int* p3 = new int[5] {10, 20, 30, 40, 50};
	std::vector<int>* p4= new std::vector{{10, 20, 30, 40, 50}};
	std::string* p5 = new std::string[3] {"Cat", "Dog", "Mouse"};

	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	for (int i = 0; i < 5; i++){
		std::cout << p3[i] << " ";
	}
	std::cout << std::endl;
	for (int num : *p4){
		std::cout << num << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 3; i++){
		std::cout << p5[i] << " ";
	}
	std::cout << std::endl;

	delete p1;
	delete p2;
	delete[] p3;
	delete p4;
	delete[] p5;
}
