#pragma once

#include "Presenter.h"
#include "InputManager.h"
#include "Board.h"
#include "WinScreen.h"
#include "Menu.h"

class World
{
public:
	World();
	~World();

	Presenter m_presenter;
	InputManager m_inputManager;
	
	void init();
	void run();
	void destroy();
	void place();

	bool isRunning();

	
private:
	bool m_isRunning;
	bool m_game_over;
	Board b;
	int m_turn;
	bool player1_won;
	int m_game_state;
	bool m_flag;

	WinScreen p1_winScreen;
	WinScreen p2_winScreen;
	Menu menu;

	GameState gs;
};