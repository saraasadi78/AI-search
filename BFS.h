#ifndef BFS_H
#define BFS_H
#include<string>
#include<fstream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<vector>
#include "Node.h"

using namespace std;

class BFS
{
public:
	void Search(Node initial_node);
	bool is_goal(Node node);
	void Result(Node *node, vector<Node> &nodes_vector);
};

#endif