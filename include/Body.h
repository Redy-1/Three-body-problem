#pragma once
#include "Engine.h"

class Body {
public:
	Body(double m, double2 p, double2 v = {0, 0});
	~Body();

	double mass;
	double2 position;
	double2 velocity;

	void update_position();
	void update_velocity(Body&);
};