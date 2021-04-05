#pragma once
#include <GLES2/gl2.h>
#include "Card.h"
#include "Player.h"
#include "Dealer.h"

class Game 
{
public:
	Game();
	Game(std::shared_ptr<Player> player, std::shared_ptr<Dealer> dealer);
	~Game();

	void Init();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

	void shuffleCard();
private:
	GLint m_bet;
	GLboolean m_end;
	std::vector<std::shared_ptr<Card>> m_deck;
	//std::list<Player> list_players;
	std::shared_ptr<Player> m_player;
	std::shared_ptr<Dealer> m_dealer;
	float m_time;
	std::shared_ptr<Card> card;
	GLboolean hasCardGiven;
};