#pragma once
#include <SDL.h>

class Slider {
public:
	Slider();
	~Slider();

	Drawable body, thumb;
	int max, min;
	int val;
	int* callback;
	bool deleteTextures = false;

	void init(int2 coord, SDL_Texture* bodyTexture, SDL_Texture* thumbTexture, int width, int _min, int _max, int initialValue, int* _callback, bool _deleteTextures = false);
	void update();
	void draw(bool drawValue = true);
	void destruct();
};