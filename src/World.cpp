#include "World.h"
#include <time.h>
#include <format>
#include <numbers>

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

//	bodies.push_back(Body(1, { 500/1000.0,500 /1000.0}, { 0,50 / 1000.0 }, 255, 255, 0));
//	/bodies.push_back(Body(1, { 1000/1000.0,500/1000.0 }, { 0,0 / 1000.0 }, 255, 0, 0));
//	bodies.push_back(Body(1, { 1500/1000.0,500/1000.0 }, { 0,-50 / 1000.0 }, 0, 255, 255));

	bodies = { 
		{ 1.0, { 0.8, 0.5 }, { 0, 0.11 }, { 0, 0 }, 255, 255, 0, loadTexture("circle.bmp") },
		{ 100.0, { 1.0, 0.5 }, { 0, 0.0 }, { 0, 0 }, 255, 0, 0, loadTexture("circle.bmp") },
		{ 1.0, { 1.2, 0.5 }, { 0, -0.09 }, { 0, 0 }, 0, 255, 255, loadTexture("circle.bmp") },
	};
}



void World::run()
{ 
	currentTime = SDL_GetPerformanceCounter();
	lastTime = currentTime - frameTime;
	//cout << deltaTime << endl;
  	m_inputManager.handleInput();
/*
	for (auto& body : bodies)
	{
		body.acc = { 0.0, 0.0 };
	}

	for (int i = 0; i < bodies.size(); i++) {
		for (int j = 0; j < bodies.size(); j++) {
			cout << i << " " << j << " ";
			if (i != j) bodies[i].update_velocity(bodies[j]);
			cout << "\n";
		}
	}

	for (int i = 0; i < bodies.size(); i++) {
		cout << std::format("UPDATED {} ", i);
		bodies[i].update_position(); 
		cout << "\n";
//		cout << bodies[i].velocity.x << " " << bodies[i].velocity.y<<endl;
		// printf("%f %f\n", bodies[i].position.x, bodies[i].position.y);
	}

	std::cout << "---\n";
*/

	vector<Body> new_bodies;
	new_bodies.resize(bodies.size());

	for (int i = 0; i < bodies.size(); i++)
	{
		new_bodies[i] = bodies[i];
		new_bodies[i].position = bodies[i].position + bodies[i].velocity * deltaTime + bodies[i].acc * deltaTime * deltaTime / 2;
		double2 acc = { 0, 0 };
		for (int j = 0; j < bodies.size(); j++)
		{
			if (i != j)
			{
				double2 offset = bodies[j].position - bodies[i].position;
				double distance = hypot(offset.x, offset.y);
				double distance3 = distance * distance * distance;
				double force = bodies[j].mass * gravConst / distance3;
				acc.x += force * offset.x;
				acc.y += force * offset.y;
			}
		}

		new_bodies[i].acc = acc;
		new_bodies[i].velocity = bodies[i].velocity + (bodies[i].acc + new_bodies[i].acc) * deltaTime / 2;
	}

	swap(bodies, new_bodies);

	drawObject(background_texture);

	for (auto b : bodies) { b.draw(); }

	m_presenter.draw();

	
	Uint64 cTime = SDL_GetPerformanceCounter();
	int64_t delay = ((int64_t)currentTime + (int64_t)frameTime - (int64_t)cTime) * 1000 / (int64_t)SDL_GetPerformanceFrequency();
	//cout << deltaTime << endl;
	//cout << delay << endl;

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

