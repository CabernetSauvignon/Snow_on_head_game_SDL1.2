#pragma once
#include "Interface.h"

class Rules: public Interface
{
public:
	explicit Rules(SDL_Surface *const &surf);
    int KeyEvent(SDL_KeyboardEvent &event);
    int MouseButtonEvent(SDL_MouseButtonEvent &button);
};

