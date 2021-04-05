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
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	//new game
	m_playGame = std::make_shared<Game>();
	m_playGame->Init();

	//text
	//shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	//std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	//m_score = std::make_shared< Text>(shader, font, "$10,000", TEXT_COLOR::RED, 1.0);
	//m_score->Set2DPosition(Vector2(660, 50));

	//coin
	//texture = ResourceManagers::GetInstance()->GetTexture("coin4");
	//shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	//m_coin = std::make_shared<AnimationSprite>(10, 0.1f, model, shader, texture);
	//m_coin->Set2DPosition(100, 100);
	//m_coin->SetSize(52, 52);

	//ResourceManagers::GetInstance()->PlaySound("background_music1", true);
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
}

void GSPlay::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	m_playGame->Update(deltaTime);
	//m_coin->Update(deltaTime);
}

void GSPlay::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_playGame->Draw();
	//for (auto it : m_listBackCard)
	//{
	//	it->Draw();
	//}
	//m_score->Draw();
	//m_coin->Draw();
}

void GSPlay::SetNewPostionForBullet()
{
}