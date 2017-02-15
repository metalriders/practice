/* template functions for evaluate data of tests from CodeFights problems*/
#ifndef _EVAL_TEST_H_
#define _EVAL_TEST_H_

#define _E_TEST_BEGIN  namespace eval_test {
#define _E_TEST_END  }

_E_TEST_BEGIN
// Generic specialization
template <typename T>
static const char* EvalTest(T a, T b)
{
	return a == b ? "pass" : "fail";
}

/* Specializations  */
template <>
static const char* EvalTest(const char * a, const char * b)
{
	return a == b ? "pass" : "fail";
}

_E_TEST_END
#endif // !_EVAL_T_H_