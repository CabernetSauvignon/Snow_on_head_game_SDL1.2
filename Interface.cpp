#include "Interface.h"

Interface::Interface(SDL_Surface *const &surf): text(NULL), menu(0) 
{
	cache=SDL_CreateRGBSurface(SDL_HWSURFACE, surf->w, surf->h, 32, surf->format->Rmask, surf->format->Gmask, surf->format->Bmask, surf->format->Amask);
	Draw_FillRect(cache, 0, 0, cache->w, cache->h, 0x000000);
	SDL_SetColorKey(cache, SDL_SRCCOLORKEY, 0x000000);
	titlefont=TTF_OpenFont("Magic.ttf", (cache->h*cache->w)/13824);
	textfont=TTF_OpenFont("Pencil Regular.ttf", (cache->h*cache->w)/34560);
	helpfont=TTF_OpenFont("Pencil Regular.ttf", (cache->h*cache->w)/41472);
	menufont=TTF_OpenFont("menu.ttf", (cache->h*cache->w)/41472);
	recordfont=TTF_OpenFont("Pencil Regular.ttf", (cache->h*cache->w)/62000/*51840*/);
	
	DefaultColorText.r=234; DefaultColorText.g=178; DefaultColorText.b=23;
	SelectedColorText.r=1; SelectedColorText.g=245; SelectedColorText.b=249;
}

void Interface::Show(SDL_Surface *const &surf)
{
	SDL_BlitSurface(cache, NULL, surf, NULL);
}

Interface::~Interface()
{
	TTF_CloseFont(helpfont);
	TTF_CloseFont(textfont);
	TTF_CloseFont(titlefont);
	TTF_CloseFont(menufont);
	TTF_CloseFont(recordfont);
	text=NULL;
}
