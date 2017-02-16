/* Google interview */

#include "../eval_t.h"
#include <iostream>
#include <vector>
#include <time.h>

typedef std::vector<int> v_int;

bool sumOfTwo(v_int a, v_int b, int v) 
{
	int comp;
	for (int i = 0; i< a.size(); i++)
	{
		comp = v - a[i];
		if (std::find(b.begin(), b.end(), comp) != b.end())
			return true;
	}
}

[[noreturn]] void main()
{
	v_int a(100000), b(100000);
	int v = 12231;
	clock_t c;
	
	for (int &i : a)
		i = rand() % 199999 + (-100000);

	for (int &i : b)
		i = rand() % 199999 + (-100000);
	c = clock();
	eval_test::EvalTest(sumOfTwo(a, b, v), false);
	std::cout << "Elapsed time: " << (clock() - c) / CLOCKS_PER_SEC;
	puts("Press a key to finish");
	getchar();
}