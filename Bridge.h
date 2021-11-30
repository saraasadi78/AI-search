#ifndef BRIDGE_H
#define BRIDGE_H
#include "Base_Entity.h"

class Bridge : public Base_Entity
{
public:
	bool traversed;
	Bridge();
	Bridge *Copy();
};

#endif // !BRIDGE_H
