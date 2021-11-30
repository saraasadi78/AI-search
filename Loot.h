#ifndef LOOT_H
#define LOOT_H
#include "Base_Entity.h"
#include "Player.h"

class Loot : public Base_Entity
{
public:
	int money, food;
	bool used;

	Loot(int money, int food);
	void Use_Money(Player &player);
	void Use_Food(Player &player);
	Loot *Copy();
};

#endif LOOT_H
