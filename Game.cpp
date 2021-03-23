#include "Game.h"

Game::Game(SDL_Surface *const &surf): speed(8), force(6), limit(15), people(surf)
{
	int temp;
	for(int i = 0; i<force; i++) Rains.push_back(new Rain(surf, 3+(rand()%(speed-3))));
}
void Game::Show(SDL_Surface *const &surf)
{
	int size=Rains.size();
	for(int i=0; i<size; i++) Rains[i]->Show(surf);
	people.Show(surf);
}
bool Game::Update(SDL_Surface *const &surf, const double &time)
{
	SDL_Rect coordinates;
	SDL_Color TimeColor;
	coordinates.x=0; coordinates.y=0;
	char *timetext;
	int min=(int)time/60;
	int sec=(int)time%60;
	if (min>59)
	{
	    min=59;
	    sec=59;
	}
	int j=0;
	if (min>9) 
	{
		timetext=new char[6];
		timetext[1]=(min%10)+'0'; j++; 
		min/=10;
		timetext[0]=(min%10)+'0'; j++;
	}
	else
	{
	    timetext=new char[5];
		timetext[j++]=(min%10)+'0';
	}
	timetext[j++]=':';
	if(sec>9)
	{
		j++;
		timetext[j]=(sec%10)+'0';
		j--; 
		sec/=10;
		timetext[j]=(sec%10)+'0';
		j+=2;
	}
	else
	{
		timetext[j++]='0';
		timetext[j++]=(sec%10)+'0';
	}
	timetext[j]='\0';
	TTF_Font *font=TTF_OpenFont("magic.ttf", 40);
	TimeColor.r=255; TimeColor.g=255; TimeColor.b=255;
	SDL_Surface *text=TTF_RenderText_Solid(font, timetext, TimeColor);
	SDL_BlitSurface(text, NULL, surf, &coordinates);
    SDL_FreeSurface(text);
    delete[] timetext;
    TTF_CloseFont(font);
    int size=Rains.size();
    for(int i=0; i<size; i++)
    {
    	Rains[i]->Move('d');
    	if(Rains[i]->GetY()>=surf->h) 
		{
		    Rains[i]->SetStatus(surf, 4+(rand()%(speed-4)));
	    }
    	if((Rains[i]->GetY()+Rains[i]->GetH())<=people.GetY()+35)
        {
            if ((Rains[i]->GetY()+Rains[i]->GetH()>=people.GetY())
            && (Rains[i]->GetX()>=(people.GetX()+30)-Rains[i]->GetW())
            && Rains[i]->GetX()<=(people.GetX()+30)+(people.GetW()-30))
            return false;
        }
    }
    if(time>=limit)
    {
    	force+=2;
    	limit+=15;
    	Rains.resize(force);
    	for(int i=force-2; i<force; i++)
    	{
    		Rains[i]=new Rain(surf, 3+(rand()%(speed-3)));
    	}
    }
    return true;
}
int Game::KeyEvent(SDL_KeyboardEvent &event)
{
	return people.KeyEvent(event);
}
void Game::Reset(SDL_Surface *const &surf)
{
	Rains.clear();
	force=6;
	speed=8;
	for(int i = 0; i < 6; i++)
        Rains.push_back(new Rain(surf, 3+(rand()%(speed-3))));
	people.Reset();
	
}
