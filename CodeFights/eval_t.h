/* template functions for evaluate data of tests from CodeFights problems*/
#ifndef _EVAL_TEST_H_
#define _EVAL_TEST_H_

#define _E_TEST_BEGIN  namespace eval_test {
#define _E_TEST_END  }

#include <iostream>

_E_TEST_BEGIN
// Generic specialization
template <typename T>
static void EvalTest(T a, T b)
{
	std::cout << a == b ? "pass" : "fail" << "\n";
}

/* Specializations  */
template <>
static void EvalTest(const char * a, const char * b)
{
	std::cout << (a == b ? "pass" : "fail") << "\n";
}

_E_TEST_END
#endif // !_EVAL_T_H_