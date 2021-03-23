#include "WithoutControl.h"

WithoutControl::WithoutControl(SDL_Surface *const &surf)
{
    //cache=SDL_CreateRGBSurface(SDL_HWSURFACE, surf->w/36+1, surf->h/20, 32, surf->format->Rmask, surf->format->Gmask, surf->format->Bmask, surf->format->Amask);
    cache=SDL_CreateRGBSurface(SDL_HWSURFACE, 64, 64, 32, surf->format->Rmask, surf->format->Gmask, surf->format->Bmask, surf->format->Amask);
    Draw_FillRect(cache, 0, 0, cache->w, cache->h, SDL_MapRGB(cache->format, 0, 0, 0));
    SDL_SetColorKey(cache, SDL_SRCCOLORKEY, SDL_MapRGB(cache->format, 0, 0, 0));

    dest.w = cache->w;
    dest.h = cache->h;
    dest.y = cache->h;
    dest.x = rand()%(surf->w-cache->w);
}
void WithoutControl::Show(SDL_Surface *const &surf)
{
	SDL_BlitSurface(cache, NULL, surf, &dest);
}
void WithoutControl::Move(char flag)
{
	if(flag=='d') dest.y+=speed;
}
