#include "Body.h"
#include "World.h"

extern float deltaTime;
extern World world;

Body::Body(double m, double2 p, double2 v, Uint8 cr, Uint8 cg, Uint8 cb) {
	mass = m;
	position = p;
	velocity = v;
	txt = loadTexture("circle.bmp");
	setColor(cr, cg, cb);
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
void Body::setColor(Uint8 cr, Uint8 cg, Uint8 cb) {
	SDL_SetTextureColorMod(txt, cr, cg, cb);
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
	rect = { (float)position.x - r,(float)position.y - r, (float)r, (float)r };

	SDL_RenderCopyF(Presenter::m_main_renderer, texture, NULL, &rect);
}
