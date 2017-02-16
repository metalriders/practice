/* 
Ticket numbers usually consist of an even number of digits. 
A ticket number is considered lucky if the sum of the first half of the digits is equal to the sum of the second half.

Given a ticket number n, determine if it's lucky or not. 
*/

#include "../eval_t.h"
#include <iostream>
#include <string>

using namespace eval_test;
typedef std::string _str;

bool isLucky(int n) {
	_str s_num = std::to_string(n);
	int lhs = 0, rhs = 0;
	int len = s_num.size();

	for (int i = 0; i<len / 2; i++) {
		lhs += s_num[i];
		rhs += s_num[len - i - 1];
	}
	return lhs == rhs;
}

[[noreturn]] void main() 
{
	int n;

	n = 1230;
	EvalTest(isLucky(n), true);
	
	n = 239017;
	EvalTest(isLucky(n), false);

	n = 239017;
	EvalTest(isLucky(n), true);

	getchar();
}