#include "Tile.h"


Tile::Tile(){}

Tile::~Tile(){}

void Tile::init(int rect_x, int rect_y)
{
	m_rect.x = rect_x;
	m_rect.y = rect_y;
	m_rect.h = tile_h;
	m_rect.w = tile_w;
	m_occupied = false;
	m_texture = loadTexture("white_square_test.bmp");
}

void Tile::occupy(bool player)
{
	if (m_occupied) { return; }
	m_occupied = true;
	if (player) {
		m_texture = loadTexture("occupied_square.bmp");
	}
	else {
		m_texture = loadTexture("occupied_square_v2.bmp");
	}
	
}

void Tile::place_queen(bool player)
{
	m_occupied = true;
	if (player) {
		m_texture = loadTexture("queen_v2_better.bmp");
	}
	else {
		m_texture = loadTexture("queen_v2_better_v2.bmp");
	}
}

void Tile::destroy()
{
	SDL_DestroyTexture(m_texture);
}

void Tile::draw()
{
	Drawable tmp;
	tmp.texture = m_texture;
	tmp.rect = m_rect;
	drawObject(tmp);
}
