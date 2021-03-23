#pragma once
#include "Graphics.h"
#include "EventHandler.h"


/* ���������*/
class Interface: public Graphics, public EventHandler
{
protected:
	SDL_Surface *text;  /*����������� ��� ������*/
	TTF_Font* titlefont;  /*�����*/
	TTF_Font* textfont;
	TTF_Font* helpfont;
	TTF_Font* menufont;
	TTF_Font* recordfont;
	SDL_Color DefaultColorText; /*���� ��������� ������*/
	SDL_Color SelectedColorText; /*���� �������������� ������*/
	int menu; /*��������������� ����� ����*/
public:
	explicit Interface(SDL_Surface *const &surf);
	~Interface();
	void Show(SDL_Surface *const &surf);
};

