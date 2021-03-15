#include "Tree.h"
#include <iostream>

Tree::Tree(string id, string name, string position) : StaticObject(id, name, position) {}

Tree::~Tree()
{
	cout << "Delete a tree" << endl;
}