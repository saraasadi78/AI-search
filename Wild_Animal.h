#ifndef WILD_ANIMAL_H
#define WILD_ANIMAL_H
#include "Base_Entity.h"
#include "Player.h"

class Wild_Animal : public Base_Entity
{
public:
	int power;

	Wild_Animal(int power);
	void Take_Food(Player &player);
	Wild_Animal *Copy();
};

#endif // !WILD_ANIMAL_H
