#include "Game.h"
#include <algorithm>

Game::Game()
{
	m_bet = 5;
	m_end = false;
	hasCardGiven = false;
	m_player = std::make_shared<Player>();
	m_dealer = std::make_shared<Dealer>();
	this->shuffleCard();
}

Game::Game(std::shared_ptr<Player> player, std::shared_ptr<Dealer> dealer)
{
	this->m_player = player;
	this->m_dealer = dealer;
	hasCardGiven = false;
	this->shuffleCard();
}

Game::~Game()
{

}

void Game::Init()
{
	card = std::make_shared<Card>(0, CardSuit::Hearts); 
	card->Init();
	m_deck.push_back(card);
	//for (auto it : m_deck)
	//{
	//	it->Init();
	//}

}

void Game::HandleEvents()
{

}
void Game::HandleKeyEvents(int key, bool bIsPressed)
{

}

void Game::HandleTouchEvents(int x, int y, bool bIsPressed)
{

}

void Game::Update(float deltaTime)
{
	card->Update(deltaTime);
	//m_time += deltaTime;
	//if (m_time < 1.3)
	//{

	//}
	for (auto it : m_deck)
	{
		it->Update(deltaTime);
	}
}

void Game::Draw()
{
	card->Draw();
	for (auto it = m_deck.rbegin(); it != m_deck.rend(); it++)
	{
		(*it)->Draw();
	}
	int d = 0;
	for (auto it : m_deck)
	{
		if (d < 5 && !hasCardGiven)
		{
			hasCardGiven = true;
			d++;
			it->setOwner(d % 2);
			it->setGiven(1);
		}
	}
}

void Game::shuffleCard()
{
	std::vector<int> iCard;
	for (int i = 0; i < 52; i++)
		iCard.push_back(i);
	random_shuffle(iCard.begin(), iCard.end());
	for (auto it : iCard)
	{
		GLint value;
		CardSuit suit;
		value = it % 13 + 1;
		int s = it / 13;
		switch (s)
		{
		case 0: suit = CardSuit::Hearts; break;
		case 1: suit = CardSuit::Diamonds; break;
		case 2: suit = CardSuit::Clubs; break;
		case 3: suit = CardSuit::Spades; break;
		}
		m_deck.push_back(std::make_shared<Card>(value, suit));
	}
	while (!iCard.empty())
	{
		iCard.pop_back();
	}
}