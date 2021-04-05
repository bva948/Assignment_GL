#include "Card.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

Card::Card()
{
	isGiven = false;
	up = false;
	numCardBefore = 0;
}

Card::Card(GLint value, CardSuit suit)
{
	isGiven = false;
	up = false;
	numCardBefore = 0;
	this->value = value;
	this->suit = suit;
}

Card::~Card()
{

}

void Card::Init()
{
	char nameCard[10]="";
	switch (getValue())
	{
	case 0: strcat_s(nameCard, "a_"); break;
	case 1: strcat_s(nameCard, "2_"); break;
	case 2: strcat_s(nameCard, "3_"); break;
	case 3: strcat_s(nameCard, "4_"); break;
	case 4: strcat_s(nameCard, "5_"); break;
	case 5: strcat_s(nameCard, "6_"); break;
	case 6: strcat_s(nameCard, "7_"); break;
	case 7: strcat_s(nameCard, "8_"); break;
	case 8: strcat_s(nameCard, "9_"); break;
	case 9: strcat_s(nameCard, "10_"); break;
	case 10: strcat_s(nameCard, "j_"); break;
	case 11: strcat_s(nameCard, "q_"); break;
	case 12: strcat_s(nameCard, "k_"); break;
	}
	switch (getSuit())
	{
	case CardSuit::Hearts: strcat_s(nameCard, "heart"); break;
	case CardSuit::Diamonds: strcat_s(nameCard, "diamond"); break;
	case CardSuit::Clubs: strcat_s(nameCard, "club"); break;
	case CardSuit::Spades: strcat_s(nameCard, "spade"); break;
	}
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameCard);
	m_card = std::make_shared<Sprite2D>(model, shader, texture);
	m_card->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_card->SetSize(75, 100);

	texture = ResourceManagers::GetInstance()->GetTexture("back_card");
	m_backCard = std::make_shared<Sprite2D>(model, shader, texture);
	m_backCard->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_backCard->SetSize(75, 100);
}


void Card::Draw()
{
	if (this->up)
	{
		m_card->Draw();
	}
	else m_backCard->Draw();
}

void Card::Update(float deltaTime)
{
	if (isGiven)
	{
		this->Given(deltaTime, owner);
		if (owner != 0)
			this->up = true;
		isGiven = false;
	}
	m_card->Set2DPosition(m_backCard->Get2DPosition().x - 10 * numCardBefore, m_backCard->Get2DPosition().y);
	m_backCard->Set2DPosition(m_backCard->Get2DPosition().x - 10*numCardBefore, m_backCard->Get2DPosition().y);
}

void Card::Given(float deltaTime, GLboolean owner)
{
	if (owner != 0 && m_backCard->Get2DPosition().y < 500)
	{
		m_backCard->Set2DPosition(m_backCard->Get2DPosition().x, m_backCard->Get2DPosition().y + deltaTime * 100);
	}
	if (owner == 0 && m_backCard->Get2DPosition().y > 100)
	{
		m_backCard->Set2DPosition(m_backCard->Get2DPosition().x, m_backCard->Get2DPosition().y - deltaTime * 100);
	}
}


GLint Card::getValue()
{
	return value;
}

CardSuit Card::getSuit()
{
	return suit;
}

void Card::setGiven(GLboolean isGiven)
{
	this->isGiven = isGiven;
}

void Card::setOwner(GLboolean owner)
{
	this->owner = owner;
}