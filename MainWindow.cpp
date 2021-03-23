#include "MainWindow.h"

MainWindow::MainWindow(SDL_Surface *const &surf): PlayerName(), background(surf), intro(surf), player(surf, PlayerName),
                       mainmenu(surf), game(surf), gameover(surf), rules(surf), pausemenu(surf), recordtable(surf)
{
	stage=IntroStage;
	start=0;
	_pause=0;
	time=0;
}

void MainWindow::process(SDL_Surface *const &surf)
{
	SDL_Event event;
	bool work=true;
	char item=0;
	while(work)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT) work=false;
			if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(stage==IntroStage) stage=Stage(PlayerStage);
                else if(stage==PlayerStage) stage=Stage(MenuStage);
                else if(stage==MenuStage)
                {
                    item=mainmenu.MouseButtonEvent(event.button);
                    if(item>=0)
                    {
                        if(item==4) work=false;
						else stage=Stage(item);
						if(stage==0) start=clock();
                    }
                }
                else if(stage==PauseStage)
				{
					item=pausemenu.MouseButtonEvent(event.button);
                    if(item==1) 
					{       
                        game.Reset(surf);
                        stage=Stage(MenuStage);
                    }
                    else if(item==0) 
					{     
                        stage=Stage(GameStage);
                        start+=(clock()-_pause);
                    }
				}
                else if(stage==GameOverStage)
                {
                    game.Reset(surf);
                    stage=Stage(MenuStage);
                }
                else if(stage==RecordTableStage) 
				{
                    if(recordtable.MouseButtonEvent(event.button)==2) stage=Stage(MenuStage);
                }
                else if(stage==RulesStage)
                {
				    if(rules.MouseButtonEvent(event.button)==0) stage=Stage(MenuStage);
				}
            }
            if(event.type == SDL_MOUSEMOTION)
            {
                if(stage==MenuStage) mainmenu.MouseMotionEvent(event.motion);
                if(stage==PauseStage) pausemenu.MouseMotionEvent(event.motion);
                if(stage==RecordTableStage) recordtable.MouseMotionEvent(event.motion);
            }
            if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
            {
                if(stage==IntroStage)
                {
                    stage=Stage(PlayerStage);
                }
                else if(stage==PlayerStage)
                {
                    if(player.KeyEvent(event.key)) stage=Stage(MenuStage);
                }
                else if(stage==MenuStage)
                {
                    item=mainmenu.KeyEvent(event.key);
                    if(item>=0)
                    {
                        if(item==4) work=false;
                        else stage=Stage(item);
                        if(stage==0) start=clock();
                    }
                }
                else if(stage==PauseStage)
				{
					item=pausemenu.KeyEvent(event.key);
                    if(item==1)        
                    {
                        game.Reset(surf);
                        stage=Stage(MenuStage);
                    }
                    else if(item==0) 
					{
                        stage=Stage(GameStage);
                        start+=(clock()-_pause);
                    }
				}
                else if(stage==GameStage)
                {
                    if(event.key.keysym.sym==SDLK_ESCAPE)
					{
					    stage=Stage(PauseStage);
					    _pause=clock();
				    }
                    else game.KeyEvent(event.key);
                }
                else if(stage==GameOverStage && event.key.keysym.sym==SDLK_RETURN)
                {
                    game.Reset(surf);
                    stage=Stage(MenuStage);
                }
                else if(stage==RecordTableStage) 
				{ 
                    if(recordtable.KeyEvent(event.key)==2) stage=Stage(MenuStage);
                }
                else if(stage==RulesStage)
                {
				    if(rules.KeyEvent(event.key)==0) stage=Stage(MenuStage);
				}
            }
		}
		background.Show(surf);
		
		if(stage==IntroStage) intro.Show(surf);
		else if(stage==PlayerStage) player.Show(surf);
		else if(stage==MenuStage) mainmenu.Show(surf, PlayerName);
		else if(stage==GameStage)
		{
			time=((clock()-start)/(double)CLOCKS_PER_SEC);
			game.Show(surf);
			game.Update(surf, time);
			if(game.Update(surf, time)==false)
			{
				recordtable.AddRecord(time, PlayerName);
				stage=Stage(GameOverStage);
			}
		}
		else if(stage==PauseStage) pausemenu.Show(surf);
		else if(stage==GameOverStage) gameover.Show(surf, PlayerName, time);
		else if(stage==RecordTableStage) recordtable.Show(surf);
		else if(stage==RulesStage) rules.Show(surf);
		SDL_Flip(surf); 
	}
}
