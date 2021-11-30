#include "DFS.h"

bool DFS::is_goal(Node node)
{
	if (node.map.at(node.player.i, node.player.j)->name == 'C')
		return true;

	return false;
}

void DFS::Result(Node* node, vector<Node>& nodes_vector)
{
	cout << "Found A Solution! Check out the Resultdfs.txt file." << endl;
	stack<Node*> nodes_stack;
	ofstream myfile;
	myfile.open("Resultdfs.txt");
	while (node->parent_index != -1)
	{
		nodes_stack.push(node);
		node = &nodes_vector[node->parent_index];
	}
	while (!nodes_stack.empty())
	{
		myfile << nodes_stack.top()->action << ", ";
		nodes_stack.pop();
	}
	myfile.close();
}

void DFS::Search(Node initial_node)
{
	vector<Node> nodes(100000);
	stack<int> frontier;
	int index = 0;
	unordered_map<string, bool> in_frontier;
	unordered_map<string, bool> explored;

	if (is_goal(initial_node))
	{
		Result(&initial_node, nodes);
		return;
	}

	nodes[index] = initial_node;
	frontier.push(index);
	in_frontier[initial_node.Hash()] = true;

	while (!frontier.empty())
	{
		int current_index = frontier.top();
		Node temp = nodes[current_index];
		frontier.pop();
		in_frontier[temp.Hash()] = false;
		explored[temp.Hash()] = true;

		vector<Node> children = temp.Successor(current_index);
		while (!children.empty())
		{
			Node child = children.back();
			children.pop_back();
			if (in_frontier[child.Hash()] == false && explored[child.Hash()] == false)
			{
				if (is_goal(child))
				{
					Result(&child, nodes);
					return;
				}
				index++;
				nodes[index] = child;
				frontier.push(index);
				in_frontier[child.Hash()] = true;
			}
		}
	}
	cout << "No Solution Found!" << endl;
}