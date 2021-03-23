#pragma once

struct SDL_KeyboardEvent;
struct SDL_MouseMotionEvent;
struct SDL_MouseButtonEvent;

class EventHandler
{
public:
    virtual int KeyEvent(SDL_KeyboardEvent &event) {return 5;}   /*нажатие клавиши*/
    virtual int MouseMotionEvent(SDL_MouseMotionEvent &event) {return 5;}   /*Движение курсора*/
    virtual int MouseButtonEvent(SDL_MouseButtonEvent &event) {return 5;}   /*Нажатие кнопки мыши*/
};

