#include "g_stack.h"
#include <iostream>

int main(int argv[], char** argc)
{
	g_stack<char> stack = g_stack<char>();
	std::cout << stack.num_instances();
	return 0;
}