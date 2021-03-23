#include "MainMenu.h"

void MainMenu::item()
{
	text=TTF_RenderUTF8_Solid(menufont, "START GAME", (menu==0) ? SelectedColorText : DefaultColorText);
    dest.x=(cache->w - text->w)/2; dest.y=cache->h*3/9;
    Draw_FillCircle(cache, cache->w/3, dest.y+text->h/2, (text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    Draw_FillCircle(cache, cache->w*2/3, dest.y+text->h/2,(text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Circle(cache, cache->w/3, dest.y+text->h/2, (text->h/2+10)-i, (menu==0) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_Circle(cache, cache->w*2/3, dest.y+text->h/2, (text->h/2+10)-i, (menu==0) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    Draw_FillRect(cache, cache->w/3, dest.y-cache->h/108, cache->w/3, text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_HLine(cache, cache->w/3, dest.y-cache->h/108+i, cache->w*2/3, (menu==0) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    	Draw_HLine(cache, cache->w/3, dest.y+text->h+cache->h/108-i,cache->w*2/3, (menu==0) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text=TTF_RenderUTF8_Solid(menufont, "CHANGE PLAYER", (menu==1)? SelectedColorText : DefaultColorText);
    dest.x=(cache->w - text->w)/2; dest.y=cache->h*4/9;
    Draw_FillCircle(cache, cache->w/3, dest.y+text->h/2, (text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    Draw_FillCircle(cache, cache->w*2/3, dest.y+text->h/2,(text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Circle(cache, cache->w/3, dest.y+text->h/2, (text->h/2+10)-i, (menu==1) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_Circle(cache, cache->w*2/3, dest.y+text->h/2, (text->h/2+10)-i, (menu==1) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    Draw_FillRect(cache, cache->w/3, dest.y-cache->h/108, cache->w/3, text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_HLine(cache, cache->w/3, dest.y-cache->h/108+i, cache->w*2/3, (menu==1) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    	Draw_HLine(cache, cache->w/3, dest.y+text->h+cache->h/108-i,cache->w*2/3, (menu==1) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text=TTF_RenderUTF8_Solid(menufont, "RECORDS", (menu==2)? SelectedColorText : DefaultColorText);
    dest.x=(cache->w - text->w)/2; dest.y=cache->h*5/9;
    Draw_FillCircle(cache, cache->w/3, dest.y+text->h/2, (text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    Draw_FillCircle(cache, cache->w*2/3, dest.y+text->h/2,(text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Circle(cache, cache->w/3, dest.y+text->h/2, (text->h/2+10)-i, (menu==2) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_Circle(cache, cache->w*2/3, dest.y+text->h/2, (text->h/2+10)-i, (menu==2) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    Draw_FillRect(cache, cache->w/3, dest.y-cache->h/108, cache->w/3, text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_HLine(cache, cache->w/3, dest.y-cache->h/108+i, cache->w*2/3, (menu==2) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    	Draw_HLine(cache, cache->w/3, dest.y+text->h+cache->h/108-i,cache->w*2/3, (menu==2) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text=TTF_RenderUTF8_Solid(menufont, "RULES", (menu==3)? SelectedColorText : DefaultColorText);
    dest.x=(cache->w - text->w)/2; dest.y=cache->h*2/3;
    Draw_FillCircle(cache, cache->w/3, dest.y+text->h/2, (text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    Draw_FillCircle(cache, cache->w*2/3, dest.y+text->h/2,(text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Circle(cache, cache->w/3, dest.y+text->h/2, (text->h/2+10)-i, (menu==3) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_Circle(cache, cache->w*2/3, dest.y+text->h/2, (text->h/2+10)-i, (menu==3) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    Draw_FillRect(cache, cache->w/3, dest.y-cache->h/108, cache->w/3, text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_HLine(cache, cache->w/3, dest.y-cache->h/108+i, cache->w*2/3, (menu==3) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    	Draw_HLine(cache, cache->w/3, dest.y+text->h+cache->h/108-i,cache->w*2/3, (menu==3) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text=TTF_RenderUTF8_Solid(menufont, "QUIT GAME", (menu==4)? SelectedColorText : DefaultColorText);
    dest.x=(cache->w - text->w)/2; dest.y=cache->h*7/9;
    Draw_FillCircle(cache, cache->w/3, dest.y+text->h/2, (text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    Draw_FillCircle(cache, cache->w*2/3, dest.y+text->h/2,(text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Circle(cache, cache->w/3, dest.y+text->h/2, (text->h/2+10)-i, (menu==4) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_Circle(cache, cache->w*2/3, dest.y+text->h/2, (text->h/2+10)-i, (menu==4) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    Draw_FillRect(cache, cache->w/3, dest.y-cache->h/108, cache->w/3, text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_HLine(cache, cache->w/3, dest.y-cache->h/108+i, cache->w*2/3, (menu==4) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    	Draw_HLine(cache, cache->w/3, dest.y+text->h+cache->h/108-i,cache->w*2/3, (menu==4) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
}
MainMenu::MainMenu(SDL_Surface *const &surf): Interface(surf)
{	
	text=TTF_RenderUTF8_Solid(titlefont, "MENU", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y=cache->h/9;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
    
    item();

    text=TTF_RenderUTF8_Solid(helpfont, "TIP: Use arrows and cursor to select. Click 'Enter' or mouse button to move", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y=cache->h-text->h-(cache->h/20);
    Draw_FillRect(cache, cache->w/10, dest.y-cache->h/54, cache->w-(cache->w/5), text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Rect(cache, cache->w/10-i, dest.y-cache->h/54-i, cache->w-(cache->w/5)+2*i, text->h+cache->h/54+2*i, SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
}
void MainMenu::Show(SDL_Surface *const &surf, Uint16 *const &playerName)
{
	SDL_BlitSurface(cache, NULL, surf, NULL);
	if(playerName[0])
    {
        text=TTF_RenderUNICODE_Solid(textfont, playerName, DefaultColorText);
        dest.x=surf->w-text->w; dest.y=0;
        SDL_BlitSurface(text, NULL, surf, &dest);
        SDL_FreeSurface(text);
    }
}
int MainMenu::KeyEvent(SDL_KeyboardEvent &event)
{
	if(event.type==SDL_KEYDOWN)
    {
        if(event.keysym.sym==SDLK_DOWN)
        {
            if(menu!=4) menu++;
            else menu=0;
            item();
        }
        if(event.keysym.sym==SDLK_UP)
        {
            if(menu!=0) menu--;
            else menu=4;
            item();
        }
        if(event.keysym.sym==SDLK_RETURN) return menu;
    }
    return -1;
}
int MainMenu::MouseMotionEvent(SDL_MouseMotionEvent &motion)
{
	if(motion.type==SDL_MOUSEMOTION)
    {
        if(motion.y>=cache->h/3 && motion.y<=cache->h*4/9 && motion.x>=(cache->w/3) && (motion.x<=cache->w*2/3))
        {
            menu=0;
            item();
        }
        if(motion.y>=cache->h*4/9 && motion.y<=cache->h*5/9 && motion.x>=(cache->w/3) && (motion.x<=cache->w*2/3))
        {
            menu=1;
            item();
        }
        if(motion.y>=cache->h*5/9 && motion.y<=cache->h*2/3 && motion.x>=(cache->w/3) && (motion.x<=cache->w*2/3))
        {
            menu=2;
            item();
        }
        if(motion.y>=cache->h*2/3 && motion.y<=cache->h*7/9 && motion.x>=(cache->w/3) && (motion.x<=cache->w*2/3))
        {
            menu=3;
            item();
        }
        if(motion.y>=cache->h*7/9 && motion.y<=cache->h*8/9 && motion.x>=(cache->w/3) && (motion.x<=cache->w*2/3))
        {
            menu=4;
            item();
        }
    }
    return -1;
} 
int MainMenu::MouseButtonEvent(SDL_MouseButtonEvent &button)
{
	if(button.type==SDL_MOUSEBUTTONDOWN) return menu;
    return -1;
}
