/*
Sudoku is a number - placement puzzle.
The objective is to fill a 9 × 9 grid with numbers in such a way that each column, each row, 
and each of the nine 3 × 3 sub - grids that compose the grid all contain all of the numbers from 1 to 9 one time.

Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout rules described above.Note that the puzzle represented by grid does not have to be solvable.

Example

For

grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
['.', '.', '6', '.', '.', '.', '.', '.', '.'],
['.', '.', '.', '.', '.', '.', '.', '.', '.'],
['.', '.', '1', '.', '.', '.', '.', '.', '.'],
['.', '6', '7', '.', '.', '.', '.', '.', '9'],
['.', '.', '.', '.', '.', '.', '8', '1', '.'],
['.', '3', '.', '.', '.', '.', '.', '.', '6'],
['.', '.', '.', '.', '.', '7', '.', '.', '.'],
['.', '.', '.', '5', '.', '.', '.', '7', '.']]
the output should be
sudoku2(grid) = true;

For

grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
['.', '.', '.', '.', '6', '.', '.', '.', '.'],
['7', '1', '.', '.', '7', '5', '.', '.', '.'],
['.', '7', '.', '.', '.', '.', '.', '.', '.'],
['.', '.', '.', '.', '8', '3', '.', '.', '.'],
['.', '.', '8', '.', '.', '7', '.', '6', '.'],
['.', '.', '.', '.', '.', '2', '.', '.', '.'],
['.', '1', '.', '2', '.', '.', '.', '.', '.'],
['.', '2', '.', '.', '3', '.', '.', '.', '.']]
the output should be
sudoku2(grid) = false.

The given grid is not correct because there are two 1s in the second column.Each column, each row, and each 3 × 3 subgrid can only contain the numbers 1 through 9 one time.

Input / Output

[time limit] 500ms(cpp)
[input] array.array.char grid

A 9 × 9 array of characters, in which each character is either a digit from '1' to '9' or a period '.'.

[output] boolean

Return true if grid represents a valid Sudoku puzzle, otherwise return false.*/

#include "../eval_t.h"
#include <iostream>
#include <vector>
#include <map>

typedef std::map<int, int> m_int_int;
typedef std::vector<char> v_char;
typedef std::vector<v_char> v_v_char;

bool checkDuplicated(m_int_int &map, int val) {
	return ++map[val] == 2;
}

bool sudoku2(std::vector<std::vector<char>> grid) {
	int i, j, curr;

	m_int_int nums;

	for (i = 0; i<grid.size(); i++) {

		// check column
		for (j = 0; j< grid.size(); j++) {
			if (grid[i][j] == '.') continue;

			curr = grid[i][j];
			if (checkDuplicated(nums, curr)) return false;
		}
		nums.clear();

		// check row
		for (j = 0; j< grid.size(); j++) {
			if (grid[j][i] == '.') continue;

			curr = grid[j][i];
			if (checkDuplicated(nums, curr)) return false;
		}
		nums.clear();

		//check sub-grid        
		int row = (i / 3) * 3;
		int col = (i % 3) * 3;

		for (int r = row; r <= row + 2; r++) {
			for (int c = col; c <= col + 2; c++) {
				if (grid[r][c] == '.') continue;

				curr = grid[r][c];
				if (checkDuplicated(nums, curr)) return false;
			}
		}
		nums.clear();
	}
	return true;
}


[[noreturn]] void main()
{
	v_v_char input;

	// Test 1
	input = {{ '.','.','.','1','4','.','.','2','.' },
		 	 { '.','.','6','.','.','.','.','.','.' },
			 { '.','.','.','.','.','.','.','.','.' },
			 { '.','.','1','.','.','.','.','.','.' },
			 { '.','6','7','.','.','.','.','.','9' },
			 { '.','.','.','.','.','.','8','1','.' },
			 { '.','3','.','.','.','.','.','.','6' },
			 { '.','.','.','.','.','7','.','.','.' },
			 { '.','.','.','5','.','.','.','7','.' } };
	eval_test::EvalTest("Test 1", sudoku2(input), true);

	// Test 2
	input = {{ '.','.','.','.','2','.','.','9','.' },
			 { '.','.','.','.','6','.','.','.','.' },
			 { '7','1','.','.','7','5','.','.','.' },
			 { '.','7','.','.','.','.','.','.','.' },
			 { '.','.','.','.','8','3','.','.','.' },
			 { '.','.','8','.','.','7','.','6','.' },
			 { '.','.','.','.','.','2','.','.','.' },
			 { '.','1','.','2','.','.','.','.','.' },
			 { '.','2','.','.','3','.','.','.','.' } };
	eval_test::EvalTest("Test 2", sudoku2(input), false);

	puts("Press a key to finish");
	getchar();
}