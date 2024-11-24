#include "NumberDrawer.h"
#include "Presenter.h"
#include <string>

NumberDrawer* NumberDrawer::m_instance = nullptr;

NumberDrawer::NumberDrawer() {}
NumberDrawer::~NumberDrawer() {}

void NumberDrawer::init() {
	for (int i = 0; i <= 9; i++) {
		std::string path = "numerals/n#.bmp";
		path[10] = i + '0';
		numerals[i] = loadTexture(path);
		SDL_QueryTexture(numerals[i], NULL, NULL, &numeralDims[i].x, &numeralDims[i].y);
	}
	decimalPoint = loadTexture("numerals/decimalPoint.bmp");
	SDL_QueryTexture(decimalPoint, NULL, NULL, &decimalPointDims.x, &decimalPointDims.y);

	m_instance = this;
}

void NumberDrawer::drawNum(std::string num, int2 pos, int height) {
	int currX = pos.x;
	for (int i = 0; i < num.size(); i++) {
		Drawable dr;
		int digit = num[i] != '.' ? num[i] - '0' : -1;

		int2 dims = digit != -1 ? numeralDims[digit] : decimalPointDims;
		double mul = (double)height / (double)dims.y;
		dr.rect.x = currX;
		dr.rect.y = pos.y;
		dr.rect.w = (int)(dims.x * mul);
		dr.rect.h = (int)(dims.y * mul);
		dr.texture = digit != -1 ? numerals[digit] : decimalPoint;
		drawObject(dr);
		currX += dr.rect.w;
	}
}

void NumberDrawer::destruct() {
	for (int i = 0; i <= 9; i++) {
		SDL_DestroyTexture(numerals[i]);
	}
	SDL_DestroyTexture(decimalPoint);
}