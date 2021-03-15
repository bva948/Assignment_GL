#include "StaticObject.h"
#include <iostream>

StaticObject::StaticObject(string id, string name, string position) : BaseObject(id, name, position) {}

StaticObject::~StaticObject()
{
	cout << "Delete a static object" << endl;
}
void StaticObject::move()
{
	getid();
	cout << "Cannot move" << endl;
}