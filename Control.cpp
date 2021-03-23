#include "Control.h"

Control::Control(SDL_Surface *const &surf): key(0)
{
    cache = SDL_CreateRGBSurface(SDL_HWSURFACE, 155, 250, 32, surf->format->Rmask, surf->format->Gmask, surf->format->Bmask, surf->format->Amask);

    Draw_FillRect(cache, 0, 0, cache->w, cache->h, SDL_MapRGB(cache->format, 75, 75, 75));
    SDL_SetColorKey(cache , SDL_SRCCOLORKEY, SDL_MapRGB(cache->format, 75, 75, 75));

    dest.w=cache->w;
    dest.h=cache->h;
    dest.y=surf->h-cache->h-surf->h/20;
    dest.x=0;
}
void Control::Show(SDL_Surface *const &surf)
{
	Move(key);
	if(dest.x>(surf->w-cache->w)) dest.x=(surf->w-cache->w);
    else if(dest.x < 0) dest.x = 0;
    SDL_BlitSurface(cache, NULL, surf, &dest);
}
void Control::Reset()
{
	dest.x=0;
    key=0;
}
void Control::Move(char flag)
{
	if (flag == 'r') dest.x+= 20;
    if (flag == 'l') dest.x-= 20;
}
int Control::KeyEvent(SDL_KeyboardEvent &event)
{
	if (event.type == SDL_KEYDOWN) 
	{          
        if (event.keysym.sym == SDLK_LEFT || event.keysym.sym == SDLK_a) 
            key ='l';
		if (event.keysym.sym == SDLK_RIGHT || event.keysym.sym == SDLK_d) 
            key ='r';
        return 1;
    }
    else if (event.type == SDL_KEYUP )        
        if (event.keysym.sym == SDLK_LEFT || event.keysym.sym == SDLK_RIGHT || event.keysym.sym == SDLK_a || event.keysym.sym == SDLK_d)
            key = 0;
    return 0;
}
