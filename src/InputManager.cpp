#include "InputManager.h"


InputManager::InputManager()
{
    m_scroll = 0;
}

InputManager::~InputManager()
{
   // delete m_keyboardState;
}

void InputManager::setMouseMultiply(float2 multiplier)
{
    m_mouseMultiply.x = multiplier.x;
    m_mouseMultiply.y = multiplier.y;
}

void InputManager::init(string path)
{
    path = CONFIG_FOLDER + path;

    fstream stream;
    string tmp;
}

void InputManager::handleInput()
{
    m_mouseIsPressed = false;
    m_mouseIsDoubleClicked = false;
    m_mouseIsRightPressed = false;

    while (SDL_PollEvent(&m_event))
    {
        switch (m_event.type)
        {
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&(m_mouseCoor.x), &(m_mouseCoor.y));

            m_mouseCoor.x *= m_mouseMultiply.x;
            m_mouseCoor.y *= m_mouseMultiply.y;

            break;
        case SDL_MOUSEBUTTONDOWN:
            if (m_event.button.button == SDL_BUTTON_LEFT)
            {
                m_mouseIsPressed = true;
            }

            if (m_event.button.button == SDL_BUTTON_RIGHT)
            {
                m_mouseIsRightPressed = true;
            }

            break;
        case SDL_MOUSEBUTTONUP:
            if (m_event.button.button == SDL_BUTTON_LEFT) {
                m_mouseIsHolded = false;
            }
            break;
        case SDL_TEXTINPUT:

            
            break;
        case SDL_KEYDOWN:
            
            break;
        }
    }

    SDL_StartTextInput();

    m_keyboardState = SDL_GetKeyboardState(NULL);

    m_scroll = 0;

    switch (m_event.wheel.type)
    {
    case SDL_MOUSEWHEEL:
        m_scroll = m_event.wheel.y;
        break;

    default:
        break;
    }

    m_event.wheel = SDL_MouseWheelEvent();

    if (m_mouseIsPressed)
    {
        if (!m_mouseIsPressedPrevFrame)
        {
            m_mouseOnClick = true;
        }
        else
        {
            m_mouseOnClick = false;
        }

        m_mouseIsHolded = true;
    }
    else
    {
        m_mouseIsPressedPrevFrame = false;
        m_mouseOnClick = false;
    }

}

bool InputManager::anyKeyIsPressed()
{
    int numOfKeys = 322;

    for (int i = 0; i < numOfKeys; i++)
    {
        if (m_keyboardState[i])
        {
            return true;
        }
    }
    return false;
}
