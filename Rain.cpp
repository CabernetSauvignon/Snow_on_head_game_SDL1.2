#include "Rain.h"
#include <ctime>

Rain::Rain(SDL_Surface *const &surf, const int &speed): WithoutControl(surf)
{
	SetStatus(surf, speed);
}
void Rain::SetStatus(SDL_Surface *const &surf, const int &newSpeed)
{
	dest.y=0;
    dest.x=rand()%(surf->w-cache->w);
    speed=newSpeed;
    SDL_Surface *image=IMG_Load("snowball.png");
	SDL_BlitSurface(image, NULL, cache, NULL);
	SDL_FreeSurface(image);
}
