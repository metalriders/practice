#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

struct Cell
{
	int direction;
	int* data_ptr;
	std::pair<int,int> coords;
	bool visited[4];
	bool operator==(Cell &rhs) { return this->data_ptr == rhs.data_ptr; }
};

enum DirectionType
{
	up = 0, down = 1, left = 2, right = 3, undef = -1
};

typedef std::vector<std::vector<int>> grid_t;
typedef std::vector<int*> vector_int_ptr;
typedef std::pair<int, int> pair_int_int;
typedef std::vector<Cell> vector_cell;

vector_cell getNeigbors(grid_t &grid, pair_int_int bounds, pair_int_int coords)
{
	vector_cell neigbors;
	int up, down, left, right;
	up = coords.first - 1;
	down = coords.first + 1;
	left = coords.second - 1;
	right = coords.second + 1;

	//	search biggest 2 neighbors and add them to the stack (that are not already in our visited nodes)
	if (up >= 0)
	{
		neigbors.push_back(Cell{ DirectionType::up, &grid[up][coords.second], pair_int_int(up, coords.second) });
	}
	if (down <= bounds.first - 1)
	{
		neigbors.push_back(Cell{ DirectionType::down, &grid[down][coords.second], pair_int_int(down, coords.second) });
	}
	if (left >= 0)
	{
		neigbors.push_back(Cell{ DirectionType::left, &grid[coords.first][left], pair_int_int(coords.first, left) });
	}
	if (right <= bounds.second - 1)
	{
		neigbors.push_back(Cell{ DirectionType::right, &grid[coords.first][right], pair_int_int(coords.first, right) });
	}

	std::sort(neigbors.begin(), neigbors.end(), [](Cell a, Cell b) { return *a.data_ptr > *b.data_ptr; });
	return neigbors;
}

int reverseCoord(int direction)
{
	switch (direction)
	{
	case up:
		return down;
		break;
	case down:
		return up;
		break;
	case left:
		return right;
		break;
	case right:
		return left;
		break;
	default:
		break;
	}

}
void updateCoords(int direction, pair_int_int &coords)
{
	switch (direction)
	{
	case up:
		coords.first--;
		break;
	case down:
		coords.first++;
		break;
	case left:
		coords.second--;
		break;
	case right:
		coords.second++;
		break;
	default:
		break;
	}
}

int updatePerimeter(grid_t &grid, vector_cell &path, pair_int_int bounds, pair_int_int coords)
{
	vector_cell curr_neigbors = getNeigbors(grid, bounds, coords);
	int match_neigbors = 0;
	int perimeter = 0;
	for (auto neigbor : curr_neigbors)
	{
		for (auto i : path)
		{
			if (neigbor == i)
				match_neigbors++;
		}
	}

	// if exist two nodes do nothing
	// if exist one node then sum 2 only
	if (match_neigbors == 1) perimeter = 2;

	// if exists three nodes substract 2
	else if (match_neigbors == 3) perimeter = -2;

	// if exist four nodes substract 4
	else  if (match_neigbors == 4) perimeter = -4;

	return perimeter;
}

int sumInPerimeter(grid_t grid, int p) {
	pair_int_int coords;
	pair_int_int bounds(0, 0);
	int max = INT_MIN;
	vector_cell grid_line;
	
	// reduce number of start points by picking values >= 0
	for (auto row = grid.begin(); row != grid.end(); row++, bounds.first++)
	{
		bounds.second = 0;
		for (auto col = (*row).begin(); col != (*row).end(); col++, bounds.second++)
		{
			if(grid[bounds.first][bounds.second] >= 0)
				grid_line.push_back(Cell{ DirectionType::undef, &grid[bounds.first][bounds.second], bounds });
			if (*col > max)
			{
				max = *col;
				coords = pair_int_int(bounds.first, bounds.second);
			}
		}
	}

	int sum = 0;
	int max_sum = 0;
	int perimeter = 0;
	bool no_moves = false;

	printf("Matrix of %d x %d\n", bounds.first, bounds.second);
	printf("Index of max value > %d, %d\n", coords.first, coords.second);
	
	// Search Paths 
	for (auto item : grid_line)
	{
		vector_cell curr_neigbors;
		vector_cell to_process;
		vector_cell path;
		coords = item.coords;

		path.push_back(Cell{ DirectionType::undef, item.data_ptr });
		sum = *path[0].data_ptr;
		perimeter = 4;

		// Beam search of 3 nodes maybe?
		while (true)
		{
			if (path.empty()) break;
			to_process.clear();
			if (perimeter > p || no_moves)
			{
				// pop current node if not empty
				Cell to_pop = *path.rbegin();
				path.pop_back();

				perimeter -= updatePerimeter(grid, path, bounds, coords);
				sum -= *to_pop.data_ptr;

				updateCoords(reverseCoord(to_pop.direction), coords);

				continue;
			}
			else if (perimeter < p || path.size() < (p / 2)-1)
			{
				curr_neigbors = getNeigbors(grid, bounds, coords);

				for (auto neigbor : curr_neigbors) {
					to_process.push_back(neigbor);
				}
			}
			else
				break;

			//visit next in stack and add value to sum
			Cell *current_cell = &(*path.rbegin());
			no_moves = true;

			for (auto cell : to_process)
			{
				if (!current_cell->visited[cell.direction])
				{
					current_cell->visited[cell.direction] = true;
					cell.visited[reverseCoord(cell.direction)] = true;
					path.push_back(cell);
					
					updateCoords(cell.direction, coords);
					if (cell.data_ptr != (*path.begin()).data_ptr) {
						perimeter += updatePerimeter(grid, path, bounds, coords);
						sum += *cell.data_ptr;
					}

					no_moves = false;
					break;
				}
			}
		}
		if (sum > max_sum) max_sum = sum;
	}
	return max_sum;
}

int main(int argc[], char** arcgv)
{
	grid_t grid;
	int p;

	// Test case #1
	grid = { { 1,2,3 }, { 4,5,6 }, { 7,8,9 } };		// passed
	p = 6;
	std::cout << "Max sum is: " << sumInPerimeter(grid, p) << "\n\n";

	// Test case #5
	grid = { { 1,1,1,1,1,1 },{ 1,5,2,1,1,1 },{ 0,3,2,1,1,1 },{ 1,2,4,1,1,1 } };		// needs to be 12 :(
	p = 8;
	std::cout << "Max sum is: " << sumInPerimeter(grid, p) << "\n\n";

	// Test case #11
	grid = { { -1,-1,0,1 }, { 0,5,2,-1 }, { -1,0,1,1 } };		// passed
	p = 10;
	std::cout << "Max sum is: " << sumInPerimeter(grid, p) << "\n\n";

	// Test case #15
	grid = { { 1, -1, 1, -1 }, { 1,0,5,10 }, { 1,0,0,4 } };		// passed
	p = 10;
	std::cout << "Max sum is: " << sumInPerimeter(grid, p) << "\n\n";

	

	
	return 0;
}