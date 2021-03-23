#pragma once
#include "Interface.h"
#include <fstream>

struct Result
{
	Uint16 name[16];
	int score;
	Result();
	Result& operator=(const Result &record);
};

class RecordTable: public Interface
{
private:
    int count;  
    Result result[10]; 
private:
    void itemMenu();
public:
	explicit RecordTable(SDL_Surface *const &surf);
    ~RecordTable();
    void Show(SDL_Surface *const &surf);
    int KeyEvent (SDL_KeyboardEvent &event);
    int MouseMotionEvent (SDL_MouseMotionEvent &motion);
    int MouseButtonEvent(SDL_MouseButtonEvent &button);
    void Clear();
    void Print();
    void AddRecord(const double &score, Uint16 *const &playerName);
    void ConvertUTF16toUTF8(const Uint16 *sourceStart, const int sourceCount,
                             Uint8 *targetStart, const int targetCount);
};

