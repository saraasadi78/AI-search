#include "Base_Entity.h"

Base_Entity::Base_Entity() {}

Base_Entity::Base_Entity(char name)
{
	this->name = name;
}

Base_Entity* Base_Entity::Copy()
{
	Base_Entity *result = new Base_Entity(this->name);
	return result;
}