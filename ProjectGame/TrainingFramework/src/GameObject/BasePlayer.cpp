#include "BasePlayer.h"

BasePlayer::BasePlayer()
{
	money = 50;
	score = 0;
	hit = 0;
	reward = 0;
}

BasePlayer::~BasePlayer()
{

}
void BasePlayer::calScore()
{
	int score = 0;
	for (auto it : hand)
	{
		int v = it->getValue();
		if (v != 0 && v < 9)
			score += v + 1;
		if (v >= 9)
			score += 10;
	}
	int ace = this->numAce();
	if (ace != 0)
	{
		if (score < (12 - ace))
			score += ace + 10;
		else if (score > (12 - ace))
			score += ace;
		else score += ace + 9;
	}
	this->score = score;
}
GLint BasePlayer::getScore()
{
	this->calScore();
	return score;
}

void BasePlayer::setMoney(int money)
{
	this->money = money;
}
GLint BasePlayer::getMoney()
{
	return money;
}

int BasePlayer::isHit()
{
	return hit;
}

void BasePlayer::setHit(int hit)
{
	this->hit = hit;
}

void BasePlayer::hitCard(std::shared_ptr<Card> card)
{
	hand.push_back(card);
	calScore();
}

void BasePlayer::Init()
{

}

void BasePlayer::Draw()
{

}

void BasePlayer::Update(float deltaTime)
{

}

int BasePlayer::numAce()
{
	int c = 0;
	for (auto it : hand)
	{
		if (it->getValue() == 0)
			c++;
	}
	return c;
}

CardState BasePlayer::getCardState()
{
	if (hand.size() == 2)
	{
		if (numAce() == 2)
			return CardState::TWO_ACES;
		if (numAce() == 1)
		{
			int check = 0;
			for (auto it : hand)
				if (it->getValue() >= 9)
					check = 1;
			if (check)
				return CardState::BLACKJACK;
		}
	}
	int score = getScore();
	if (score < 22 && hand.size() == 5)
		return CardState::FIVE_CARDS;
	if (score < 16)
		return CardState::NOT_ENOUGH;
	if (score < 22)
		return CardState::ENOUGH;
	if (score < 29)
		return CardState::BUST;
}

void BasePlayer::setCardState(CardState cardState)
{
	this->cardState = cardState;
}

int BasePlayer::getNumCards()
{
	return hand.size();
}

std::shared_ptr<Card> BasePlayer::getNewestCard()
{
	if (hand.size() == 0)
		return 0;
	return hand.back();
}

int BasePlayer::getReward()
{
	return reward;
}

void BasePlayer::setReward(int reward)
{
	this->reward = reward;
}