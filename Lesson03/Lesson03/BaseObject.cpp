#include <iostream>
#include "BaseObject.h"

BaseObject::BaseObject(string id, string name, string position)
{
	this->id = id;
	this->name = name;
	this->position = position;
}

BaseObject::~BaseObject()
{
	cout << "Delete a base object" << endl;
}

void BaseObject::getName() 
{
	cout << name << endl;
}

void BaseObject::getid()
{
	cout << id << endl;
}

void BaseObject::printPosition()
{
	cout << position << endl;
}

void BaseObject::move() {

}