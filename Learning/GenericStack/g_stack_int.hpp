#ifndef _G_STACK_INT_HPP_
#define _G_STACK_INT_HPP_

template<>
g_stack<int>::g_stack()
{
	++g_stack<int>::instances;
}

template<>
g_stack<int>::g_stack(const g_stack<int> &other)
{
	++g_stack<int>::instances;
}

template<>
g_stack<int>::~g_stack()
{
}

template<>
inline const size_t g_stack<int>::GetInstancesQty()
{
	return g_stack<int>::instances;
}

//size_t g_stack<int>::instances = 2;

#endif // !_G_STACK_INT_HPP_