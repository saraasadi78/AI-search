#include "Loot.h"

Loot::Loot(int money, int food) : Base_Entity('L')
{
	this->money = money;
	this->food = food;
	this->used = false;
}

void Loot::Use_Money(Player &player)
{
	player.change_money(money);
	used = true;
}

void Loot::Use_Food(Player &player)
{
	player.change_food(food);
	used = true;
}

Loot* Loot::Copy()
{
	Loot *result = new Loot(this->money, this->food);
	result->used = this->used;
	return result;
}