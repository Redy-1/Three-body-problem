#include "Board.h"

Board::Board(){}

Board::~Board(){}

void Board::init(){
	for (int i = 0; i < br_rows; i++) {
		for (int j = 0; j < br_cols; j++) {
			board[i][j].init(offset_x + i * tile_w, offset_y + j * tile_h);
			/*
			cout <<"W: "<< board[i][j].m_rect.w << endl;
			cout <<"H: " << board[i][j].m_rect.h << endl;;
			cout <<"X: "<< board[i][j].m_rect.x << endl;
			cout <<"Y: "<< board[i][j].m_rect.y << endl;
			cout <<"Texture: "<< board[i][j].m_texture << endl;
			*/
		}
	}
}

void Board::update(int x,int y, bool player){
	board[x][y].place_queen(player);
	go_until(x, y, 0,   1, player);
	go_until(x, y, -1,  1, player);
	go_until(x, y, 1,   1, player);
	go_until(x, y, 1,   0, player);
	go_until(x, y, -1,  0, player);
	go_until(x, y, 0,  -1, player);
	go_until(x, y, -1, -1, player);
	go_until(x, y, 1,  -1, player);
}

void Board::draw(){
	for (int i = 0; i < br_rows; i++) {
		for (int j = 0; j < br_cols; j++) {
			board[i][j].draw();
		}
	}
}

void Board::go_until(int x, int y, int dir_x, int dir_y,bool player)
{
	int new_x=x+dir_x;
	int new_y=y+dir_y;
	if (new_x >= br_rows || new_x < 0 || new_y >= br_cols || new_y < 0) {
		return;
	}
	board[new_x][new_y].occupy(player);
	go_until(new_x, new_y, dir_x, dir_y, player);
}

int2 Board::find_most()
{
	int max = 0;
	int2 max_coords;
	max_coords.x = 0;
	max_coords.y = 0;
	for (int i = 0; i < br_rows; i++) {
		for (int j = 0; j < br_cols; j++) {
			int2 t;
			t.x = i;
			t.y = j;
			int temp = will_occupy(t);
			if (temp > max) {
				max = temp;
				max_coords.x = i;
				max_coords.y = j;
			}
		}
	}
	return max_coords;
}

int Board::will_occupy(int2 coords)
{
	int br = 0;
	for (int i = 0; i < br_rows; i++) {
		for (int j = 0; j < br_cols; j++) {
			if (board[i][j].m_occupied) {
				continue;
			}
			if (i==coords.x) {
				br++;
			}
			if (j == coords.y) {
				br++;
			}
			if (i - j == coords.x-coords.y) {
				br++;
			}
			if (i + j == coords.x + coords.y) {
				br++;
			}
		}
	}
	return br;
}

void Board::destroy(){
	delete board;
}