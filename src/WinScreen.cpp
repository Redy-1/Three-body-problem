#include "WinScreen.h"
#include "Presenter.h"

WinScreen::WinScreen(){}

WinScreen::~WinScreen(){}

void WinScreen::init_victory(bool p1_wins)
{
	m_victory_msg_rect.w = 600;
	m_victory_msg_rect.x = (screen_w- m_victory_msg_rect.w)/2;
	m_victory_msg_rect.y = 200;
	m_victory_msg_rect.h = m_victory_msg_rect.w/2;
	if (p1_wins) {
		m_victory_msg_texture = loadTexture("p1_wins_msg.bmp");
	}
	else {
		m_victory_msg_texture = loadTexture("p2_wins_msg.bmp");
	}
	
}

void WinScreen::init_quit()
{
	m_quit_rect.x = 440;
	m_quit_rect.y = 700;
	m_quit_rect.w = 400;
	m_quit_rect.h = 200;
	m_quit_texture = loadTexture("quit.bmp");
}

void WinScreen::init_play_again()
{
	m_play_again_rect.x = 1040;
	m_play_again_rect.y = 700;
	m_play_again_rect.w = 400;
	m_play_again_rect.h = 200;
	m_play_again_texture = loadTexture("play_again.bmp");
}

void WinScreen::init_background()
{
	m_background_rect.x = 0;
	m_background_rect.x = 0;
	m_background_rect.w = screen_w;
	m_background_rect.h = screen_h;
	m_background_texture = loadTexture("win_screen_p1_v2.bmp");
}

void WinScreen::init_all(bool p1_wins)
{
	init_background();
	init_victory(p1_wins);
	init_quit();
	init_play_again();
}

void WinScreen::draw_victory()
{
	Drawable tmp;
	tmp.texture = m_victory_msg_texture;
	tmp.rect = m_victory_msg_rect;
	drawObject(tmp);
}

void WinScreen::draw_quit()
{
	Drawable tmp;
	tmp.texture = m_quit_texture;
	tmp.rect = m_quit_rect;
	drawObject(tmp);
}

void WinScreen::draw_play_again()
{
	Drawable tmp;
	tmp.texture = m_play_again_texture;
	tmp.rect = m_play_again_rect;
	drawObject(tmp);
}

void WinScreen::draw_background()
{
	Drawable tmp;
	tmp.texture = m_background_texture;
	tmp.rect = m_background_rect;
	drawObject(tmp);
}

void WinScreen::draw_all()
{
	draw_background();
	draw_victory();
	draw_quit();
	draw_play_again();
}
