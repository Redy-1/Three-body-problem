#include "World.h"
#include <time.h>

float deltaTime;

World::World()
{
}

World::~World()
{
}


Uint64 currentTime = 0;
Uint64 lastTime = 0;

void World::init()
{
	currentTime = SDL_GetPerformanceCounter();
	lastTime = SDL_GetPerformanceCounter();

	background_rect.x = 0;
	background_rect.y = 0;
	background_rect.x = screen_w;
	background_rect.y = screen_h;
	
	m_presenter.init();

	m_numberDrawer.init();
}



void World::run()
{
	lastTime = currentTime;
	currentTime = SDL_GetPerformanceCounter();
	deltaTime = (float)((currentTime - lastTime) * 1000.0f / (float)SDL_GetPerformanceFrequency());
	deltaTime /= 16.0f; /// TODO: config


	m_inputManager.handleInput();

	for (int i = 0; i < bodies.size(); i++) {
		for (int j = 0; j < bodies.size(); j++) {
			if (i != j) bodies[i].update_velocity(bodies[j]);
		}
	}

	for (int i = 0; i < bodies.size(); i++) {
		bodies[i].update_position();
	}
	
	//drawObject(background_texture);

	m_numberDrawer.drawNum("123.567.2", { 200, 200 }, 50);

	m_presenter.draw();

}

// call destroy for all classes to prevent memory leak
void World::destroy() {
	m_numberDrawer.destruct();

	SDL_DestroyRenderer(m_presenter.m_main_renderer);

	SDL_DestroyWindow(m_presenter.m_main_window);
}

