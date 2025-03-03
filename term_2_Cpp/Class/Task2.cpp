#include <iostream>
#include "Vector2f.hpp"
using std::cout, std::endl;

int main() 
{
	Vector2f a = {1.0, 2.0};
	Vector2f b = {4.0, -1.0};
	cout << "a = " << a << "b = " << b;
	cout << "a + b = " << a + b;
	cout << "-a = " << -a;
	cout << "Scalar product of a and b = " << a * b << endl;
	a += b;
	cout << "a after a+= b;" << a;
}