#include "Intro.h"

Intro::Intro(SDL_Surface *const &surf): Interface(surf)
{
	SDL_Surface *intro=IMG_Load("lyod2.png");
	dest.x=400; dest.y=0; dest.w=1120; dest.h=1080;
	SDL_BlitSurface(intro, NULL, cache, &dest);
	SDL_FreeSurface(intro);
	
	/*çàãîëîâîê*/
    text = TTF_RenderUTF8_Solid(titlefont, "Snow on head", DefaultColorText);
    dest.x = (cache->w - text->w)/2; dest.y=cache->h/3;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    /*èìÿ ÑÎÇÄÀÒÅËß!!!*/
    text = TTF_RenderUTF8_Solid(textfont, "Morozov K.I.,  I584", DefaultColorText);
    dest.x = (cache->w - text->w)/2; dest.y=(cache->h/2+200);
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
    
    /*ïîìîùü*/
    text = TTF_RenderUTF8_Solid(helpfont,"Press any key to continue..." , DefaultColorText);
    dest.x = (cache->w - text->w)/2; dest.y = cache->h-text->h-200;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
    
}
