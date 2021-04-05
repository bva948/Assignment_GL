#pragma once
#include "Player.h"

class Dealer : public Player
{
public:
	Dealer();
	~Dealer();
	GLboolean isEnd();
	void setEnd(GLboolean end);
	void play();
private:
	GLboolean end;
};