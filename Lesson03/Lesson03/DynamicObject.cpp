#include "DynamicObject.h"
#include <iostream>

//DynamicObject::DynamicObject() : BaseObject() {}

DynamicObject::DynamicObject(string id, string name, string position) : BaseObject(id, name, position) {}

DynamicObject::~DynamicObject()
{
	cout << "Delete a dynamic object" << endl;
}

void DynamicObject::move()
{
	cout << "Can move" << endl;
}