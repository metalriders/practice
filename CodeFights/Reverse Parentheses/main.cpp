/*
You are given a string s that consists of English letters, punctuation marks, whitespace characters and brackets. 
It is guaranteed that the brackets in s form a regular bracket sequence.

Your task is to reverse the strings in each pair of matching parenthesis, starting from the innermost one.

Example

For string "s = a(bc)de" the output should be

reverseParentheses(s) = "acbde".

Input/Output

[time limit] 500ms (cpp)
[input] string s

A string consisting of English letters, punctuation marks, whitespace characters and brackets. It is guaranteed that parenthesis form a regular bracket sequence.

Constraints:

5 ≤ x.length ≤ 55.

[output] string
*/

#include "../eval_t.h"
#include <iostream>
#include <map>

typedef std::string _str;
typedef std::map<int, char> m_int_chr;

void updateParentesesIndexes(m_int_chr &parenteses, int idx)
{
	for (m_int_chr::const_iterator it = parenteses.begin(); it != parenteses.end(); ++it)
	{
		if (it->first > idx) {

			parenteses[it->first-2] = it->second;
			parenteses.erase((it--)->first);
		}
	}
}

_str reverseParentheses(_str s)
{
	int open_par = 0;
	m_int_chr parenteses;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == ')') parenteses[i] = s[i];
	}

	while (!parenteses.empty()) 
	{
		for (m_int_chr::const_iterator it = ++(parenteses.begin()); it != parenteses.end(); ++it)
		{
			auto prev_it = it;

			if ((--prev_it)->second == '(' && it->second == ')')
			{
				int b_idx = prev_it->first;
				_str reversed = s.substr(b_idx + 1, it->first - b_idx - 1);
				
				std::reverse(reversed.begin(), reversed.end());
				s.replace(b_idx, reversed.size() + 2, reversed);

				parenteses.erase(prev_it);
				parenteses.erase(it);
				updateParentesesIndexes(parenteses, b_idx);
				break;
			}
		}
	}

	return s;
}

[[noreturn]] void main()
{
	_str s, out;

	// Test 1
	s = "a(bc)de";
	out = "acbde";
	eval_test::EvalTest(reverseParentheses(s), out);

	// Test 3
	s = "co(de(fight)s)";
	out = "cosfighted";
	eval_test::EvalTest(reverseParentheses(s), out);

	// Test 4
	s = "Code(Cha(lle)nge)";
	out = "CodeegnlleahC";
	eval_test::EvalTest(reverseParentheses(s), out);

	puts("Press a key to finish");
	getchar();
}