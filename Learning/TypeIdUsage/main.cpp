#include "person.h"
#include <iostream>
#include <typeinfo>
#include <vector>
#include <queue>

int main()
{
	Person me();
	
	std::cout << "Person typeid> " << typeid(me).name() << std::endl;
	std::cout << "int typeid> " << typeid(123).name() << std::endl;
	std::cout << "std::queue typeid> " << typeid(std::queue<int>).name() << std::endl;
	std::cout << "std::vector typeid> " << typeid(std::vector<int>).name() << std::endl;
	getchar();
	return 0;
}