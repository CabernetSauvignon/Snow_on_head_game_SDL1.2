#pragma once
#include "DynamicSurface.h"

class WithoutControl: public DynamicSurface
{
protected:
	int speed;
public:
	explicit WithoutControl(SDL_Surface *const &surf);
    void Show(SDL_Surface *const &surf);
    void Move(char flag);
	inline int GetW() {return cache->w;}
    inline int GetH() {return cache->h;}
};

