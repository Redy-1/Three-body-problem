#include "Menu.h"
#include "Presenter.h"

void Menu::init_easy() {
	m_easy_rect.x = 1433;
	m_easy_rect.y = 475;
	m_easy_rect.w = 300;
	m_easy_rect.h = 150;
	m_easy_texture = loadTexture("easy.bmp");
}

void Menu::init_medium() {
	m_medium_rect.x = 1433;
	m_medium_rect.y = m_easy_rect.y+m_easy_rect.h;
	m_medium_rect.w = 300;
	m_medium_rect.h = 150;
	m_medium_texture = loadTexture("medium.bmp");
}

void Menu::init_hard() {
	m_hard_rect.x = 1433;
	m_hard_rect.y = m_medium_rect.y+m_medium_rect.h;
	m_hard_rect.w = 300;
	m_hard_rect.h = 150;
	m_hard_texture = loadTexture("hard.bmp");
}

void Menu::init_quit()
{
	m_quit_rect.x = 1040;
	m_quit_rect.y = 600;
	m_quit_rect.w = 400;
	m_quit_rect.h = 200;
	m_quit_texture = loadTexture("1player.bmp");
}

void Menu::init_title()
{
	m_title_rect.w = 1000;
	m_title_rect.x = (screen_w - m_title_rect.w) / 2;
	m_title_rect.y = 100;
	m_title_rect.h = 500;
	m_title_texture = loadTexture("Title.bmp"); 
}

void Menu::init_2players()
{
	m_2players_rect.x = 440;
	m_2players_rect.y = 600;
	m_2players_rect.w = 400;
	m_2players_rect.h = 200;
	m_2players_texture = loadTexture("2players.bmp");
}

void Menu::init_background()
{
	m_background_rect.x = 0;
	m_background_rect.x = 0;
	m_background_rect.w = screen_w;
	m_background_rect.h = screen_h;
	m_background_texture = loadTexture("menu_background.bmp");
}

void Menu::init_all()
{
	init_easy();
	init_medium();
	init_hard();
	init_background();
	init_quit();
	init_2players();
	init_title();
}

void Menu::draw_quit()
{
	Drawable tmp;
	tmp.texture = m_quit_texture;
	tmp.rect = m_quit_rect;
	drawObject(tmp);
}

void Menu::draw_title()
{
	Drawable tmp;
	tmp.texture = m_title_texture;
	tmp.rect = m_title_rect;
	drawObject(tmp);
}

void Menu::draw_2players()
{
	Drawable tmp;
	tmp.texture = m_2players_texture;
	tmp.rect = m_2players_rect;
	drawObject(tmp);
}

void Menu::draw_background()
{
	Drawable tmp;
	tmp.texture = m_background_texture;
	tmp.rect = m_background_rect;
	drawObject(tmp);
}

void Menu::draw_easy()
{
	Drawable tmp;
	tmp.texture = m_easy_texture;
	tmp.rect = m_easy_rect;
	drawObject(tmp);
}
void Menu::draw_medium()
{
	Drawable tmp;
	tmp.texture = m_medium_texture;
	tmp.rect = m_medium_rect;
	drawObject(tmp);
}
void Menu::draw_hard()
{
	Drawable tmp;
	tmp.texture = m_hard_texture;
	tmp.rect = m_hard_rect;
	drawObject(tmp);
}
void Menu::draw_all()
{
	draw_background();
	draw_2players();
	draw_quit();
	draw_title();
}

void Menu::draw_diff() {
	draw_easy();
	draw_medium();
	draw_hard();
}