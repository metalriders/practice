#include "..\eval_t.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define _STD ::std::
#define _STR _STD string 

using namespace eval_test;

typedef _STR _str;
typedef _STD vector<_str> v_str;
typedef _STD map<char, char> m_ch_ch;
typedef _STD map<_str, _str> m_str_str;

const char spc = ' ';
const char b_line = '\\';
const _str sp_chr = " ,:;[](){}\"'*-+";

const v_str kwords
{ 
	{ "if"},{ "for"},{"function" },
	{ "return" },{ "print" } 
};

bool plagiarismCheck(v_str code1, v_str code2)
{
	std::string cod1, cod2;
	bool word_rec = false;
	for (auto line : code1) cod1 += line + spc;
	for (auto line : code2) cod2 += line + spc;
	
	// Special case :P (not likely to happen) ???
	//if (cod1.compare(cod2)) return true;
	
	//remove all spaces ???

	std::cout << cod1 << std::endl;
	std::cout << cod2 << std::endl;

	// look for words
	std::string c_word = "";
	std::string p_code = "";

	for (int i = 0; i < cod1.size(); i++)
	{
		if (sp_chr.find_first_of(cod1[i]) == _STR::npos && cod1[i] != b_line)	// not a special character so track word/num/var
		{
			c_word += cod1[i];
			word_rec = true;
			continue;
		}
		else if(!c_word.empty() && _STD find(kwords.begin(), kwords.end(),c_word) != kwords.end()) // word found but is a keyword
		{
			p_code += c_word;
			c_word.clear();
			word_rec = false;
		}
		else if(!c_word.empty())
		{
			size_t idx = cod2.find(p_code, 0) + p_code.size();		//get idx for begin of word to find

			if (c_word.compare(cod2.substr(idx, c_word.size())) != 0)
			{
				std::string check_word = "";
				int s_idx = idx;
				
				// get word changed
				while (sp_chr.find_first_of(cod2[s_idx]) == _STR::npos)
				{
					check_word += cod2[s_idx];
					s_idx++;
				}

				// find & replace
				while (idx < cod2.size())
				{
					idx = cod2.find(check_word, 0);
					if (idx == _STR::npos) break;
					cod2.replace(idx, check_word.size(), c_word, 0, c_word.size());
				}
			}
			p_code += c_word;
			c_word.clear();
			word_rec = false;
		}

		//if we are not tracking a word just get a trail of previous code
		p_code += cod1[i];
	}

	// compare the two codes

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
	EvalTest( plagiarismCheck(code1, code2), true );

	// Test 2
	code1 = {	"function is_even_sum(a, b) {",
				"  return (a + b) % 2 === 0;",
				"}" };
	code2 = {	"function is_even_sum(a, b) {",
				"  return (a + b) % 2 !== 1;",
				"}" };
	EvalTest( plagiarismCheck(code1, code2), false );

	// Test 7
	code1 = { "if (2 * 2 == 5 &&",
			"true):",
			"  print 'Tricky test ;)'" };
	code2 = { "if (2 * 2 == 5",
			"&& true):",
			"  print 'Tricky test ;)'" };

	EvalTest (plagiarismCheck(code1, code2), true );
}