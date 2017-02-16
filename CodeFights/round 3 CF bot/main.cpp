#include "..\eval_t.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace eval_test;

#define _STD ::std::
#define _STR _STD string 

typedef _STR _str;
typedef _STD vector<_str> v_str;
typedef _STD map<char, char> m_ch_ch;
typedef _STD map<_str, _str> m_str_str;

const char spc = ' ';
const char b_line = '\\';
const _str digits = "0123456789";
const _str sp_chr = " ,:;[](){}\"'*-+";

const v_str operands
{
	{"!=="},{"==="},{"=="},
	{"<="},{ ">=" },{ "!=" },
	{"="}
};
const v_str kwords
{ 
	{ "if"},{ "for"},{"function" },
	{ "return" },{ "print" } 
};

bool plagiarismCheck(v_str code1, v_str code2)
{
	std::string cod1, cod2;
	v_str words;

	for (auto line : code1) cod1 += line + b_line;
	for (auto line : code2) cod2 += line + b_line;
	
	// look for words
	std::string c_word = "";
	int p_code = 0;

	for (int i = 0; i < cod1.size(); i++)
	{
		if (sp_chr.find_first_of(cod1[i]) == _STR::npos && cod1[i] != b_line)	// not a special character so track word/var
		{
			c_word += cod1[i];
			continue;
		}
		else if (!c_word.empty() && 		 // word found but is a keyword or a comparator or a number
			(_STD find(kwords.begin(), kwords.end(), c_word) != kwords.end() ||
				_STD find(operands.begin(), operands.end(), c_word) != operands.end()) ||
			digits.find_first_of(c_word[0]) != _STR::npos
			)
		{
			p_code = i;
			c_word.clear();
		}
		else if (!c_word.empty())
		{
			size_t idx = p_code;		//get idx for begin of word to find

			if (c_word.compare(cod2.substr(idx, c_word.size())) != 0)
			{
				std::string check_word = "";
				int s_idx = idx;
				
				while (cod2[s_idx] != '\\' && sp_chr.find_first_of(cod2[s_idx]) == _STR::npos)
				{
					check_word += cod2[s_idx];
					s_idx++;
				}

				// find & replace
				while (idx < cod2.size())
				{
					idx = cod2.find(check_word, idx);
					if (idx != _STR::npos) {
						cod2.replace(idx, check_word.size(), c_word, 0, c_word.size());
						idx += c_word.size();
					}
				}
			}

			if(_STD find(words.begin(), words.end(), c_word) == words.end())
				words.push_back(c_word);

			p_code = i;
			c_word.clear();
		}

		//if we are not tracking a word just get a trail of previous code
		p_code++;
	}

	std::cout << cod1 << std::endl;
	std::cout << cod2 << std::endl;

	return cod1.compare(cod2)==0;
}

void main()
{
	std::vector<std::string> code1, code2;

	// Test 1
	code1 = {	"def is_even_sum(a, b):",
				"    return (a + b) % 2 == 0" };
	code2 = {	"def is_even_sum(summand_1, summand_2):",
				"    return (summand_1 + summand_2) % 2 == 0" };
	//EvalTest(plagiarismCheck(code1, code2), true );

	// Test 2
	code1 = {	"function is_even_sum(a, b) {",
				"  return (a + b) % 2 === 0;",
				"}" };
	code2 = {	"function is_even_sum(a, b) {",
				"  return (a + b) % 2 !== 1;",
				"}" };
	//EvalTest( plagiarismCheck(code1, code2), false );

	// Test 6
	code1 = { "def return_first(f, s):",
		"  t = f",
		"  return f" };
	code2 = { "def return_first(f, s):",
		"  f = f",
		"  return f" };
	EvalTest(plagiarismCheck(code1, code2), true);

	// Test 7
	code1 = { "if (2 * 2 == 5 &&",
			"true):",
			"  print 'Tricky test ;)'" };
	code2 = { "if (2 * 2 == 5",
			"&& true):",
			"  print 'Tricky test ;)'" };
	EvalTest (plagiarismCheck(code1, code2), false );

	// Test 11
	code1 = { "def return_smth(a, b):",
			"  return a + a" };
	code2 = { "def return_smth(a, b):",
			"  return a + b" };
	EvalTest(plagiarismCheck(code1, code2), false);

	// Test 12
	code1 = { "def f(a,b)",
			"    return a + b" };
	code2 = { "def f(b,a)",
			"    return b + a" };
	EvalTest(plagiarismCheck(code1, code2), true);
	
	// Test 13
	code1 = { "def f(a,b)",
			"    return a + b" };
	code2 = { "def f(b,a)",
			"    return a + b" };
	EvalTest(plagiarismCheck(code1, code2), false);

	getchar();
}