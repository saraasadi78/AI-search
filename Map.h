#ifndef MAP_H
#define MAP_H
#include<vector>
#include<iostream>
#include "Base_Entity.h"
#include "Player.h"

using namespace std;

class Map
{
public:
	int rows;
	int cols;
	vector<Base_Entity *> game;

	Map();
	Map(int rows, int cols);
	void Add(int i, int j, Base_Entity *entity);
	void Print();
	Map Copy();
	Base_Entity* at(int i, int j);
};

#endif // !MAP_H
