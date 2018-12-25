#include "CountTime.h"



CountTime::CountTime()
{
	cout << "正在加载时间..." << endl;
	is_pause = false;
	minute = 0, second = 0;
	inital_Time = 0, pause_Time = 0, game_Time = 0;
}


CountTime::~CountTime()
{
}

void CountTime::InitTime()
{
	inital_Time = time(0);
}

void CountTime::StartTime()
{
	if (is_pause)
	{
		is_pause = 0;
		inital_Time += time(0) - pause_Time;
	}
}

void CountTime::PauseTime()
{
	if (!is_pause)
	{
		is_pause = 1;
		pause_Time = time(0);
	}
}

void CountTime::ShowTime(int x, int y)
{
	if (is_pause)
		PauseTime();
	else
	{
		game_Time = time(0) - inital_Time;
		minute = game_Time / 60, second = game_Time % 60;
		//跳转到时间输入点
		GotoPosition(x, y);
		cout << minute << " : " << setw(2) << setfill('0') << second;//输出时间
		//返回用户输入点
		GotoPosition(UT_x, UT_y);
	}
}
