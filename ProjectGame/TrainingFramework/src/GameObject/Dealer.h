#pragma once
#include "BasePlayer.h"

class Dealer : public BasePlayer
{
public:
	Dealer();
	~Dealer();

	int isEnd();
	void setEnd();

	void Init() override;
	void Draw() override;
	void Update(float deltaTime) override;

	void action(); 
private:
	int end;

	std::shared_ptr<Sprite2D> m_dealer;
	std::shared_ptr<Text> m_dealerReward;

};