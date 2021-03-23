#include "People.h"

People::People(SDL_Surface *const &surf): Control(surf)
{
	SDL_Surface *image=IMG_Load("snowman.png");
	SDL_BlitSurface(image, NULL, cache, NULL);
	SDL_FreeSurface(image);
}
