#pragma once
#include <GLES2/gl2.h>
#include "Card.h"
#include "BasePlayer.h"
#include "GameButton.h"

enum class PlayerState
{
	PLAY, STAND
};

class Player : public BasePlayer

{
public:
	Player();
	~Player();
	void Init() override;
	void Draw() override;
	void Update(float deltaTime) override;

	void HandleTouchEvents();

	void setStand();
	int isStand();

	int end;
private:
	int stand;

	std::shared_ptr<Sprite2D> m_player;
	std::shared_ptr<Text> m_playerReward;
};