#include "GSMenu.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSMenu::GSMenu()
{

}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_menu1");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);
	
	//Title
	//texture = ResourceManagers::GetInstance()->GetTexture("title1");
	//m_title = std::make_shared<Sprite2D>(model, shader, texture);
	//m_title->Set2DPosition(screenWidth / 2, screenHeight / 2);
	//m_title->SetSize(600, 400);

	//play button
	texture = ResourceManagers::GetInstance()->GetTexture("start_button");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, screenHeight / 2 + 250);
	button->SetSize(200, 80);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		});
	m_listButton.push_back(button);

	//help button
	texture = ResourceManagers::GetInstance()->GetTexture("help_icon1");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth - 200, 50);
	button->SetSize(50, 50);
	//button->SetOnClick([]() {
	//	GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Intro);
	//	});
	m_listButton.push_back(button);

	//exit button
	texture = ResourceManagers::GetInstance()->GetTexture("exit_icon");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth - 60, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button);

	//setting button
	texture = ResourceManagers::GetInstance()->GetTexture("setting_icon");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth - 130, 50);
	button->SetSize(50, 50);
	//button->SetOnClick([]() {
	//	GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Intro);
	//	});
	m_listButton.push_back(button);


	//text game title
	//shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	//std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	//m_Text_gameName = std::make_shared< Text>(shader, font, "BLACKJACK", TEXT_COLOR::WHILE, 2.0);

	//ResourceManagers::GetInstance()->PlaySound("background_music1");
}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{

}

void GSMenu::Resume()
{

}


void GSMenu::HandleEvents()
{

}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSMenu::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	//m_title->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	m_BackGround->Draw();
	//m_title->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}
