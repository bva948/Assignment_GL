#include "Motorbike.h"
#include <iostream>

Motorbike::Motorbike(string id, string name, string position): DynamicObject(id, name, position) {}

Motorbike::~Motorbike()
{
	cout << "Delete a motorbike" << endl;
}

