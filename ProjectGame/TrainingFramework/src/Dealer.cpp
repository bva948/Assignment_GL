#include "Dealer.h"

Dealer::Dealer(): Player()
{
	setPlayerName("Dealer");
	end = false;
}

Dealer::~Dealer()
{

}

GLboolean Dealer::isEnd()
{
	return end;
}

void Dealer::setEnd(GLboolean end)
{
	this->end = end;
}
void Dealer::play()
{
	while (!end)
	{
		if (this->getScore() < 15)
		{
			this->setHit(true);
		}
	}
}