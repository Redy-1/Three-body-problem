#include "Body.h"
#include "World.h"
#include <format>

extern double deltaTime;
extern World world;
/*
Body::Body(double m, double2 p, double2 v, Uint8 cr, Uint8 cg, Uint8 cb) {
	mass = m;
	position = p;
	velocity = v;
	acc = { 0.0, 0.0 };
	txt = loadTexture("circle.bmp");
}*/

Body::~Body()
{
}

void Body::update_position()
{
	velocity += acc * deltaTime * gravConst;
	position += velocity * deltaTime;

	cout << std::format("acc {}:{} ", acc.x, acc.y);
	cout << std::format("vel {}:{} ", velocity.x, velocity.y);
	cout << std::format("pos {}:{} ", position.x, position.y);
}

void Body::update_velocity(Body& other)
{
	double2 dpos = other.position - position;
	double distance = hypot(dpos.x, dpos.y);
	double distance3 = distance * distance * distance;
	cout << std::format("distance {} ", distance);

	acc.x += dpos.x * other.mass / distance3;
	acc.y += dpos.y * other.mass / distance3;

	cout << std::format("acc {}:{} ", acc.x, acc.y);
}
void Body::draw(int r) {
	if (r == -1) { r = (double) sqrt(mass) * 30.0; }
	//Drawable dr;
	//dr.texture = txt;
	//dr.rect = { int(position.x) - r,int(position.y) - r,r,r };
	//world.m_presenter.drawObject(dr);
	SDL_FRect rect;
	SDL_Texture* texture;
	texture = txt;
	rect = { (float)position.x - r,(float)position.y  - r, (float)r, (float)r };
	
	SDL_SetTextureColorMod(txt, cr, cg, cb);
	SDL_RenderCopyF(Presenter::m_main_renderer, texture, NULL, &rect);
}
