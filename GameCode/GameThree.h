#pragma once
#include "LocalText.h"
#include "Game.h"
class GameThree :public LocalText, public Game
{
public:
	GameThree();
	virtual ~GameThree();
public:
	virtual void InitialGame();
	virtual void RunGame();
public:
	void CleanWarnText();
public:
	static time_t totalTime;
};
