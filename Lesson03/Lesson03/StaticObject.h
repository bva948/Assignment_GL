#ifndef StaticObject_H
#define StaticObject_H

#include "BaseObject.h"

class StaticObject : public BaseObject {
public:
//	StaticObject();
	StaticObject(string id, string name, string position);
	void move();
	~StaticObject();
};

#endif