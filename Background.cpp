#include "Background.h"

Background::Background(SDL_Surface *const &surf): Interface(surf)
{
	SDL_Surface *image=SDL_LoadBMP("background.bmp");
	SDL_BlitSurface(image, NULL, cache, NULL);
	SDL_FreeSurface(image);
}
