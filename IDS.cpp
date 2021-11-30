#include "IDS.h"
bool IDS::is_goal(Node node)
{
	if (node.map.at(node.player.i, node.player.j)->name == 'C')
		return true;

	return false;
}

void IDS::Result(Node* node, vector<Node>& nodes_vector)
{
	cout << "Found A Solution! Check out the Resultids.txt file." << endl;
	stack<Node*> nodes_stack;
	ofstream myfile;
	myfile.open("Resultids.txt");
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

