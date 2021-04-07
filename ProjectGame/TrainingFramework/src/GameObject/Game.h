#pragma once
#include <GLES2/gl2.h>
#include "Card.h"
#include "Player.h"
#include "Dealer.h"
#include "Font.h"

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


	void giveCard(int i, int owner, int stt);

	void startWinner(); //0 -> dealer, 1 -> player, 2 -> push, 3 -> game not over
	void endWinner(); //0 -> dealer, 1 -> player, 2 -> push, 3 -> game not over

private:
	GLint m_bet;
	int m_end;
	std::vector<std::shared_ptr<Card>> m_deck;
	std::vector<std::shared_ptr<Card>> m_cards;

	std::shared_ptr<Player> m_player;
	std::shared_ptr<Dealer> m_dealer;

	std::shared_ptr<Sprite2D> m_hitButton;
	std::shared_ptr<Sprite2D> m_standButton;

	int startChecked;
	int winner; //0 -> dealer, 1 -> player, 2 -> push, 3 -> game not over

	std::shared_ptr<Text>  m_win;
	std::shared_ptr<Text>  m_lose;
	std::shared_ptr<Text>  m_push;
};