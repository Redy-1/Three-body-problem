#include "World.h"
#include <time.h>

double deltaTime;

World::World()
{
}

World::~World()
{
}

int fps = 60;
Uint64 currentTime = 0;
Uint64 lastTime = 0;
Uint64 frameTime;

void World::init()
{
	lastTime = SDL_GetPerformanceCounter();
	SDL_Delay(1000 / fps);
	currentTime = SDL_GetPerformanceCounter();
	deltaTime = 1. / fps;
	frameTime = SDL_GetPerformanceFrequency() / fps;

	background_rect.x = 0;
	background_rect.y = 0;
	background_rect.x = screen_w;
	background_rect.y = screen_h;

	m_presenter.init();

	m_numberDrawer.init();

	bodies.push_back(Body(1, { 900,500 }, { 0,50 }, 255, 255, 0));
	bodies.push_back(Body(1, { 1000,500 }, { 0,0 }, 255, 0, 0));
	bodies.push_back(Body(1, { 1100,500 }, { 0,-50 }, 0, 255, 255));
}



void World::run()
{ 
	currentTime = SDL_GetPerformanceCounter();
	lastTime = currentTime - frameTime;
	cout << deltaTime << endl;
	m_inputManager.handleInput();

	for (int i = 0; i < bodies.size(); i++) {
		for (int j = 0; j < bodies.size(); j++) {
			if (i != j) bodies[i].update_velocity(bodies[j]);
		}
	}

	for (int i = 0; i < bodies.size(); i++) {
		bodies[i].update_position();
		// printf("%f %f\n", bodies[i].position.x, bodies[i].position.y);
	}
	std::cout << "---\n";
	
	drawObject(background_texture);

	for (auto b : bodies) { b.draw(); }

	m_presenter.draw();

	
	Uint64 cTime = SDL_GetPerformanceCounter();
	int64_t delay = ((int64_t)currentTime + (int64_t)frameTime - (int64_t)cTime) * 1000 / (int64_t)SDL_GetPerformanceFrequency();
	if (delay > 0) {
		SDL_Delay(delay);
	}
	
}

// call destroy for all classes to prevent memory leak
void World::destroy() {
	m_numberDrawer.destruct();

	SDL_DestroyRenderer(m_presenter.m_main_renderer);

	SDL_DestroyWindow(m_presenter.m_main_window);
}

