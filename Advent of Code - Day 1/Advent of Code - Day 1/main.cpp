#include <stdio.h>
#include <iostream>
#include <string.h>

int main()
{
	char *in = "";
	char *tok;
	char *nexttok;

	std::cin >> in;
	if (in == NULL) return 1;
	tok = strtok_s(in, ", ", &nexttok);

	while (tok != NULL)
	{
		std::cout << "Move> " << tok[0] << " steps> " << tok[1] << std::endl;
		tok = strtok_s(NULL, ", ", &nexttok);
	}
	return 0;
}