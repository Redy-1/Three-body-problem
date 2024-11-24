#pragma once
#include "Engine.h"

class Body {
public:
	Body(double m, double2 p, double2  v = { 0,0 }, Uint8 cr = 0, Uint8 cg = 0, Uint8 cb = 0);
	~Body();

	double mass;
	double2 position;
	double2 velocity;

	SDL_Texture* txt;

	void update_position();
	void update_velocity(Body& other);

	void setColor(Uint8 cr, Uint8 cg, Uint8 cb);
	void draw(int r = -1);
};