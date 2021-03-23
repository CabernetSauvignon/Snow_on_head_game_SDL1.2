#pragma once
#include <vector>
#include <ctime>
#include "Rain.h"
#include "People.h"

using namespace std;

class Game: public Graphics, public EventHandler
{
private:
	int speed, force;
	double limit;
	vector<Rain*> Rains;
	People people;
public:
	explicit Game(SDL_Surface *const &surf);
	void Show(SDL_Surface *const &surf);
	bool Update(SDL_Surface *const &surf, const double &time);
	int KeyEvent(SDL_KeyboardEvent &event);
	void Reset(SDL_Surface *const &surf);
};

