/*
A cryptarithm is a mathematical puzzle for which the goal is to find the correspondence between letters and digits, such that the given arithmetic equation consisting of letters holds true when the letters are converted to digits.

You have an array of strings crypt, the cryptarithm, and an an array containing the mapping of letters and digits, solution. The array crypt will contain three non-empty strings that follow the structure: [word1, word2, word3], which should be interpreted as the word1 + word2 = word3 cryptarithm.

If crypt, when it is decoded by replacing all of the letters in the cryptarithm with digits using the mapping in solution, becomes a valid arithmetic equation containing no numbers with leading zeroes, the answer is true. If it does not become a valid arithmetic solution, the answer is false.

Example

For crypt = ["SEND", "MORE", "MONEY"] and

solution = [['O', '0'],
['M', '1'],
['Y', '2'],
['E', '5'],
['N', '6'],
['D', '7'],
['R', '8'],
['S', '9']]
the output should be
isCryptSolution(crypt, solution) = true.

When you decrypt "SEND", "MORE", and "MONEY" using the mapping given in crypt, you get 9567 + 1085 = 10652 which is correct and a valid arithmetic equation.

For crypt = ["TEN", "TWO", "ONE"] and

solution = [['O', '1'],
['T', '0'],
['W', '9'],
['E', '5'],
['N', '4']]
the output should be
isCryptSolution(crypt, solution) = false.

Even though 054 + 091 = 145, 054 and 091 both contain leading zeroes, meaning that this is not a valid solution.

Input/Output

[time limit] 500ms (cpp)
[input] array.string crypt

An array of three non-empty strings containing only uppercase English letters.

Guaranteed constraints:
crypt.length = 3,
1 ≤ crypt[i].length ≤ 14.

[input] array.array.char solution

An array consisting of pairs of characters that represent the correspondence between letters and numbers in the cryptarithm. The first character in the pair is an uppercase English letter, and the second one is a digit in the range from 0 to 9.

Guaranteed constraints:
solution[i].length = 2,
'A' ≤ solution[i][0] ≤ 'Z',
'0' ≤ solution[i][1] ≤ '9',
solution[i][0] ≠ solution[j][0], i ≠ j,
solution[i][1] ≠ solution[j][1], i ≠ j.

It is guaranteed that solution only contains entries for the letters present in crypt and that different letters have different values.

[output] boolean

Return true if the solution represents the correct solution to the cryptarithm crypt, otherwise return false.*/

#include "../eval_t.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

typedef std::string str;
typedef std::map<char, char> m_char_char;
typedef std::vector<str> v_str;
typedef std::vector<char> v_char;
typedef std::vector<v_char> v_v_char;

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
	m_char_char m_solution;
	bool valid;

	// have a better map
	for (auto s : solution) {
		m_solution[s[0]] = s[1];
	}

	// decrypt and check leading zeroes
	for (auto &word : crypt) {
		valid = false;
		for (auto &ch : word) {
			ch = m_solution[ch];
			if (ch == '0' && !valid && word.size() > 1) {
				return false;
			}
			else {
				valid = true;
			}
		}
	}
	
	// check arithmetic
	return stoll(crypt[0]) + stoll(crypt[1]) == stoll(crypt[2]);
}

[[noreturn]] void main()
{
	v_str crypt;
	v_v_char solution;

	// Test 1
	crypt = { "SEND", "MORE", "MONEY" };
	solution = { { 'O','0' },
				 { 'M','1' },
				 { 'Y','2' },
				 { 'E','5' },
				 { 'N','6' },
				 { 'D','7' },
				 { 'R','8' },
				 { 'S','9' } };

	eval_test::EvalTest("Test 1", isCryptSolution(crypt, solution), true);

	// Test 2
	crypt = { "TEN", "TWO", "ONE" };
	solution = { { 'O','1' },
				 { 'T','0' },
				 { 'W','9' },
				 { 'E','5' },
				 { 'N','4' } };

	eval_test::EvalTest("Test 2", isCryptSolution(crypt, solution), false);

	// Test 3
	crypt = { "A", "B", "C" };
	solution = { { 'A', '5' },
				 { 'B', '6' },
				 { 'C', '1' } };

	eval_test::EvalTest("Test 3", isCryptSolution(crypt, solution), false);

	// Test 4
	crypt = { "AA", "AA", "AA" };
	solution = { { 'A', '0' } };

	eval_test::EvalTest("Test 4", isCryptSolution(crypt, solution), false);

	puts("Press a key to finish");
	getchar();
}