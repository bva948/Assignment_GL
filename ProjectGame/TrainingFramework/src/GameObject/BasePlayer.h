#pragma once
#include "GLES2/gl2.h"
#include "vector"
#include "memory"
#include "Card.h"
#include "AnimationSprite.h""

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

enum class CardState
{
	NOT_ENOUGH, BUST, ENOUGH, FIVE_CARDS, BLACKJACK, TWO_ACES
};

class BasePlayer
{
public:
		BasePlayer();
		~BasePlayer();

		virtual void Init();
		virtual void Draw();
		virtual void Update(float deltaTime);

		void calScore();
		GLint getScore();
	
		void setMoney(int money);
		int getMoney();
	
		int isHit();
		void setHit(int hit);
		void hitCard(std::shared_ptr<Card> card);

		CardState getCardState();
		void setCardState(CardState cardState);

		int numAce();

		int getNumCards();

		std::shared_ptr<Card> getNewestCard();

		int getReward();
		void setReward(int reward);
protected:
	char* basePlayerName;
	int money;
	int score;
	int hit;

	CardState cardState;
	std::vector<std::shared_ptr<Card>> hand;

	std::shared_ptr<AnimationSprite> m_coin;
	std::shared_ptr<Text>  m_textScore;
	std::shared_ptr<Text>  m_score;
	std::shared_ptr<Text>  m_money;
	int reward;
};