#pragma once
#include "StaticObject.h"

class House : public StaticObject
{
public:
	//House();
	House(string id, string name, string position);
	~House();
};

