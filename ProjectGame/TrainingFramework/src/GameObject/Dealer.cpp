#include "Dealer.h"

Dealer::Dealer(): BasePlayer()
{
	basePlayerName = "Dealer";
	end = 0;
}

Dealer::~Dealer()
{

}

int Dealer::isEnd()
{
	return end;
}

void Dealer::setEnd()
{
	this->end = 1;
}

void Dealer::Init()
{
	//name box
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("dealer_name");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_dealer = std::make_shared<Sprite2D>(model, shader, texture);
	m_dealer->Set2DPosition(screenWidth / 2 - 200, screenHeight / 2 - 200);
	m_dealer->SetSize(100, 50);

	//score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("josefin");
	m_textScore = std::make_shared<Text>(shader, font, "Score: ", TEXT_COLOR::YELLOW, 1.0);
	m_textScore->Set2DPosition(Vector2(screenWidth / 2 - 400, screenHeight / 2 - 180));

	m_score = std::make_shared<Text>(shader, font, std::to_string(score), TEXT_COLOR::YELLOW, 1.0);
	m_score->Set2DPosition(Vector2(screenWidth / 2 - 300, screenHeight / 2 - 180));

	//money
	m_money = std::make_shared<Text>(shader, font, "$" + std::to_string(money) + ",000", TEXT_COLOR::YELLOW, 1.0);
	m_money->Set2DPosition(Vector2(screenWidth / 2 - 380, screenHeight / 2 - 220));

	//dealer reward
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	m_dealerReward = std::make_shared<Text>(shader, font, std::to_string(getReward()) + ",000", TEXT_COLOR::YELLOW, 1.0);
	m_dealerReward->Set2DPosition(Vector2(screenWidth / 2 - 380, screenHeight / 2 - 250));
}

void Dealer::Draw()
{
	m_dealer->Draw(); 
	if (end && !getNewestCard()->isGiven)
	{
		m_textScore->Draw();
		m_score->Draw();
		m_dealerReward->Draw();
		for (auto it : hand)
		{
			it->setUp();
		}
	}
	m_money->Draw();
}

void Dealer::Update(float deltaTime)
{
	m_score->setText(std::to_string(score));
	if (reward != 0)
	{
		if (getReward() > 0)
			m_dealerReward->setText("+" + std::to_string(getReward()) + ",000");
		else m_dealerReward->setText(std::to_string(getReward()) + ",000");
		m_money->setText(std::to_string(money + reward) + ",000");
		reward = 0;
	}
}

void Dealer::action()
{
	if (getCardState() == CardState::NOT_ENOUGH)
		setHit(1);
	else {
		srand(time(0));
		int x = rand() % 100 + 1;
		float y = x / sqrt(3);
		y = y - (int)y;
		switch (getScore())
		{
		case 16:
			if (y < 0.7)
				setHit(1);
			else setEnd();
		case 17:
			if (y < 0.4)
				setHit(1);
			else setEnd();
		case 18:
			if (y < 0.05)
				setHit(1);
			else setEnd();
		case 19:
			if (y < 0.01)
				setHit(1);
			else setEnd();
		case 20:
			if (y < 0.0001)
				setHit(1);
			else setEnd();
		default: setEnd();
		}
		
	}
}