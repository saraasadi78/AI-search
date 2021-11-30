#include "Bridge.h"

Bridge::Bridge() : Base_Entity('P')
{
	traversed = false;
}

Bridge* Bridge::Copy()
{
	Bridge *result = new Bridge();
	result->traversed = this->traversed;
	return result;
}