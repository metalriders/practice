#include <string>
#include <vector>
#include <iostream>

bool diff_one_char(std::string lhs, std::string rhs)
{
	int diff_chars = -1;

	for (int i = 0; i < lhs.size() && diff_chars < 1; i++)
	{
		if (lhs[i] != rhs[i])
			diff_chars++;
	}
	return !diff_chars;
}

bool stringsRearrangement(std::vector<std::string> inputArray) {
	std::vector<std::string> output;
	bool insert_made;

	while (!inputArray.empty())
	{
		if (output.empty())
		{
			output.push_back(inputArray[0]);
			inputArray.erase(std::begin(inputArray));
			continue;
		}

		for (std::vector<std::string>::iterator it_in = inputArray.begin(); it_in != inputArray.end(); )
		{
			insert_made = false;
			for (auto it_out = output.rbegin(); it_out != output.rend(); it_out++)
			{

				if (diff_one_char(*it_in, *it_out))
				{
					// if fits at end
					if (it_out == output.rbegin())
					{
						output.push_back(*it_in);
						insert_made = true;
					}

					// if fits at the begining
					else if (it_out == output.rend())
					{
						output.insert(output.begin(), *it_in);
						insert_made = true;
					}

					// if fits before
					else if (diff_one_char(*it_in, *(it_out - 1)))
					{
						output.insert(it_out.base() - 2, *it_in);
						insert_made = true;
					}
					// if fits after
					else if (diff_one_char(*it_in, *(it_out + 1)))
					{
						output.insert(it_out.base() + 2, *it_in);
						insert_made = true;
					}
					else
						continue;

					it_in = inputArray.erase(it_in);
					break;
				}
			}
			if (!insert_made)
				it_in++;
		}
		if (!insert_made)
			return false;
	}

	return true;
}


int main()
{
	std::vector<std::string> in{ "abc","xbc","xxc","xbc","aby","ayy","aby" };

	std::cout << stringsRearrangement(in);

	return 0;
}