#ifndef _G_STACK_H_
#define _G_STACK_H_

template<typename T>
class g_stack
{
private:
	static size_t instances;
public:
	g_stack();
	g_stack(const g_stack<T>&);
	~g_stack();

	static const size_t g_stack<T>::GetInstancesQty();
};

#include "g_stack.hpp"

#endif // !_G_STACK_H_
