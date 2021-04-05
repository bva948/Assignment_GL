#pragma once
#include <GLES2/gl2.h>
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
	void Given(float deltaTime, GLboolean owner);

	GLint getValue();
	CardSuit getSuit();
	void setGiven(GLboolean isGiven);
	void setOwner(GLboolean owner);
private:
	std::shared_ptr<Sprite2D> m_card;
	std::shared_ptr<Sprite2D> m_backCard;
	GLboolean up;
	CardSuit suit;
	GLint value;
	Vector2 pos;
	GLboolean owner; //owner = 0 -> dealer
	GLboolean isGiven;
	GLint numCardBefore;
};