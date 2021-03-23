#pragma once
#include "EventHandler.h"
#include "DynamicSurface.h"

class Control : public EventHandler, public DynamicSurface
{
private:
	char key;
public:
	explicit Control(SDL_Surface *const &surf);
    void Show(SDL_Surface *const &surf);
    void Reset();
    void Move(char flag);
    int KeyEvent(SDL_KeyboardEvent &event);
    inline int GetH() {return cache->h;}
    inline int GetW() {return cache->w;}
};
