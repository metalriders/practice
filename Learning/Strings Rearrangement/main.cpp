#include <string>
#include <vector>
#include <iostream>

typedef std::vector<std::string> Vector_str;

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

bool stringsRearrangement(Vector_str inputArray) {
	bool insert_made;
	Vector_str output;

	while (!inputArray.empty())
	{
		if (output.empty())
		{
			output.push_back(inputArray[0]);
			inputArray.erase(std::begin(inputArray));
			continue;
		}

		for (Vector_str::iterator it_in = inputArray.begin(); it_in != inputArray.end(); )
		{
			insert_made = false;
			for (auto it_out = output.begin(); it_out != output.end(); it_out++)
			{

				if (diff_one_char(*it_in, *it_out))
				{
					// if fits at begining
					if (it_out == output.begin())
					{
						it_out = output.insert(output.begin(), *it_in);
						insert_made = true;
					}

					// if fits at the end
					else if (it_out + 1 == output.end())
					{
						it_out = output.insert(output.end(), *it_in);
						insert_made = true;
					}

					// if fits before
					else if (diff_one_char(*it_in, *(it_out - 1)))
					{
						it_out = output.insert(it_out - 1, *it_in);
						insert_made = true;
					}
					// if fits after
					else if (diff_one_char(*it_in, *(it_out + 1)))
					{
						it_out = output.insert(it_out + 1, *it_in);
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
	Vector_str in{ "abc","xbc","xxc","xbc","aby","ayy","aby" };

	std::cout << stringsRearrangement(in);

	return 0;
}