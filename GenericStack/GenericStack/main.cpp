#include "g_stack.h"
#include <iostream>

int main(int argv[], char** argc)
{
	g_stack<char>::SetInstances(12);

	g_stack<char> c_stack = g_stack<char>();
	g_stack<char> c_stack2(c_stack);
	g_stack<int> i_stack = g_stack<int>();

	std::cout << c_stack.num_instances() << "\n";
	std::cout << i_stack.num_instances() << "\n";
	return 0;
}