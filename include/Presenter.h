#pragma once 

#include <iomanip>

#include <SDL_TTF.h>

#include "Engine.h"

using namespace std;

class Presenter
{
public:
	static SDL_Window* m_main_window;
	static SDL_Renderer* m_main_renderer;

	static unsigned int m_SCREEN_WIDTH;
	static unsigned int m_SCREEN_HEIGHT;

	void init();
	void update();
	void draw();

	SDL_Renderer* getRenderer();

	static void drawObject(SDL_Texture* texture);
	static void drawObject(Drawable& drawable);


private:
	int2 screenCenter;

	void improveRenderer();
};

namespace
{
	template <typename T>
	void drawObject(T& t)
	{
		Presenter::drawObject(t);
	}  

	SDL_Texture* loadTexture(string path)
	{
		return LoadTexture(path, Presenter::m_main_renderer);
	}
}