#include "AStar.h"
#include <queue>

using namespace std;
int AStar::manhattan_distance(Node a,Node b) {
    int sum = 0;
    sum=(abs(a.map.rows - b.map.rows)) + (a.map.cols - b.map.cols);
    return sum;
}

int AStar::heuristic(Node current_node){

	Node key;
	Node goal;
	key.map.rows = 6;
	key.map.cols = 1;
	goal.map.rows = 4;
	goal.map.cols = 4;
    int h1 = manhattan_distance(key, current_node);
    int h2 = manhattan_distance(goal, current_node);
    int h = h1 + h2;
    return h;
}

bool AStar::is_goal(Node node)
{
    if (node.map.at(node.player.i, node.player.j)->name == 'C')
        return true;

    return false;
}
void AStar::Result(Node* node, vector<Node>& nodes_vector)
{
    cout << "Found A Solution! Check out the ResultA*.txt file." << endl;
    stack<Node*> nodes_stack;
    ofstream myfile;
    myfile.open("ResultA*.txt");
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

 

void AStar::Search(Node initial_node) {
   
	vector<Node> nodes(100000);
	priority_queue<int> frontier;
	queue <int> deppth;
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
	deppth.push(0);
	in_frontier[initial_node.Hash()] = true;

	while (!frontier.empty())
	{
		
		int current_index = frontier.top();
		Node temp = nodes[current_index];
		frontier.pop();
		int d = deppth.front();
		deppth.pop();
		in_frontier[temp.Hash()] = false;
		explored[temp.Hash()] = true;

		vector<Node> children = temp.Successor(current_index);
		 
		int f = deppth.back() + heuristic(nodes.back());
		frontier.push(f);

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
				deppth.push(d + 1);
				in_frontier[child.Hash()] = true;
			}
		}
	}
	cout << "No Solution Found!" << endl;

	}
     
    
