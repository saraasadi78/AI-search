#pragma once
#include<string>
#include<fstream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<vector>
#include "Node.h"
using namespace std;
class DFS
{
public:
	void Search(Node initial_node);
	bool is_goal(Node node);
	void Result(Node* node, vector<Node>& nodes_vector);
};

