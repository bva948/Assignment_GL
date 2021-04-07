#include "Player.h"
//
Player::Player() : BasePlayer()
{
	basePlayerName = "Player";
	stand = 0;
	end = 0;
}

Player::~Player()
{

}


void Player::Init()
{
	//name box
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("player_name");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_player = std::make_shared<Sprite2D>(model, shader, texture);
	m_player->Set2DPosition(screenWidth / 2 - 200, screenHeight / 2 + 200);
	m_player->SetSize(100, 50);

	//score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("josefin");
	m_textScore = std::make_shared<Text>(shader, font, "Score: ", TEXT_COLOR::YELLOW, 1.0);
	m_textScore->Set2DPosition(Vector2(screenWidth / 2 - 400, screenHeight / 2 + 240));

	m_score = std::make_shared<Text>(shader, font, std::to_string(score), TEXT_COLOR::YELLOW, 1.0);
	m_score->Set2DPosition(Vector2(screenWidth / 2 - 300, screenHeight / 2 + 240));

	//money
	m_money = std::make_shared<Text>(shader, font, "$" + std::to_string(money) + ",000", TEXT_COLOR::YELLOW, 1.0);
	m_money->Set2DPosition(Vector2(screenWidth / 2 - 380, screenHeight / 2 + 200));


	//player reward
	m_playerReward = std::make_shared<Text>(shader, font, std::to_string(getReward()) + ",000", TEXT_COLOR::YELLOW, 1.0);
	m_playerReward->Set2DPosition(Vector2(screenWidth / 2 - 380, screenHeight / 2 + 170));
}

void Player::Draw()
{
	m_player->Draw();
	m_textScore->Draw();
	m_score->Draw();
	m_money->Draw();
	if (end)
		m_playerReward->Draw();

}
void Player::Update(float deltaTime)
{
	if (hand.size() != 0)
		if (hand.back()->isUp())
			m_score->setText(std::to_string(score));
	if (reward != 0)
	{
		if (getReward() > 0)
			m_playerReward->setText("+" + std::to_string(getReward()) + ",000");
		else m_playerReward->setText(std::to_string(getReward()) + ",000");
		m_money->setText(std::to_string(money + reward) + ",000");
		reward = 0;
	}
}

void Player::setStand()
{
	stand = 1;
}

int Player::isStand()
{
	return stand;
}