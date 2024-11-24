#pragma once

#include "Presenter.h"
#include "InputManager.h"
#include "Body.h"

class World
{
public:
	World();
	~World();

	Presenter m_presenter;
	InputManager m_inputManager;
	
	void init();
	void run();
	void destroy();

private:
	vector<Body> bodies;
};