/*
Note: Try to solve this task in-place (with O(1) additional memory), 
since this is what you'll be asked to do during an interview.

You are given an n x n 2D matrix that represents an image. 
Rotate the image by 90 degrees (clockwise).

Example 
For a= 
	[[1, 2, 3],
	 [4, 5, 6],
	 [7, 8, 9]]

the output should be rotateImage(a) =
	[[7, 4, 1],
	 [8, 5, 2],
	 [9, 6, 3]]

Input/Output
	[time limit] 500ms (cpp)
	[input] array.array.integer a

Guaranteed constraints:
	1 ≤ a.length ≤ 100,
	a[i].length = a.length,
	1 ≤ a[i][j] ≤ 104.

[output] array.array.integer
*/
#include "../eval_t.h"
#include <vector>

typedef std::vector<int> v_int;
typedef std::vector<v_int> v_v_int;

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

v_v_int rotateImage(v_v_int a) {
	int max = a.size() - 1;
	int i,j;

	for (i = 0; i< max - i; i++) {
		j = i;

		// rotate corners
		swap(a[i][j], a[j][max - i]);
		swap(a[i][j], a[max - j][i]);
		swap(a[max - j][i], a[max - i][max - j]);

		// rotate inners
		for (j++; j <= max - (i+1); j++) {
			swap(a[i][j], a[j][max - i]);
			swap(a[i][j], a[max - j][i]);
			swap(a[max - j][i], a[max - i][max - j]);
		}
	}

	return a;
}

void main() {
	v_v_int in, out;

	in = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	out = { { 7, 4, 1 },{ 8, 5, 2 },{ 9, 6, 3 } };
	eval_test::EvalTest("Test 1", rotateImage(in), out);

	in = { { 1, 2, 3, 4 },{ 5, 6, 7, 8},{ 9, 10, 11, 12},{ 13, 14, 15, 16 } };
	out = { { 13, 9, 5, 1 },{ 14, 10, 6, 2 },{ 15, 11, 7, 3 },{ 16, 12, 8, 4} };
	eval_test::EvalTest("Test 2", rotateImage(in), out);

	in = { { 10, 9, 6, 3, 7 },{ 6, 10, 2, 9, 7 },{ 7, 6, 3, 8, 2 },{ 8, 9, 7, 9, 9 },{ 6, 8, 6, 8, 2 } };
	out = { { 6, 8, 7, 6, 10 },{ 8, 9, 6, 10, 9 },{ 6, 7, 3, 2, 6 },{ 8, 9, 8, 9, 3 },{ 2, 9, 2, 7, 7 } };
	eval_test::EvalTest("Test 3", rotateImage(in), out);

	getchar();
}