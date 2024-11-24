#include "Body.h"

Body::Body(double m, 
	double2 p, 
	double2 v = {0, 0}) {
	mass = m;
	position = p;
	velocity = v;
}

Body::~Body()
{
}

void Body::update_position()
{
}

void Body::update_velocity()
{
}
