#include "Player.h"

Player::Player()
{
	playerName = "Player";
	money = 50;
	win = false;
	score = 0;
	myTurn = false;
}

Player::~Player()
{

}
void Player::calScore(std::vector<Card> hand)
{
	GLint score = 0;
	for (auto it : hand)
	{
		score += it.getValue();
	}
	this->score = score;
}
GLint Player::getScore()
{
	return score;
}

char* Player::getPlayerName()
{
	return playerName;
}
void Player::setPlayerName(char* playerName)
{
	this->playerName = playerName;
}
void Player::setMoney(int money)
{
	this->money = money;
}
GLint Player::getMoney()
{
	return money;
}

GLboolean Player::isHit()
{
	return hit;
}

void Player::setHit(GLboolean hit)
{
	this->hit = hit;
}

void Player::hitCard(Card card)
{
	hand.push_back(card);
}

GLboolean Player::isMyTurn()
{	
	return myTurn;
}

void Player::setMyTurn(GLboolean myTurn)
{
	this->myTurn = myTurn;
}

GLint Player::getNumCard()
{
	return numCard;
}

void Player::setNumCard(GLint numCard)
{
	this->numCard = numCard;
}