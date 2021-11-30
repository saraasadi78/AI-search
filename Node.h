#ifndef NODE_H
#define NODE_H
#include<string>
#include<vector>
#include "Map.h"
#include "Player.h"


using namespace std;

class Node
{
public:
	Map map;
	Player player;
	int parent_index;
	string action;
	 

	Node();
	Node(Map map, Player player, int parent_index, string action);
	vector<Node> Successor(int index);
	string Hash();
};

#endif NODE_H
