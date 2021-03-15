#ifndef DynamicObject_H
#define DynamicObject_H

#include "BaseObject.h"

class DynamicObject : public BaseObject
{
public:
	//DynamicObject();
	DynamicObject(string id, string name, string position);
	~DynamicObject();
	void move();
};

#endif