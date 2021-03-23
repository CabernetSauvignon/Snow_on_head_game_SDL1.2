#pragma once
#include "Interface.h"

class MainMenu: public Interface
{
protected:
	void item();
public:
    explicit MainMenu(SDL_Surface *const &surf);
	void Show(SDL_Surface *const &surf, Uint16 *const &playerName);
    int KeyEvent(SDL_KeyboardEvent &event); 
    int MouseMotionEvent(SDL_MouseMotionEvent &motion); 
    int MouseButtonEvent(SDL_MouseButtonEvent &button);
};

