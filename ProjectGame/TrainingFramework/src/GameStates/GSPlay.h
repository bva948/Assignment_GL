#pragma once
#include "gamestatebase.h"
#include "GameButton.h"
#include "AnimationSprite.h"
#include "Game.h"

class Sprite2D;
class Sprite3D;
class Text;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

	
	void SetNewPostionForBullet();

private:

	std::shared_ptr<Sprite2D> m_BackGround;
	std::list<std::shared_ptr<GameButton>>	m_listButton;

	std::shared_ptr<AnimationSprite> m_playerCoin;
	std::shared_ptr<AnimationSprite> m_dealerCoin;

	std::shared_ptr<Game> m_playGame;
	std::shared_ptr<Player> m_player;
	std::shared_ptr<Dealer> m_dealer;
};

