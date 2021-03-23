#pragma once
#include <cmath>
#include "SDL.h"
#include "SDL_draw.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

using namespace std;

/* ����������� ������� �������� */ 
class Graphics
{
protected:
	SDL_Rect dest;   /* ���������� */
	SDL_Surface* cache;   /* ����������� */
public:
	Graphics();
	~Graphics();
	virtual void Show(SDL_Surface *const &surf)=0;   /* ����������� */	
};

