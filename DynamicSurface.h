#pragma once
#include "Dynamic.h"
#include "Graphics.h"

class DynamicSurface: public Graphics, public Dynamic
{
public:
	virtual void Show(SDL_Surface *const &surf)=0;
	virtual void Move(char flag)=0;
	virtual int GetW()=0;
	virtual int GetH()=0;
	inline int GetX() {return dest.x;};
	inline int GetY() {return dest.y;};
};

