/* Given two strings, find the number of common characters between them. */

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

typedef std::string string;

int commonCharacterCount(string s1, string s2) {
	int common_chars = 0;

	for (int i = 0; i < s1.size() && !s2.empty(); i++)
	{
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				s2.erase(j, 1);
				common_chars++;
				break;
			}
		}			
	}

	return common_chars;
}

[[noreturn]] void main()
{
	string str1, str2;

	str1 = "aabcc";
	str2 = "adcaa";
	std::cout << commonCharacterCount(str1,str2) << "\n";	/* Expected 3 */

	str1 = "zzzz";
	str2 = "zzzzzzz";
	std::cout << commonCharacterCount(str1, str2) << "\n";	/* Expected 4 */

}

