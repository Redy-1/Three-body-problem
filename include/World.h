#pragma once

#include "Presenter.h"
#include "InputManager.h"
#include "Body.h"
#include "NumberDrawer.h"

class World
{
public:
	World();
	~World();

	Presenter m_presenter;
	InputManager m_inputManager;
	NumberDrawer m_numberDrawer;
	
	void init();
	void run();
	void destroy();

private:
	vector<Body> bodies;
};