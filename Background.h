#pragma once
#include "Interface.h"

class Background: public Interface
{
public:
	explicit Background(SDL_Surface *const &surf);
};

