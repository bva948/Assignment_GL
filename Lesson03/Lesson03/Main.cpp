#include "Main.h"
#include "Car.h"
#include "House.h"
#include "Tree.h"
#include "Motorbike.h"
#include <list>

int main() {
	list <BaseObject> listObj;
	BaseObject* car1 = new Car("01", "car1", "park");
	listObj.push_back(*car1);
	BaseObject* tree1 = new Tree("03", "tree1", "garden");
	listObj.push_back(*tree1);
	BaseObject* motor1 = new Motorbike("04", "motor1", "gara");
	listObj.push_back(*motor1);
	BaseObject* house1 = new House("02", "house1", "ground");
	listObj.push_back(*house1);
	for (auto obj : listObj) {
		obj.getName();
	}
	for (auto obj : listObj) {
		obj.move();
	}
	for (auto obj : listObj) {
		obj.printPosition();
	}
	listObj.clear();
	return 0;
}
