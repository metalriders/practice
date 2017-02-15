#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> taskMaker(std::vector<std::string> source, int challengeId)
{
	std::string db_tag = "\\\\DB ";
	std::string str_id = std::to_string(challengeId);
	std::string db_to_lookup = db_tag + str_id;

	std::vector<std::string> output;
	for (int i = 0; i< source.size(); i++)
	{
		if (source[i].find(db_to_lookup, 0) != -1)
		{
			int idx = (int)source[i].find(db_to_lookup);
			int end_idx = 7 + (int)str_id.size();

			output.pop_back();
			source[i].erase(idx, end_idx);
		}
		if (source[i].find(db_tag, 0) != -1) continue;
		output.push_back(source[i]);
	}
	return output;
}

void main()
{
	std::vector<std::string> in {	"ans = 0",
									"for i in range(n):",
									"    for j in range(n):",
									"    //DB 3//for j in range(1, n):",
									"    //DB 2//for j in range(n + 1):",
									"        ans += 1",
									"return ans" };

	taskMaker(in, 3);
}