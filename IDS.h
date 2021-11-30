#pragma once
#include<string>
#include<fstream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<vector>
#include "Node.h"

class IDS
{
public:
	void Search(Node initial_node );
	bool is_goal(Node node);
	void Result(Node* node, vector<Node>& nodes_vector);
	void Depth_Limited_Search(Node initial_nod);
};

