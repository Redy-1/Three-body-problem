#include "World.h"
#include <time.h>

World::World()
{
	m_isRunning = true;
}

World::~World()
{
}

void World::init()
{
	background_rect.x = 0;
	background_rect.y = 0;
	background_rect.x = screen_w;
	background_rect.y = screen_h;
	
	m_turn = 0;
	m_flag = false;
	m_game_over = false;
	m_presenter.init();
	b.init();
	background_texture = loadTexture("better_background.bmp");
	
	p1_winScreen.init_all(0);
	p2_winScreen.init_all(1);

	menu.init_all();
}


void World::place() {
	if (m_inputManager.m_mouseIsPressed) {
		//cout << "Mouse x:" << m_inputManager.m_mouseCoor.x << endl;
		//cout << "Mouse y:" << m_inputManager.m_mouseCoor.y << endl;
		int real_x = (m_inputManager.m_mouseCoor.x - offset_x) / tile_h;
		int real_y = (m_inputManager.m_mouseCoor.y - offset_y) / tile_h;
		//cout << "Mouse real x:" << (m_inputManager.m_mouseCoor.x-offset_x)/tile_h << endl;
		//cout << "Mouse real y:" << (m_inputManager.m_mouseCoor.y-offset_y)/tile_h << endl;
		if (!b.board[real_x][real_y].m_occupied && real_x < br_cols && real_x >= 0 && real_y < br_cols && real_y >= 0) {
			b.update(real_x, real_y, m_turn % 2);
			m_turn++;
			bool flag = true;
			for (int i = 0; i < br_rows; i++) {
				for (int j = 0; j < br_cols; j++) {
					if (!b.board[i][j].m_occupied) {
						flag = false;
					}
				}
			}
			if (flag) {
				player1_won = m_turn % 2;
				gs = WScreen;
			}
		}
	}
}

void World::run()
{
	m_inputManager.handleInput();
	drawObject(background_texture);
	
	if (gs == WScreen) {
		if (!(m_turn % 2)) {
			p1_winScreen.draw_all();
		}
		else {
			p2_winScreen.draw_all();
		}
		if (m_inputManager.m_mouseIsPressed) {
			if (MouseIsInRect(m_inputManager.m_mouseCoor, p1_winScreen.m_quit_rect)) {
				exit(0);
			}
			if (MouseIsInRect(m_inputManager.m_mouseCoor, p1_winScreen.m_play_again_rect)) {
				gs = StartMenu;
				b.init();
				m_turn = 0;
			}

		}
	}
	if(gs==Game2p) {
		place();
		b.draw();
	}
	if (gs == Game1pD1 ) {
		if (m_turn % 2==0) {
			place();
		}
		else {
			int2 r;
			r.x = rand() % br_rows;
			r.y = rand() % br_cols;
			while (b.board[r.x][r.y].m_occupied) {
				r.x = rand() % br_rows;
				r.y = rand() % br_cols;
			}
			b.update(r.x, r.y, m_turn % 2);
			m_turn++;
			bool flag = true;
			for (int i = 0; i < br_rows; i++) {
				for (int j = 0; j < br_cols; j++) {
					if (!b.board[i][j].m_occupied) {
						flag = false;
					}
				}
			}
			if (flag) {
				gs = WScreen;
			}
		}
		
		b.draw();
	}
	if (gs == Game1pD2) {
		if (m_turn % 2 == 0) {
			place();
		}
		else {
			int2 r = b.find_most();
			cout << r.x << " " << r.y << endl;
			b.update(r.x, r.y, m_turn % 2);
			m_turn++;
			bool flag = true;
			for (int i = 0; i < br_rows; i++) {
				for (int j = 0; j < br_cols; j++) {
					if (!b.board[i][j].m_occupied) {
						flag = false;
					}
				}
			}
			if (flag) {
				gs = WScreen;
			}
		}
		b.draw();
	}
	if (gs == Game1pD3) {
		gs = Game1pD1;
	}
	if (gs == StartMenu) {
		menu.draw_all();
		if (m_flag) {
			menu.draw_diff();	
			if (m_inputManager.m_mouseIsPressed) {
				if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_easy_rect)) {
					gs = Game1pD1;
					b.init();
					m_turn = 0;
					m_flag = false;
				}
				if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_medium_rect)) {
					gs = Game1pD2;
					b.init();
					m_turn = 0;
					m_flag = false;
				}
				if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_hard_rect)) {
					gs = Game1pD3;
					b.init();
					m_turn = 0;
					m_flag = false;
				}
			}
		}
		if (m_inputManager.m_mouseIsPressed) {
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_quit_rect)) {
				m_flag = true;
			}
			if (MouseIsInRect(m_inputManager.m_mouseCoor, menu.m_2players_rect)) {
				gs = Game2p;
				b.init();
				m_turn = 0;
				m_flag = false;
			}
		}
	}
	
	m_presenter.draw();
	
}

// call destroy for all classes to prevent memory leak
void World::destroy()
{
	SDL_DestroyRenderer(m_presenter.m_main_renderer);

	SDL_DestroyWindow(m_presenter.m_main_window);

}

bool World::isRunning()
{
	return m_isRunning;
}
