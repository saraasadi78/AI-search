#ifndef BANDIT_H
#define BANDIT_H
#include "Base_Entity.h"
#include "Player.h"

class Bandit : public Base_Entity
{
public:
	int power;

	Bandit(int power);
	void Take_Money(Player &player);
	Bandit *Copy();
};

#endif
