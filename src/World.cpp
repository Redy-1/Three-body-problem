#include "World.h"
#include <time.h>

World::World()
{
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
	
	background_texture = loadTexture("better_background.bmp");
	
	m_presenter.init();
}



void World::run()
{
	m_inputManager.handleInput();
	drawObject(background_texture);
	
	m_presenter.draw();
	
}

// call destroy for all classes to prevent memory leak
void World::destroy()
{
	SDL_DestroyRenderer(m_presenter.m_main_renderer);

	SDL_DestroyWindow(m_presenter.m_main_window);

}

