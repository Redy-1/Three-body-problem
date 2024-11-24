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

struct int2
{
    int x = 0;
    int y = 0;
};

struct float2
{
    float x = 0;
    float y = 0;
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
