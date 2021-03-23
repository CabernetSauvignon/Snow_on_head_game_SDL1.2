#include "Graphics.h"

Graphics::Graphics(): cache(NULL)
{
	dest.x=0; dest.y=0;
	dest.w=0; dest.h=0;
}

Graphics::~Graphics()
{
	if(cache) SDL_FreeSurface(cache);
}
