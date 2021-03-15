#include "House.h"
#include <iostream>

//House::House(): StaticObject() {}

House::House(string id, string name, string position) : StaticObject(id, name, position) {}

House::~House()
{
	cout << "Delete a house" << endl;
}

