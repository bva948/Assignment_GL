#include "GSPlay.h"

#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("background_play");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//back button
	texture = ResourceManagers::GetInstance()->GetTexture("back_icon");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		ResourceManagers::GetInstance()->PauseSound("bgmusic");
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	//new game
	m_player = std::make_shared<Player>();
	m_dealer = std::make_shared<Dealer>();
	m_playGame = std::make_shared<Game>(m_player, m_dealer);
	m_playGame->Init();

	//player coin
	texture = ResourceManagers::GetInstance()->GetTexture("coin");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_playerCoin = std::make_shared<AnimationSprite>(8, 0.1f, model, shader, texture);
	m_playerCoin->Set2DPosition(screenWidth / 2 - 400, screenHeight / 2 + 195);
	m_playerCoin->SetSize(30, 30);

	//dealer coin
	m_dealerCoin = std::make_shared<AnimationSprite>(8, 0.1f, model, shader, texture);
	m_dealerCoin->Set2DPosition(screenWidth / 2 - 400, screenHeight / 2 - 222);
	m_dealerCoin->SetSize(30, 30);

	ResourceManagers::GetInstance()->PlaySound("bgmusic", true);
}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
	m_playGame->HandleTouchEvents(x, y, bIsPressed);
}

void GSPlay::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	m_playGame->Update(deltaTime);
	m_playerCoin->Update(deltaTime);
	m_dealerCoin->Update(deltaTime);
}

void GSPlay::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_playGame->Draw();
	m_playerCoin->Draw();
	m_dealerCoin->Draw();
}

void GSPlay::SetNewPostionForBullet()
{
}