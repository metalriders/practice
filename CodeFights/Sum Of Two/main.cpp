/* Google interview */

#include "../eval_t.h"
#include <iostream>
#include <vector>

typedef std::vector<int> v_int;

bool sumOfTwo(v_int a, v_int b, int v) 
{
	int comp;

	for (auto it = a.begin(); it != a.end(); it++)
	{
		if ((comp = v - *it) < 0) continue;

		if (std::find(b.begin(), b.end(), comp) != b.end()) return true;
	}
	return false;
}

[[noreturn]] void main()
{
	v_int a, b;
	int v;
	
	// Test 1
	a = { 1, 2, 3 };
	b = { 10, 20, 30, 40 };
	v = 42;
	eval_test::EvalTest(sumOfTwo(a, b, v), true);

	// Test 7
	a = { 4, 6, 4, 2, 9, 6, 6, 2, 9, 2 };
	b = { 3, 4, 5, 1, 4, 10, 9, 9, 6, 4 };
	v = 5;
	eval_test::EvalTest(sumOfTwo(a, b, v), true);

	// Test 1
	a = { 6, 10, 25, 13, 20, 21, 11, 10, 18, 21 };
	b = { 21, 10, 6, 0, 29, 25, 1, 17, 19, 25 };
	v = 37;
	eval_test::EvalTest(sumOfTwo(a, b, v), true);

	puts("Press a key to finish");
	getchar();
}