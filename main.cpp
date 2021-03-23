#include <iostream>
#include "MainWindow.h"

const int width=1920, height=1080, depth=32;

void exit();

int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "RUS");
	setbuf(stderr, NULL);
	if(SDL_Init(SDL_Init(SDL_INIT_EVERYTHING)))
	{
		fprintf(stderr,"Ошибка в SDL_Init: %s\n",SDL_GetError());
        return  1;
	}
	if (TTF_Init())
    {
        fprintf(stderr,"Ошибка в TTF_Init: %s\n",SDL_GetError());
        return 2;
    }
    atexit(exit);
    SDL_Surface *screen=SDL_SetVideoMode(width, height, depth, SDL_FULLSCREEN | SDL_DOUBLEBUF);
    if(!screen)
    {
    	fprintf(stderr,"SDL mode failed: %s\n",SDL_GetError());
        return 1;
    }
    SDL_EnableUNICODE(SDL_ENABLE);
    SDL_WM_SetCaption("Snow on head", NULL);
    MainWindow start(screen);
    start.process(screen);
	return 0;
}

void exit()
{
	TTF_Quit();
	SDL_Quit();
}
