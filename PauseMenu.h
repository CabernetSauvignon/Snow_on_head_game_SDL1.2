#pragma once
#include "Interface.h"

class PauseMenu: public Interface
{
protected:
	void Item();
public:
    explicit PauseMenu(SDL_Surface *const &surf);
    int KeyEvent (SDL_KeyboardEvent &event); 
    int MouseMotionEvent (SDL_MouseMotionEvent &motion);
    int MouseButtonEvent( SDL_MouseButtonEvent &button);		 
};

