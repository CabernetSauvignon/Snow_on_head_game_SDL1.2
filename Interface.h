#pragma once
#include "Graphics.h"
#include "EventHandler.h"


/* Интерфейс*/
class Interface: public Graphics, public EventHandler
{
protected:
	SDL_Surface *text;  /*Поверхность для текста*/
	TTF_Font* titlefont;  /*Шрифт*/
	TTF_Font* textfont;
	TTF_Font* helpfont;
	TTF_Font* menufont;
	TTF_Font* recordfont;
	SDL_Color DefaultColorText; /*Цвет основного текста*/
	SDL_Color SelectedColorText; /*Цвет задействанного текста*/
	int menu; /*Задействованный пункт меню*/
public:
	explicit Interface(SDL_Surface *const &surf);
	~Interface();
	void Show(SDL_Surface *const &surf);
};

