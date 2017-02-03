#include "g_stack.h"

#ifndef _G_STACK_HPP_
#define _G_STACK_HPP_

template<typename T>
size_t g_stack<T>::instances = 0;

template<typename T>
g_stack<T>::g_stack()
{
	++g_stack<T>::instances;
}

template<typename T>
g_stack<T>::g_stack(const g_stack<T> &other)
{
	++g_stack<T>::instances;
}

template <typename T>
g_stack<T>::~g_stack()
{
}

template<typename T>
inline const size_t g_stack<T>::GetInstancesQty()
{
	return g_stack<T>::instances;
}

#endif // !_G_STACK_HPP_