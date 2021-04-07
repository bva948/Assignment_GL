#pragma once
#include "GLES2/gl2.h"
#include "Sprite2D.h"
#include "ResourceManagers.h"

enum class CardSuit
{
	Hearts, Diamonds, Clubs, Spades
};
class Card
{
public:
	Card();
	Card(GLint value, CardSuit suit);
	~Card();

	void Init();
	void Draw();
	void Update(float deltaTime);

	GLint getValue();
	CardSuit getSuit();

	void setGiven(GLboolean isGiven);

	int getOwner();
	void setOwner(int owner);

	int stt;
	void setstt(int stt);

	int isUp();
	void setUp();

	GLboolean isGiven;
	
private:
	std::shared_ptr<Sprite2D> m_card;
	std::shared_ptr<Sprite2D> m_backCard;
	int up;
	CardSuit suit;
	GLint value;
	Vector2 pos;
	
	int owner; //owner = 0 -> dealer, owner = 1 -> player, owner = 2 -> not given
	GLint numCardBefore;
	float m_time;
};