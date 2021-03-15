#include "Car.h"
#include <iostream>

Car::Car(string id, string name, string position) : DynamicObject(id, name, position) {}

Car::~Car()
{
	cout << "Delete a motorbike" << endl;
}

