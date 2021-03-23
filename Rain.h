#pragma once
#include "WithoutControl.h"

class Rain: public WithoutControl
{
public:
	explicit Rain(SDL_Surface *const &surf, const int &speed=0);
    void SetStatus(SDL_Surface *const &surf, const int &newSpeed);
};

