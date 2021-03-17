
#include <iostream>
using namespace std;

class State;
class Door
{
	State* current;
public:
	Door();
	void setCurrent(State* s)
	{
	current = s;
    };
	void toUnlock();
	void toOpen();
	void toClose();
	void toLock();
};
class State
{
public:
	virtual void toUnlock(Door* d)
	{
		cout << "already unlocked" << endl;
	};
	virtual void toOpen(Door* d)
	{
		cout << "already opened" << endl;
	}
	virtual void toClose(Door* d)
	{
		cout << "already closed" << endl;
	}
	virtual void toLock(Door* d)
	{
		cout << "already locked" << endl;
	}
};

//void Door::setCurrent(State* s)
//{
//	current = s;
//}

void Door::toUnlock()
{
	current->toUnlock(this);
}

void Door::toOpen()
{
	current->toOpen(this);
}

void Door::toClose()
{
	current->toClose(this);
}

void Door::toLock()
{
	current->toLock(this);
}

class Opened: public State
{
public:
	Opened()
	{
	cout << "The door is opened" << endl;
};
//	~Opened(){};
	void toClose(Door *d);
	void toUnlock(Door *d)
	{
        cout << "The door is not locked" << endl;
	}
	void toLock(Door *d)
	{
	    cout << "The door is not closed" << endl;
	}
};

class Closed : public State
{
public:
	Closed()
	{
	cout << "The door is closed (unlocked)" << endl;
};
//	~Closed();
	void toLock(Door* d);
	void toOpen(Door* d)
	{
	cout << "Closed ---> Opened" << endl;
	d->setCurrent(new Opened());
	delete this;
};
};

void Opened::toClose(Door* d)
{
	cout << "Opened ---> Closed" << endl;
	d->setCurrent(new Closed());
	delete this;
}

class Locked: public State
{
public:
	Locked()
	{
	cout << "The door is locked" << endl;
};
//	~Locked();
	void toUnlock(Door* d)
	{
	cout << "Locked ---> Unlocked (Closed)" << endl;
	d->setCurrent(new Closed());
	delete this;
};
    void toOpen(Door *d)
    {
        cout << "The door is not closed" << endl;
    }
    void toClose(Door *d)
    {
        cout << "The door is not opened" << endl;
    }
};

void Closed::toLock(Door* d)
{
	cout << "Unlocked ---> Locked" << endl;
	d->setCurrent(new Locked());
	delete this;
}

Door::Door()
{
	current = new Locked();
}

int main()
{
	Door* door = new Door();
//    void(Door:: *ptrs[])() =
//    {
//        Door::toOpen, Door::toClose, Door::toUnlock, Door::toLock
//    };
    int num = -1;
    while (num < 4)
    {
        cout << "Enter 0 - 3 (0: open, 1: close, 2: unlock, 3: lock): ";
        cin >> num;
//        (door -> *ptrs[num])();
        switch(num)
        {
            case 0: door -> toOpen(); break;
            case 1: door -> toClose(); break;
            case 2: door -> toUnlock(); break;
            case 3: door -> toLock();
        }
    }
	return 0;
}
