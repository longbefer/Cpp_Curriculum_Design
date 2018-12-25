#pragma once
#include "CharTrain.h"
#include "Game.h"
class GameOne :public CharTrain, public Game
{
public:
	GameOne();
	virtual ~GameOne();
public:
	virtual void InitialGame();
	virtual void RunGame();
public:
	void Product();
	void Position();//自动换行
	void JudgeAction();//判断
	void DeleteWord();
	void UserInput(int key);
	void CoutVelocity();
};
