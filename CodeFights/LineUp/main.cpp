/*
To prepare his students for an upcoming game, the sports coach decides to try some new training drills. 
To begin with, he lines them up and starts with the following warm-up exercise: when the coach says 'L', 
he instructs the students to turn to the left. Alternatively, when he says 'R', they should turn to the right. 
Finally, when the coach says 'A', the students should turn around.

Unfortunately some students (not all of them, but at least one) can't tell left from right, meaning they always turn right
when they hear 'L' and left when they hear 'R'. The coach wants to know how many times the students end up facing the same direction.

Given the list of commands the coach has given, count the number of such commands after which the students will 
be facing the same direction.

Example

For commands = "LLARL", the output should be
lineUp(commands) = 3.

Let's say that there are 4 students, and the second one can't tell left from right. 
In this case, only after the second, third and fifth commands will the students face the same direction.
*/

#include "../eval_t.h"
#include <string>

typedef std::string str;

enum _commands { L = 3, A = 2, R = 1 };

struct student
{
	int facing = 0;		// 0 front, 90 right, 180 back, 270 left
	bool well_oriented = true;
	inline void update_orientation(_commands command)
	{
		if (command == L || command == R)
			facing += well_oriented ? command : command + 2;
		else
			facing += command;
		facing %= 4;
	}
};

int lineUp(str commands) {
	student a, b;
	int cmds_cnt = 0;
	b.well_oriented = false;

	for(char ch : commands)
	{
		_commands command;
		switch (ch)
		{
		case 'L':		// turn left
			command = L;
			break;
		case 'A':		// turn around
			command = A;
			break;
		case 'R' :		// turn right
			command = R;
			break;
		default:
			break;
		}
		a.update_orientation(command);
		b.update_orientation(command);

		if (a.facing == b.facing) cmds_cnt++;
	}
	
	return cmds_cnt;
}

void main()
{
	std::string input;
	
	input = "LLARL";
	eval_test::EvalTest("Test 1", lineUp(input), 3);

	input = "L";
	eval_test::EvalTest("Test 4", lineUp(input), 0);

	input = "A";
	eval_test::EvalTest("Test 5", lineUp(input), 1);

	getchar();
}