#pragma once
#include "Tile.h"
class Board {
public:
	Board();
	~Board();

	Tile board[br_rows][br_cols];

	void init();

	void update(int,int,bool);
	void draw();
	void destroy();
	void go_until(int x,int y,int dir_x,int dir_y,bool);
	int2 find_most();
	int will_occupy(int2);
private:
};