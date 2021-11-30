#pragma once
#pragma once
#include<string>
#include<fstream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<vector>
#include "Node.h"
using namespace std;
class AStar
{
public:
	int heuristic(Node current_node);
	int manhattan_distance(Node a, Node b);
	void Result(Node* node, vector<Node>& nodes_vector);
	void Search(Node initial_node);
	bool is_goal(Node node);
 
};

