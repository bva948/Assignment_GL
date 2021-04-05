#pragma once
#include <GLES2/gl2.h>
#include "Card.h"

class Player
{
public:
	Player();
	~Player();

	void calScore(std::vector<Card> hand);
	GLint getScore();

	char* getPlayerName();
	void setPlayerName(char* playerName);

	void setMoney(int money);
	GLint getMoney();

	GLboolean isHit();
	void setHit(GLboolean hit);
	void hitCard(Card card);

	GLboolean isMyTurn();
	void setMyTurn(GLboolean myTurn);

	GLint getNumCard();
	void setNumCard(GLint numCard);
private:
	char* playerName;
	GLint money;
	GLboolean win;
	std::vector<Card> hand;
	GLint score;
	GLboolean myTurn;
	GLboolean hit;
	GLint numCard;
};