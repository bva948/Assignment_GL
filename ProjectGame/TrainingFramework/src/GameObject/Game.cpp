#include "Game.h"
#include <algorithm>

Game::Game()
{
	m_bet = 5;
	m_end = 0;
	m_player = std::make_shared<Player>();
	m_dealer = std::make_shared<Dealer>();
	shuffleCard();
	startChecked = 0;
	winner = 3;
}

Game::Game(std::shared_ptr<Player> player, std::shared_ptr<Dealer> dealer)
{
	m_bet = 5;
	m_end = 0;
	this->m_player = player;
	this->m_dealer = dealer;
	shuffleCard();
	startChecked = 0;
	winner = 3;
}

Game::~Game()
{

}

void Game::Init()
{
	for (int i = 51; i > 40; i--)
	{
		m_cards[i]->Init();
	}
	m_player->Init();
	m_dealer->Init();

	//hit button
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("hit_button1");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_hitButton = std::make_shared<Sprite2D>(model, shader, texture);
	m_hitButton->Set2DPosition(screenWidth / 2 - 300, screenHeight / 2);
	m_hitButton->SetSize(100, 50);

	//stand button
	texture = ResourceManagers::GetInstance()->GetTexture("stand_button");
	m_standButton = std::make_shared<Sprite2D>(model, shader, texture);
	m_standButton->Set2DPosition(screenWidth / 2 + 300, screenHeight / 2);
	m_standButton->SetSize(100, 50);

	//win announcement
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("josefin");
	m_win = std::make_shared<Text>(shader, font, "YOU WIN", TEXT_COLOR::YELLOW, 2.0);
	m_win->Set2DPosition(Vector2(screenWidth / 2 + 200, screenHeight / 2));

	//lose announcement
	m_lose = std::make_shared<Text>(shader, font, "YOU LOSE", TEXT_COLOR::YELLOW, 2.0);
	m_lose->Set2DPosition(Vector2(screenWidth / 2 + 200, screenHeight / 2));

	//push announcement
	m_push = std::make_shared<Text>(shader, font, "PUSH", TEXT_COLOR::YELLOW, 2.0);
	m_push->Set2DPosition(Vector2(screenWidth / 2 + 200, screenHeight / 2));

}

void Game::HandleEvents()
{

}
void Game::HandleKeyEvents(int key, bool bIsPressed)
{

}

void Game::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	if (!m_player->isStand())
	{
		if (m_player->getCardState() == CardState::NOT_ENOUGH || m_player->getCardState() == CardState::ENOUGH)
		{
			if ((x > m_hitButton->Get2DPosition().x - 50) && (x < m_hitButton->Get2DPosition().x + 50) && (y > m_hitButton->Get2DPosition().y - 25) && (y < m_hitButton->Get2DPosition().y + 25))
			{
				giveCard(m_deck.size() - 1, 1, m_player->getNumCards() + 1);
			}
			if (m_player->getCardState() == CardState::ENOUGH)
			{
				if ((x > m_hitButton->Get2DPosition().x - 50) && (x < m_hitButton->Get2DPosition().x + 50) && (y > m_hitButton->Get2DPosition().y - 25) && (y < m_hitButton->Get2DPosition().y + 25))
				{

				}
				if ((x > m_standButton->Get2DPosition().x - 50) && (x < m_standButton->Get2DPosition().x + 50) && (y > m_standButton->Get2DPosition().y - 25) && (y < m_standButton->Get2DPosition().y + 25))
				{
					m_player->setStand();
				}
			}
		}
		if (m_player->getCardState() == CardState::BUST || m_player->getCardState() == CardState::FIVE_CARDS)
		{
			if ((x > m_standButton->Get2DPosition().x - 50) && (x < m_standButton->Get2DPosition().x + 50) && (y > m_standButton->Get2DPosition().y - 25) && (y < m_standButton->Get2DPosition().y + 25))
			{
				m_player->setStand();
			}

		}
	}
}

void Game::Update(float deltaTime)
{
	if (m_end && m_dealer->isEnd() && !(m_dealer->getNewestCard()->isGiven))
	{
		
		
	}
	m_dealer->Update(deltaTime);
	m_player->Update(deltaTime);
		
	for (int i = 51; i > 40; i--)
	{
		if (m_cards[i]->isGiven)
			m_cards[i]->Update(deltaTime);
	}

	int i = m_deck.size() - 1;
	if (i > 47 && !(m_cards[i]->isGiven))
	{
		giveCard(i, (52 - i) % 2, (51 - i) / 2);

	}
	if (i == 47 && !startChecked)
	{
		startWinner();
		if (winner != 3)
		{
			
			m_player->setStand();
			m_end = 1;
			m_dealer->setEnd();
			m_player->end = 1;
		}
		else startChecked = 1;
	}
	if (m_player->isStand() && !m_dealer->isEnd())
	{
		if (!m_dealer->isHit())
		{
			m_dealer->action();
			if (!(m_cards[i]->isGiven))
			{
				giveCard(i, 0, m_dealer->getNumCards() + 1);
				m_dealer->setHit(0);
			}
			else
			{
				m_end = 1;
				m_dealer->setEnd();
				endWinner();
				m_player->end = 1;
			}
		}
		
	}
	if (m_dealer->isEnd())
	{
		m_end = 1;
		m_player->end = 1;
	}
		
}

void Game::Draw()
{
	if (m_end && m_dealer->isEnd())
	{
		if (winner == 0)
			m_lose->Draw();
		else if (winner == 1)
			m_win->Draw();
		else m_push->Draw();
	}
	for (int i = 41; i <= 51; i++)
	{
		m_cards[i]->Draw();
	}
	m_player->Draw();
	m_dealer->Draw();

	if (!m_player->isStand())
	{
		if (m_player->getCardState() == CardState::NOT_ENOUGH || m_player->getCardState() == CardState::ENOUGH)
		{
			if (m_player->getNumCards() == 5 || (m_deck.size() - 1 == 47 && !(m_dealer->getNewestCard()->isGiven)) || (m_player->getNumCards() > 2 && m_player->getCardState() == CardState::NOT_ENOUGH))
			{
				m_hitButton->Draw();
			}
			if (m_player->getCardState() == CardState::ENOUGH && m_deck.size() - 1 <= 47 && !(m_dealer->getNewestCard()->isGiven))
			{
				m_hitButton->Draw();
				m_standButton->Draw();
			}

		}
		if (m_player->getCardState() == CardState::BUST || m_player->getCardState() == CardState::FIVE_CARDS)
		{
			m_standButton->Draw();
		}

	}
}

void Game::shuffleCard()
{
	std::vector<int> iCard;
	for (int i = 0; i < 52; i++)
		iCard.push_back(i);
	std::srand(std::time(0));
	random_shuffle(iCard.begin(), iCard.end());
	for (auto it : iCard)
	{
		GLint value;
		CardSuit suit;
		value = it % 13;
		int s = it / 13;
		switch (s)
		{
		case 0: suit = CardSuit::Hearts; break;
		case 1: suit = CardSuit::Diamonds; break;
		case 2: suit = CardSuit::Clubs; break;
		case 3: suit = CardSuit::Spades; break;
		}
		std::shared_ptr<Card> tmp_card = std::make_shared<Card>(value, suit);
		m_cards.push_back(tmp_card);
		m_deck.push_back(tmp_card);
	}
	while (!iCard.empty())
	{
		iCard.pop_back();
	}
}

void Game::giveCard(int i, int owner, int stt)
{
	if (m_cards[i]->getOwner() == 2)
	{
		m_cards[i]->setOwner(owner);
		m_cards[i]->setGiven(1);
		m_cards[i]->setstt(stt);
		if (m_cards[i]->getOwner() == 1)
			m_player->hitCard(m_cards[i]);
		else m_dealer->hitCard(m_cards[i]);
	}
	else {
		m_deck.pop_back();
	}
}

void Game::startWinner()
{
	CardState playerCardState = m_player->getCardState();
	CardState dealerCardState = m_dealer->getCardState();
	if (playerCardState == CardState::TWO_ACES || dealerCardState == CardState::TWO_ACES)
	{
		if (playerCardState == dealerCardState)
			winner = 2;
		else if (playerCardState == CardState::TWO_ACES)
		{
			m_player->setReward(2 * m_bet);
			m_dealer->setReward(-2 * m_bet);
		}
		else
		{
			m_player->setReward(-2 * m_bet);
			m_dealer->setReward(2 * m_bet);
		}
	}
	else if (playerCardState == CardState::BLACKJACK || dealerCardState == CardState::BLACKJACK)
	{
		if (playerCardState == dealerCardState)
			winner = 2;
		else if (playerCardState == CardState::BLACKJACK)
		{
			m_player->setReward(m_bet);
			m_dealer->setReward(-m_bet);
		}
		else
		{
			m_player->setReward(-m_bet);
			m_dealer->setReward(m_bet);
		}
	}
}

void Game::endWinner()
{
	CardState playerCardState = m_player->getCardState();
	CardState dealerCardState = m_dealer->getCardState();
	if (playerCardState == dealerCardState)
	{
		if (playerCardState == CardState::FIVE_CARDS)
		{
			if (m_player->getScore() == m_dealer->getScore())
				winner = 2;
			else if (m_player->getScore() < m_dealer->getScore())
			{
				winner = 1;
				m_player->setReward(m_bet);
				m_dealer->setReward(-m_bet);
			}	
			else
			{
				winner = 0;
				m_player->setReward(-m_bet);
				m_dealer->setReward(m_bet);
			}
		}
		else if (playerCardState == CardState::ENOUGH)
		{
			if (m_player->getScore() == m_dealer->getScore())
				winner = 2;
			else if (m_player->getScore() < m_dealer->getScore())
			{
				winner = 0;
				m_player->setReward(-m_bet);
				m_dealer->setReward(m_bet);
			}
			else
			{
				winner = 1;
				m_player->setReward(m_bet);
				m_dealer->setReward(-m_bet);
			}
		}
		else winner = 2;
	}
	else if (playerCardState < dealerCardState)
	{
		winner = 0;
		m_player->setReward(-m_bet);
		m_dealer->setReward(m_bet);
	}
	else 
	{
		winner = 1;
		m_player->setReward(m_bet);
		m_dealer->setReward(-m_bet);
	}
}