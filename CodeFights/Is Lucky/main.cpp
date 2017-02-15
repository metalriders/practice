/* 
Ticket numbers usually consist of an even number of digits. 
A ticket number is considered lucky if the sum of the first half of the digits is equal to the sum of the second half.

Given a ticket number n, determine if it's lucky or not. 
*/

#include <iostream>
#include <vector>
#include <assert.h>
#include "../eval_t.h"

using namespace eval_test;

bool isLucky(int n)
{
	return true;
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