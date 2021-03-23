#pragma once
#include <cmath>
#include "SDL.h"
#include "SDL_draw.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

using namespace std;

/* Графические видимые элементы */ 
class Graphics
{
protected:
	SDL_Rect dest;   /* Координаты */
	SDL_Surface* cache;   /* Поверхность */
public:
	Graphics();
	~Graphics();
	virtual void Show(SDL_Surface *const &surf)=0;   /* Отображение */	
};

