#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

class Base_Entity
{
public:
	char name;

	Base_Entity();
	Base_Entity(char name);
	virtual Base_Entity *Copy();
};

#endif

