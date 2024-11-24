#pragma once
#include "Engine.h"

class Body {
public:
	Body(double, double2, double2 = { 0,0 }, Uint8 = 0, Uint8 = 0, Uint8 = 0);
	~Body();

	double mass;
	double2 position;
	double2 velocity;

	SDL_Texture* txt;

	void update_position();
	void update_velocity(Body&);

	void setColor(Uint8, Uint8, Uint8);
	void draw(int = 50);
};