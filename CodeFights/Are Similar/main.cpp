/*
Two arrays are called similar if one can be obtained from another by swapping at most one pair of elements.

Given two arrays, check whether they are similar.

Example

For A = [1, 2, 3] and B = [1, 2, 3], the output should be
areSimilar(A, B) = true;
For A = [1, 2, 3] and B = [2, 1, 3], the output should be
areSimilar(A, B) = true;
For A = [1, 2, 2] and B = [2, 1, 1], the output should be
areSimilar(A, B) = false.
Input/Output

[time limit] 500ms (cpp)
[input] array.integer A

Array of integers.

Constraints:
3 ≤ A.length ≤ 105,
1 ≤ A[i] ≤ 1000.

[input] array.integer B

Array of integers of the same length as A.

Constraints:
B.length = A.length,
1 ≤ B[i] ≤ 1000.

[output] boolean

true if A and B are similar, false otherwise.
*/

#include "../eval_t.h"
#include <vector>

typedef std::vector<int> v_int;

int safeFind(v_int &a, v_int &b, int ofs, int val)
{
	for (int i = ofs; i < a.size(); i++) {
		if (a[i] == val && b[i] != val) return i;
	}
	return -1;
};

bool areSimilar(v_int a, v_int b) {
	int diff_nums = 0;

	for (int i = 0; i < a.size() && diff_nums < 2; i++)
	{
		if (a[i] != b[i])
		{
			diff_nums++;
			int s_val = safeFind(a, b, i, b[i]);
			if (s_val == -1) return false;
			std::iter_swap(i + a.begin(), s_val + a.begin());
		}
	}
	return diff_nums < 2;
}

void main()
{
	v_int a, b;

	a = { 1, 2, 3 };
	b = { 1, 2, 3 };
	eval_test::EvalTest("Test 1", areSimilar(a, b), true);

	a = { 1, 2, 3 };
	b = { 2, 1, 3 };
	eval_test::EvalTest("Test 2", areSimilar(a, b), true);

	a = { 1, 2, 2 };
	b = { 2, 1, 1 };
	eval_test::EvalTest("Test 3", areSimilar(a, b), false);

	a = { 1, 2, 3 };
	b = { 1, 10, 2 };
	eval_test::EvalTest("Test 4", areSimilar(a, b), false);

	a = { 2, 3, 1 };
	b = { 1, 3, 2 };
	eval_test::EvalTest("Test 5", areSimilar(a, b), true);

	a = { 1, 2, 3, 4, 3 };
	b = { 3, 2, 1, 3, 4 };
	eval_test::EvalTest("Custom Test 1", areSimilar(a, b), false);

	getchar();
}