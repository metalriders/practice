/*
Note: Write a solution that only iterates over the string once and uses O(1) additional memory, 
since this is what you would be asked to do during a real interview.

Given a string s, find and return the first instance of a non-repeating character in it. 
If there is no such character, return '_'.

Example

For s = "abacabad", the output should be
firstNotRepeatingCharacter(s) = 'c'.

There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.

For s = "abacabaabacaba", the output should be
firstNotRepeatingCharacter(s) = '_'.

There are no characters in this string that do not repeat.

Input/Output

[time limit] 500ms (cpp)
[input] string s

A string that contains only lowercase English letters.

Guaranteed constraints:
1 ≤ s.length ≤ 105.

[output] char

The first non-repeating character in s, or '_' if there are no characters that do not repeat.
*/

#include "../eval_t.h"
#include <list>

typedef std::string string;
typedef std::list<char> l_char;

char firstNotRepeatingCharacter(std::string s) {
	int alphabeth[27] = { 0 };
	l_char uniques;

	for (auto i : s) {
		int ch_idx = i - 'a';
		if (++alphabeth[ch_idx] == 1) {
			uniques.push_back(i);
		}
	}

	for (auto i : uniques) {
		int ch_idx = i - 'a';
		if (alphabeth[ch_idx] == 1) return i;
	}

	return '_';
}

void main()
{
	string a;

	a = "abacabad";
	eval_test::EvalTest("Test 1", firstNotRepeatingCharacter(a), 'c');

	a = "abacabaabacaba";
	eval_test::EvalTest("Test 2", firstNotRepeatingCharacter(a), '_');

	a = "z";
	eval_test::EvalTest("Test 3", firstNotRepeatingCharacter(a), 'z');

	a = "bcb";
	eval_test::EvalTest("Test 4", firstNotRepeatingCharacter(a), 'c');

	a = "bcccccccb";
	eval_test::EvalTest("Test 5", firstNotRepeatingCharacter(a), '_');

	getchar();
}
