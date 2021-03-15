#ifndef BaseObject_H
#define BaseObject_H

#include <string>

using namespace std; 

class BaseObject {
protected:
	string id;
	string name;
	string position;
public:
//	BaseObject();
	BaseObject(string id, string name, string position);
	virtual ~BaseObject();
	void getName();
	void getid();
	virtual void move();
	void printPosition();
};

#endif