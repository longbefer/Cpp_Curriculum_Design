#pragma once
#include <iomanip>
#include "Tools.h"
class CountTime :public Tools
{
public:
	CountTime();
	~CountTime();
public:
	bool is_pause;
public:
	void InitTime();//初始化时间
	void StartTime();//从零开始的时间
	void PauseTime();//判断暂停的时间
	void ShowTime(int x, int y);//显示时间
protected:
	time_t minute, second;
	time_t inital_Time, pause_Time, game_Time;
};
