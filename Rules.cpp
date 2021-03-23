#include "Rules.h"

Rules::Rules(SDL_Surface *const &surf): Interface(surf)
{
	Draw_FillRect(cache, cache->w/5, cache->h*2/7, cache->w-(cache->w*2/5), cache->h/2, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Rect(cache, cache->w/5-i, cache->h*2/7-i, cache->w-(cache->w*2/5)+2*i, cache->h/2+2*i, SDL_MapRGB(cache->format, 234, 178, 23));
    }
	
	text=TTF_RenderUTF8_Solid(titlefont, "RULES", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y=cache->h/9;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
	
	text=TTF_RenderUTF8_Solid(textfont, "Beware of hail!", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y=cache->h/3;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text=TTF_RenderUTF8_Solid(textfont, "One heat, and you lost", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y+=cache->h/9;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text=TTF_RenderUTF8_Solid(textfont, "Snowman controls by keyboard arrows", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y+=cache->h/9;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text=TTF_RenderUTF8_Solid(textfont, "Hold on as long as possible", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y+=cache->h/9;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
    
    text = TTF_RenderUTF8_Solid(helpfont, "TIP: Press 'Enter' or mouse button to continue...", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y=cache->h-text->h-(cache->h/20);
    Draw_FillRect(cache, cache->w/10, dest.y-cache->h/54, cache->w-(cache->w/5), text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Rect(cache, cache->w/10-i, dest.y-cache->h/54-i, cache->w-(cache->w/5)+2*i, text->h+cache->h/54+2*i, SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
}
int Rules::KeyEvent(SDL_KeyboardEvent &event)
{
	if(event.type==SDL_KEYDOWN)
        if(event.keysym.sym==SDLK_RETURN) return 0;
    return -1;
}
int Rules::MouseButtonEvent(SDL_MouseButtonEvent & button)
{
	if(button.type == SDL_MOUSEBUTTONDOWN) return 0;
    return -1;
}
