#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define _STD ::std::
#define _STR _STD string 

typedef _STR _str;
typedef _STD vector<_str> v_str;
typedef _STD map<char, char> m_ch_ch;
typedef _STD map<_str, _str> m_str_str;

const char spc = ' ';
const char b_line = '\\';
const _str sp_chr = " ,:;[](){}\"'*-+=";

const v_str kwords
{ 
	{ "if"},{ "for"},{"function" },
	{ "return" },{ "print" } 
};

bool plagiarismCheck(v_str code1, v_str code2)
{
	std::string cod1, cod2;
	bool word_rec = false;
	for (auto line : code1) cod1 += line + b_line;
	for (auto line : code2) cod2 += line + b_line;
	
	// Special case :P (not likely to happen)
	//if (cod1.compare(cod2)) return true;
	
	//remove all spaces 

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
			p_code = c_word;
			c_word.clear();
			word_rec = false;
		}
		else if(!c_word.empty())
		{
			size_t idx = cod2.find(p_code, 0) + p_code.size();		//get idx for begin of word to find

			if (c_word.compare(cod2.substr(idx, c_word.size()))) continue;

			std::string check_word = "" ;
			// find
			while (sp_chr.find_first_of(cod2[idx]) == _STR::npos)
			{
				check_word += cod2[idx];
				idx++;
			}

			// replace
			while (idx < cod2.size()) 
			{
				//cod2.replace()
				idx++;
			}
		}

		//if we are not tracking a word just get a trail of previous code
		p_code += cod1[i];
	}

	return false;
}

void main()
{
	std::vector<std::string> code1, code2;

	std::string base = "this is a test string.";
	std::string str2 = "sample phrase";
	std::string str3 = "sample phrase";
	std::string str4 = "useful.";

	// replace signatures used in the same order as described above:

	// Using positions:                     0123456789*123456789*12345
	std::string str = base;				// "this is a test string."
	str.replace(8, str2.size(), str2, 0, str2.size());			// "this is an example string." (1)
	str.replace(19, str3.size(), str3, 6, 6);     // "this is an example phrase." (2)
	str.replace(8, 10, "just a");		// "this is just a phrase."     (3)
	str.replace(8, 6, "a shorty", 7);	// "this is a short phrase."    (4)
	str.replace(22, 1, 3, '!');			// "this is a short phrase!!!"  (5)

	code1 = { "if (2 * 2 == 5 &&",
			"true):",
			"  print 'Tricky test ;)'" };
	code2 = { "if (2 * 2 == 5",
			"&& true):",
			"  print 'Tricky test ;)'" };

	plagiarismCheck(code1, code2);

}