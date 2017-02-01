#ifndef _G_STACK_H_
#define _G_STACK_H_

template<typename T>
class g_stack
{
private:
	size_t instances;
public:
	g_stack();
	g_stack(const g_stack<T>&);
	~g_stack();

	size_t num_instances();
};

#include "g_stack.hpp"

#endif // !_G_STACK_H_
