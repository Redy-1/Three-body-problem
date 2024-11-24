#pragma once

#include <iostream>
#include <string>

#include <vector>
#include <SDL.h>

using namespace std;

#define D(x) cerr << #x << " = " << (x) << " | " << __LINE__ << endl;
#define Dex(x) cerr << #x << " = " << (x) << " | " << __LINE__ << " " << __FILE__ << endl;
#define __FILE_NAME__ (strrchr(__FILE__, '\\' ) ? strrchr(__FILE__, '\\') + 1 : __FILE__)

static string MENU_FOLDER = "menu\\";
static string MAIN_FOLDER = "main\\";
static string IMG_FOLDER = "img\\";
static string CONFIG_FOLDER = "config\\";
static string FONT_FOLDER = "ttf\\";
static string SOUND_FOLDER = "music\\";
static string TITLE_SCREEN_FOLDER = "titleScreen\\";
static string WIN_SCREEN_FOLDER = "winScreen\\";
static string GAME_FOLDER = "game\\";


const int offset_y = 30;

const int screen_w = 1920;
const int screen_h = 1080;

const int br_rows = 8;
const int br_cols = 8;

const int tile_w = (screen_h - 2 * offset_y) / br_cols;
const int tile_h = (screen_h - 2 * offset_y) / br_cols;

const int offset_x = (screen_w-tile_w*br_cols)/2;\

static SDL_Rect background_rect;
static SDL_Texture* background_texture;

typedef Uint32 Time;

static double gravConst = 500;

struct int2 {
	int x = 0, y = 0;

	void reset() { x = 0; y = 0; };
	void set(int2 b) { x = b.x; y = b.y; };
	void operator+=(int2 a) { x += a.x; y += a.y; };
	void operator-=(int2 a) { x -= a.x; y -= a.y; };
	void operator*=(int2 a) { x *= a.x; y *= a.y; };
	void operator/=(int2 a) { x /= a.x; y /= a.y; };
	int2 operator+(int2 a) const { return { x + a.x, y + a.y }; };
	int2 operator-(int2 a) const { return { x - a.x, y - a.y }; };
	int2 operator*(int2 a) const { return { x * a.x, y * a.y }; };
	int2 operator/(int2 a) const { return { x / a.x, y / a.y }; };
	int2 operator*(int a) const { return { x * a , y * a }; };
	int2 operator/(int a) const { return { x / a , y / a }; };
	int2 operator-() const { return { -x, -y }; };
	bool operator==(int2 a) const { return (x == a.x && y == a.y); };
	bool operator!=(int2 a) const { return (x != a.x || y != a.y); };
};

struct float2 {
	float x = 0, y = 0;

	void reset() { x = 0; y = 0; };
	void set(float2 b) { x = b.x; y = b.y; };
	void operator+=(float2 a) { x += a.x; y += a.y; };
	void operator-=(float2 a) { x -= a.x; y -= a.y; };
	void operator*=(float2 a) { x *= a.x; y *= a.y; };
	void operator/=(float2 a) { x /= a.x; y /= a.y; };
	float2 operator+(float2 a) const { return { x + a.x, y + a.y }; };
	float2 operator-(float2 a) const { return { x - a.x, y - a.y }; };
	float2 operator*(float2 a) const { return { x * a.x, y * a.y }; };
	float2 operator/(float2 a) const { return { x / a.x, y / a.y }; };
	float2 operator*(float a) const { return { x * a , y * a }; };
	float2 operator/(float a) const { return { x / a , y / a }; };
	float2 operator-() const { return { -x, -y }; };
	bool operator==(float2 a) const { return (x == a.x && y == a.y); };
	bool operator!=(float2 a) const { return (x != a.x || y != a.y); };
};

struct double2 {
	double2() {};
	double2(double x1, double y1) {
		x = x1;
		y = y1;
	}
	double x = 0, y = 0;

	void reset() { x = 0; y = 0; };
	void set(double2 b) { x = b.x; y = b.y; };
	void operator+=(double2 a) { x += a.x; y += a.y; };
	void operator-=(double2 a) { x -= a.x; y -= a.y; };
	void operator*=(double2 a) { x *= a.x; y *= a.y; };
	void operator/=(double2 a) { x /= a.x; y /= a.y; };
	double2 operator+(double2 a) const { return { x + a.x, y + a.y }; };
	double2 operator-(double2 a) const { return { x - a.x, y - a.y }; };
	double2 operator*(double2 a) const { return { x * a.x, y * a.y }; };
	double2 operator/(double2 a) const { return { x / a.x, y / a.y }; };
	double2 operator*(double a) const { return { x * a , y * a }; };
	double2 operator/(double a) const { return { x / a , y / a }; };
	double2 operator-() const { return { -x, -y }; };
	bool operator==(double2 a) const { return (x == a.x && y == a.y); };
	bool operator!=(double2 a) const { return (x != a.x || y != a.y); };
};

enum class SOUND
{
    NONE = 0,
    BACKGROUND = 1
};

enum GameState
{
    StartMenu = 0,
    Game1pD1 = 1,
    Game1pD2 = 2,
    Game1pD3 = 3,
    Game2p = 4,
    WScreen = 5

};

struct Drawable
{
    SDL_Texture* texture = nullptr;
    SDL_Rect rect = { 0 }; /// The rect where we draw
};
