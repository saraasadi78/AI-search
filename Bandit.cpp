#include "Bandit.h"

Bandit::Bandit(int power) : Base_Entity('B')
{
	this->power = power;
}

void Bandit::Take_Money(Player &player)
{
	player.change_money(-power);
}

Bandit* Bandit::Copy()
{
	Bandit *result = new Bandit(this->power);
	return result;
}