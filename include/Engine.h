#pragma once

#include <cmath>
#include <string>
#include <float.h>
#include <utility>

#include <SDL.h>
#include <SDL_TTF.h>

#include "defines.h"

SDL_Texture* LoadTexture(string configFile, SDL_Renderer* renderer);
bool MouseIsInRect(int2 coor, SDL_Rect rect);
bool collRectRect(SDL_Rect a, SDL_Rect b);
bool checkInOffBounds(SDL_Rect rect, int screenWidth, int screenHeight);
int rangeMap(int from_low, int from_high, int to_low, int to_high, int val);
bool coordInRect(int2 coor, SDL_Rect rect);