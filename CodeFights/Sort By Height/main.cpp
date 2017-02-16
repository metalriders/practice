/*
Some people are standing in a row in a park. 
There are trees between them which cannot be moved. 
Your task is to rearrange the people by their heights in a non-descending order without moving the trees.
*/

#include "../eval_t.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace eval_test;
typedef std::vector<int> v_int;

v_int sortByHeight(v_int a) {
	v_int tmp = a;
	std::sort(tmp.begin(), tmp.end());

	int idx = 0;
	for (int i : tmp) {
		if (i >= 0) {
			while (a[idx] == -1)
				++idx;
			a[idx] = i;
			++idx;
		}
	}

	return a;
}

[[noreturn]] void main()
{
	v_int in_arr, out_arr;

	// Test 1
	in_arr = { -1, 150, 190, 170, -1, -1, 160, 180 };
	out_arr = { -1, 150, 160, 170, -1, -1, 180, 190 };
	EvalTest(sortByHeight(in_arr), out_arr);
	
	// Test 2
	in_arr = { -1, -1, -1, -1, -1 };
	out_arr = { -1, -1, -1, -1, -1 };
	EvalTest(sortByHeight(in_arr), out_arr);

	// Test 3
	in_arr = { 4, 2, 9, 11, 2, 16 };
	out_arr = { 2, 2, 4, 9, 11, 16 };
	EvalTest(sortByHeight(in_arr), out_arr);

	getchar();
}