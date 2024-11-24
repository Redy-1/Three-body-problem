#pragma once

#include "Engine.h"
#include "Presenter.h"

class Tile {
public:
	Tile();
	~Tile();

	void init(int rectX,int rectY);
	void occupy(bool);
	void place_queen(bool);
	void destroy();
	void draw();
//private:
	bool m_occupied;
	SDL_Texture* m_texture;
	SDL_Rect m_rect;
};