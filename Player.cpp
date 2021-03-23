#include "Player.h"

Player::Player(SDL_Surface *const &surf, Uint16 *const &PlayerName): Interface(surf), name(PlayerName)
{
	text=TTF_RenderUTF8_Solid(textfont, "What is the name", DefaultColorText);
    dest.x = (cache->w-text->w)/2; dest.y = cache->h/4;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text = TTF_RenderUTF8_Solid(textfont, "of the new player?", DefaultColorText);
    dest.x = (cache->w-text->w)/2; dest.y+=cache->h/9;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
	
	ChangeName();
	
	text=TTF_RenderUTF8_Solid(helpfont, "TIP: Write a name and click 'Enter' or mouse button", DefaultColorText);
    dest.x = (cache->w-text->w)/2; dest.y =cache->h-text->h-(cache->h/20);
    Draw_FillRect(cache, cache->w/10, dest.y-cache->h/54, cache->w-(cache->w/5), text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Rect(cache, cache->w/10-i, dest.y-cache->h/54-i, cache->w-(cache->w/5)+2*i, text->h+cache->h/54+2*i, SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
	
}

void Player::ChangeName()
{
	Uint16 x0=(cache->w*3/10);
    Uint16 y0 = cache->h*5/9;
    Uint16 xWidth =(cache->w*4/11);
    Uint16 yHeight = cache->h/10;
    
    Draw_FillCircle(cache, x0, y0+yHeight/2, yHeight/2, SDL_MapRGB(cache->format, 255, 0, 0));
    Draw_FillCircle(cache, x0+xWidth, y0+yHeight/2, yHeight/2, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Circle(cache, x0, y0+yHeight/2, yHeight/2-i, SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_Circle(cache, x0+xWidth, y0+yHeight/2, yHeight/2-i, SDL_MapRGB(cache->format, 234, 178, 23));
    }
    Draw_FillRect(cache, x0, y0, xWidth, yHeight, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_HLine(cache, x0, y0+i, x0+xWidth, SDL_MapRGB(cache->format, 234, 178, 23));
    	Draw_HLine(cache, x0, y0+yHeight-i, x0+xWidth, SDL_MapRGB(cache->format, 234, 178, 23));
    }
    
    if(name[0]!=0)
    {
        text=TTF_RenderUNICODE_Solid(textfont, name, DefaultColorText);
        dest.x=(cache->w-text->w)/2; dest.y=cache->h*5/9+7;
        SDL_BlitSurface(text, NULL, cache, &dest);
        SDL_FreeSurface(text);
    }
}

int Player::KeyEvent(SDL_KeyboardEvent &event)
{
	if(event.type==SDL_KEYDOWN)
    {
        Uint16 symbol=event.keysym.unicode;
		if(((symbol>=0x0410u) && (symbol<=0x044Fu)) || ((symbol>=0x0020u)&&(symbol<=0x007Fu)) || (symbol==0x0401u) || (symbol==0x0451u)) 
            if(menu<15)
            {
                name[menu]=symbol;
                menu++;
            }
            name[menu]=0;
            ChangeName();
        if(event.keysym.sym==SDLK_BACKSPACE) 
            if(menu>0)
            {
                menu--;
                name[menu]=0;
            }
        ChangeName();
        if(event.keysym.sym==SDLK_RETURN) return 1;
    }
    return 0;
}
