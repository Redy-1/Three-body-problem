#include "Body.h"
#include "World.h"

extern float deltaTime;

Body::Body(double m, double2 p, double2 v = double2(0,0))
{
	mass = m;
	position = p;
	velocity = v;
}

Body::~Body()
{
}

void Body::update_position()
{
	position += velocity * deltaTime;
}

void Body::update_velocity(Body& other)
{
	double2 dpos = other.position - position;
	double2 acc;
	acc.x = dpos.x * other.mass * gravConst / (pow(dpos.x * dpos.x + dpos.y * dpos.y, 1.5));
	acc.y = dpos.y * other.mass * gravConst / (pow(dpos.x * dpos.x + dpos.y * dpos.y, 1.5));
	velocity += acc * deltaTime;
}
