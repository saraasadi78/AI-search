#include<iostream>
#include<vector>
#include "Bandit.h"
#include "Wild_Animal.h"
#include "Loot.h"
#include "Player.h"
#include "Map.h"
#include "Node.h"
#include "Bridge.h"
#include "BFS.h"
#include "DFS.h"
#include "AStar.h"
using namespace std;

int main()
{
	Map m(7, 6);
	m.Add(0, 0, new Bandit(50));
	m.Add(0, 1, new Base_Entity('G'));
	m.Add(0, 2, new Base_Entity('S'));
	m.Add(0, 3, new Bandit(150));
	m.Add(0, 4, new Base_Entity('G'));
	m.Add(0, 5, new Base_Entity('G'));

	m.Add(1, 0, new Base_Entity('S'));
	m.Add(1, 1, new Bridge());
	m.Add(1, 2, new Base_Entity('G'));
	m.Add(1, 3, new Base_Entity('S'));
	m.Add(1, 4, new Bridge());
	m.Add(1, 5, new Bandit(25));

	m.Add(2, 0, new Loot(50, 50));
	m.Add(2, 1, new Base_Entity('G'));
	m.Add(2, 2, new Wild_Animal(150));
	m.Add(2, 3, new Base_Entity('G'));
	m.Add(2, 4, new Base_Entity('G'));
	m.Add(2, 5, new Base_Entity('G'));

	m.Add(3, 0, new Base_Entity('G'));
	m.Add(3, 1, new Wild_Animal(50));
	m.Add(3, 2, new Bandit(100));
	m.Add(3, 3, new Base_Entity('G'));
	m.Add(3, 4, new Bandit(150));
	m.Add(3, 5, new Base_Entity('S'));

	m.Add(4, 0, new Base_Entity('G'));
	m.Add(4, 1, new Bandit(50));
	m.Add(4, 2, new Base_Entity('G'));
	m.Add(4, 3, new Bandit(99));
	m.Add(4, 4, new Base_Entity('C'));
	m.Add(4, 5, new Wild_Animal(200));

	m.Add(5, 0, new Base_Entity('S'));
	m.Add(5, 1, new Base_Entity('G'));
	m.Add(5, 2, new Loot(100, 100));
	m.Add(5, 3, new Base_Entity('G'));
	m.Add(5, 4, new Base_Entity('S'));
	m.Add(5, 5, new Base_Entity('G'));

	m.Add(6, 0, new Bandit(100));
	m.Add(6, 1, new Base_Entity('K'));
	m.Add(6, 2, new Base_Entity('S'));
	m.Add(6, 3, new Base_Entity('G'));
	m.Add(6, 4, new Base_Entity('S'));
	m.Add(6, 5, new Base_Entity('S'));

	Player p(2, 5, 100, 100);

	m.Print();
 
	Node n(m, p, -1, "");
	BFS bfs;
	bfs.Search(n);

	DFS dfs;
	dfs.Search(n);

	AStar astar;
	astar.Search(n);

}