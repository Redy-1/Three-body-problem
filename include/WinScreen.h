#pragma once 

#include "Engine.h"

class WinScreen {
public:
	WinScreen();
	~WinScreen();

	SDL_Rect m_background_rect;
	SDL_Texture* m_background_texture;

	SDL_Rect m_victory_msg_rect;
	SDL_Texture* m_victory_msg_texture;

	SDL_Rect m_quit_rect;
	SDL_Texture* m_quit_texture;

	SDL_Rect m_play_again_rect;
	SDL_Texture* m_play_again_texture;

	void init_victory(bool);
	void init_quit();
	void init_play_again();
	void init_background();

	void init_all(bool);

	void draw_victory();
	void draw_quit();
	void draw_play_again();
	void draw_background();

	void draw_all();
};