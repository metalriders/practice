#include "g_stack.h"

#ifndef _G_STACK_HPP_
#define _G_STACK_HPP_

template<typename T>
g_stack<T>::g_stack()
{
	instances = 0;
}

template<typename T>
g_stack<T>::g_stack(const g_stack<T> &other)
{
	instances = other.num_instances();
}

template <typename T>
g_stack<T>::~g_stack()
{
}

template<typename T>
size_t g_stack<T>::num_instances()
{
	return instances;
}

#endif // !_G_STACK_HPP_