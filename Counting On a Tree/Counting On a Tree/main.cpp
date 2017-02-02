#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int id;
	int value;
	std::vector<int> edges;

	inline bool operator!=(const Node &rhs) { return id != rhs.id; }
	inline bool operator==(const Node &rhs) { return id == rhs.id; }
	inline bool operator==(const int &val) { return value == val; }
};

std::vector<Node> GetPath(int orig, int dest, const std::vector<Node>& graph)
{
	std::stack<Node> cool_nodes;
	std::vector<Node> visited;
	std::vector<Node> path;

	Node curr_node = graph[orig];
	cool_nodes.push(curr_node);
	visited.push_back(curr_node);

	while (curr_node != graph[dest])
	{

		for (int edge : curr_node.edges)
		{
			if (std::find(std::begin(visited), std::end(visited), graph[edge]) == std::end(visited))
				cool_nodes.push(graph[edge]);
		}

		if (cool_nodes.top() == curr_node) cool_nodes.pop();

		curr_node = cool_nodes.top();
		visited.push_back(curr_node);
	}

	while (!cool_nodes.empty())
	{
		Node node = cool_nodes.top();
		cool_nodes.pop();

		if (std::find(std::begin(visited), std::end(visited), node) != std::end(visited))
			path.push_back(node);
	}

	return path;
}

int main() {
	std::vector<Node> graph(1);
	std::vector<Node> i_path;
	std::vector<Node> j_path;

	int nodes_qty, queries_qty;
	int pairs_found;

	std::cin >> nodes_qty >> queries_qty;

	//graph.erase(std::begin(graph));
	// Initialize nodes
	for (int i = 1; i <= nodes_qty; i++)
	{
		int node_value;
		std::cin >> node_value;
		graph.push_back(Node{ i, node_value, std::vector<int>() });
	}

	// Initialize edges
	for (int i = 0; i<nodes_qty - 1; i++)
	{
		int orig, dest;
		std::cin >> orig >> dest;

		graph[orig].edges.push_back(dest);
		graph[dest].edges.push_back(orig);
	}

	// Process queries
	while (queries_qty--)
	{
		pairs_found = 0;
		int i_orig, i_dest, j_orig, j_dest;
		std::cin >> i_orig >> i_dest >> j_orig >> j_dest;

		i_path = GetPath(i_orig, i_dest, graph);
		j_path = GetPath(j_orig, j_dest, graph);

		// TODO: find match nodes in paths
		for (Node i : i_path)
		{
			auto tmp = std::find(std::begin(j_path), std::end(j_path), i.value);
			if ( tmp != std::end(j_path) && *tmp != i)
				pairs_found++;
		}

		std::cout << pairs_found <<"\n";
	}

	return 0;
}