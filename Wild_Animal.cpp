#include "Wild_Animal.h"

Wild_Animal::Wild_Animal(int power) : Base_Entity('W')
{
	this->power = power;
}

void Wild_Animal::Take_Food(Player &player)
{
	player.change_food(-power);
}

Wild_Animal* Wild_Animal::Copy()
{
	Wild_Animal *result = new Wild_Animal(this->power);
	return result;
}