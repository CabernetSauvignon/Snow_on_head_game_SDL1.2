#pragma once

struct SDL_KeyboardEvent;
struct SDL_MouseMotionEvent;
struct SDL_MouseButtonEvent;

class EventHandler
{
public:
    virtual int KeyEvent(SDL_KeyboardEvent &event) {return 5;}   /*������� �������*/
    virtual int MouseMotionEvent(SDL_MouseMotionEvent &event) {return 5;}   /*�������� �������*/
    virtual int MouseButtonEvent(SDL_MouseButtonEvent &event) {return 5;}   /*������� ������ ����*/
};

