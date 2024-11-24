#include "Presenter.h"
#include "Slider.h"
#include "Engine.h"
#include "World.h"

extern World world;

Slider::Slider() {}
Slider::~Slider() {}

void Slider::init(int2 coord, SDL_Texture* bodyTexture, SDL_Texture* thumbTexture, int width, int _min, int _max, int initialValue, int* _callback, bool _deleteTextures){
	body.rect.x = coord.x;
	body.rect.y = coord.y;
	body.rect.w = width;
	body.rect.h = 30;
	body.texture = bodyTexture;
	thumb.texture = thumbTexture;
	min = _min;
	max = _max;
	val = initialValue;
	callback = _callback;
	deleteTextures = _deleteTextures;
}

void Slider::update() {
	thumb.rect.w = 15;
	thumb.rect.h = 40;
	thumb.rect.x = rangeMap(min, max, body.rect.x + thumb.rect.w / 2, body.rect.x + body.rect.w - thumb.rect.w - thumb.rect.w/2, val);
	thumb.rect.y = body.rect.y - (thumb.rect.h - body.rect.h) / 2;

	if (world.m_inputManager.m_mouseIsHolded && coordInRect(world.m_inputManager.m_mouseCoor, body.rect)) {
		val = rangeMap(
			body.rect.x + thumb.rect.w,
			body.rect.x + body.rect.w - thumb.rect.w,
			min,
			max,
			world.m_inputManager.m_mouseCoor.x
		);
		if (val < min) { val = min; }
		else if (val > max) { val = max; }
	}

	if (callback) { *callback = val; }
}

void Slider::draw(bool drawValue) {
	drawObject(body);
	drawObject(thumb);

	if (drawValue) {
		drawNum(to_string(val), { body.rect.x + body.rect.w + 20, body.rect.y-1 }, 32);
	}
}

void Slider::destruct() {
	if (deleteTextures) {
		SDL_DestroyTexture(body.texture);
		SDL_DestroyTexture(thumb.texture);
	}
}