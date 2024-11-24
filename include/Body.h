#pragma once
#include "Engine.h"

class Body {
public:
	Body(double,double2,double2);
	~Body();

	double mass;
	double2 position;
	double2 velocity;

	static SDL_Texture* txt;

	void update_position();
	void update_velocity(Body&);

	void draw(int r = 50);
};