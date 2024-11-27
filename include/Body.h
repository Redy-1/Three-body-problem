#pragma once
#include "Engine.h"

class Body {
public:
	~Body();

	double mass = 0;
	double2 position = { 0, 0 };
	double2 velocity = { 0, 0 };
	double2 acc = { 0, 0 };

	Uint8 cr = 100, cg = 100, cb = 100;

	SDL_Texture* txt;

	void update_position();
	void update_velocity(Body& other);

	void draw(int r = -1);
};