#pragma once
#include "Interface.h"

class Player: public Interface
{
protected:
	Uint16 *name;
protected: 
    void ChangeName();
public:
	Player(SDL_Surface *const &surf, Uint16 *const &playername);
	int KeyEvent (SDL_KeyboardEvent &event);  /*Нажатие клавиш*/
};

