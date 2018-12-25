#pragma once
#include "CharTrain.h"
#include "Game.h"
class GameTwo :public CharTrain, public Game
{
public:
	GameTwo();
	virtual ~GameTwo();
public:
	virtual void InitialGame();
	virtual void RunGame();
protected:
	void LettersProduct();//产生字符
	void LettersErase();//擦除字符
	void Move();//移动字符
	void Position();//展现字符位置
	void PauseGameTwo();//暂停游戏
	void JudgePosite();//判段是否碰壁
	void JudgeAction(int key);//判断字符
	void EarseText();//擦除无用文本
	void ShowLife();//显示生命
	void EarseLife();//擦除生命
	void GameLevel();//游戏等级
	void CoutNumTime();//最后结果
protected:
	int life, level;
};
