#include "GameOver.h"

GameOver::GameOver(SDL_Surface *const &surf): Interface(surf)
{
	text=TTF_RenderUTF8_Solid(titlefont, "GAME OVER", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y=cache->h/8;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text=TTF_RenderUTF8_Solid(helpfont,"TIP: Press 'Enter' or mouse button to continue...", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y=cache->h-text->h-(cache->h/20);
    Draw_FillRect(cache, cache->w/10, dest.y-cache->h/54, cache->w-(cache->w/5), text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Rect(cache, cache->w/10-i, dest.y-cache->h/54-i, cache->w-(cache->w/5)+2*i, text->h+cache->h/54+2*i, SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
}
void GameOver::Show(SDL_Surface *const &surf, Uint16 *const &PlayerName, double time)
{
	SDL_BlitSurface(cache, NULL, surf, NULL);
	
	Draw_FillRect(cache, cache->w/5, cache->h*5/16, cache->w-(cache->w*2/5), cache->h/4, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
	    Draw_Rect(cache, cache->w/5-i, cache->h*5/16-i, cache->w-(cache->w*2/5)+2*i, cache->h/4+2*i, SDL_MapRGB(cache->format, 234, 178, 23));	
	if(PlayerName[0]!=0)
    {
        text=TTF_RenderUNICODE_Solid(textfont, PlayerName, DefaultColorText);
        dest.x=(surf->w-text->w)/2; dest.y=cache->h/3;
        SDL_BlitSurface(text, NULL, surf, &dest);
        SDL_FreeSurface(text);
    }
    char *txtbuf;
	int min=(int)time/60;
	int sec=(int)time%60;
	if (min>59)
	{
	    min=59;
	    sec=59;
	}
	int i=0;
	if (min>9) 
	{
		txtbuf=new char[6];
		txtbuf[1]=(min%10)+'0'; i++; 
		min/=10;
		txtbuf[0]=(min%10)+'0'; i++;
	}
	else
	{
		txtbuf=new char[5];
		txtbuf[i++]=(min%10)+'0';
	}
	txtbuf[i++]=':';
	if(sec>9)
	{
		i++;
		txtbuf[i]=(sec%10)+'0'; 
		i--;
		sec/=10;
		txtbuf[i]=(sec%10)+'0';
		i+=2;
	}
	else
	{
		txtbuf[i++]='0';
		txtbuf[i++]=(sec%10)+'0';
	}
	txtbuf[i]='\0';
	text=TTF_RenderText_Solid(textfont, txtbuf, DefaultColorText);
    dest.x = (surf->w-text->w)/2; dest.y=surf->h*4/9;
    SDL_BlitSurface(text, NULL, surf, &dest);
    SDL_FreeSurface(text);
    delete[] txtbuf;
}
