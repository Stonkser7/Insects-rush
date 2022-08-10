#ifndef MENU_STATE_BASE_H
#define MENU_STATE_BASE_H

#include "Menu.h"


//base MenuState class
class MenuStateBase
{
public:
	virtual MenuStateBase* processInputs(Menu&, Game&) = 0;
	virtual void update(Menu&, Game&) = 0;
	virtual void render(Menu&, Game&) = 0;
};

#endif