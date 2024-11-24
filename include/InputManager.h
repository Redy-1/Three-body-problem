#pragma once

#include <utility>

#include <SDL.h>
#include <fstream>
#include <string>

#include "defines.h"
#include "Engine.h"

class InputManager
{
public:
    InputManager();
    ~InputManager();

    bool m_mouseIsPressed;
    bool m_mouseIsDoubleClicked;
    // mouse is being pressed for first time
    bool m_mouseOnClick;
    bool m_mouseOnRelease;
    bool m_mouseIsPressedPrevFrame;
    bool m_mouseIsHolded;
    bool m_mouseIsRightPressed;

    int2 m_inputDirection;

    int2 m_mouseCoor;

    const Uint8* m_keyboardState;

    int m_scroll;

    void handleInput(); //< call the SDL_PollEvent fnc and update all variables
    void setMouseMultiply(float2 multiplier); //< multiply the mouseCoor corespondingly to the screen resolution

    void init(string path); //< read the pre-set controlls in a configFile 

    bool anyKeyIsPressed();

private:
    SDL_Event m_event;

    float2 m_mouseMultiply;

    int2* m_playerScreenPos;

    int2 m_screenCenter;
    int2 m_direction;
};