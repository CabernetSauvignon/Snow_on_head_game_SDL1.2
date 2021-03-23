#pragma once
#include "Background.h"
#include "Intro.h"
#include "Player.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "GameOver.h"
#include "Game.h"
#include "RecordTable.h"
#include "Rules.h"

class MainWindow
{
private:
	enum Stage
	{
		GameStage=0,
		PlayerStage,
		RecordTableStage,
		RulesStage,
		IntroStage,
		MenuStage,
		GameOverStage,
		PauseStage
	} stage;
	Uint16 PlayerName[16];
	double time;
	clock_t start, _pause;
	Background background;
	Intro intro;
	Player player;
	MainMenu mainmenu;
	PauseMenu pausemenu;
	GameOver gameover;
	Game game;
	RecordTable recordtable;
	Rules rules;
public:
	explicit MainWindow(SDL_Surface *const &surf);
	void process(SDL_Surface *const &surf);
};

