#pragma once
#include "Interface.h"

class GameOver: public Interface
{
public:
	explicit GameOver(SDL_Surface *const &surf);
    void Show(SDL_Surface *const &surf, Uint16 *const &playerName, double time);
};

