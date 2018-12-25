#include "GameOne.h"



GameOne::GameOne()
{
	cout << "加载游戏一成功！！！" << endl;
	CT_x = 0, CT_y = 1;
	UT_x = 0, UT_y = CT_y + 1;
	out.open("CharInput.txt");
}


GameOne::~GameOne()
{
	cout << '\n';
	cout << "正在退出..." << endl;
}

void GameOne::InitialGame()
{
	system("CLS");
	system("mode con cols=120 lines=30  ");
	system("TITLE The Random English Letters Input");
	cout << "请输入与上文相同的字符,输入完一行之后回车可继续输入,按ESC退出,按空格键暂停" << endl;
	Product();
	GotoPosition(CT_x, CT_y);
	cout << computerOutputT;
	GotoPosition(UT_x, UT_y);
}

void GameOne::RunGame()
{
	int key = 0;
	InitTime();
	while (1)
	{
		Sleep(50);
		if (_kbhit())
		{
			key = _getch();
			if (key == VK_ESCAPE)
				break;
			if (key == VK_BACK)
				DeleteWord();
			else if (key == VK_RETURN)
				Position();
			else if (key == VK_SPACE)
				PauseGame();
			else
			{
				StartTime();
				UserInput(key);
				GetInput(key);//存储在硬盘
				JudgeAction();
				Tempi++;
				Position();
			}
		}
		if (Tempj == 10)
		{
			system("CLS");
			GotoPosition(50, 15);
			cout << "You're Great!!!";
			GotoPosition(51, 16);
			cout << "Wait 3 second";
			Sleep(3000);
			break;
		}
		ShowTime(110, 0);
	}
	StatisticGame();
	CoutVelocity();
}

void GameOne::Product()
{
	if (Tempj != 0)
		out << '\n';
	out << "电脑输入：";
	for (int i = 0; i < 100; i++)
	{
		computerOutputT[i] = RandomWords();
		GetInput(computerOutputT[i]);
	}
	computerOutputT[100] = '\0';
	TransformWords();
	out << '\n';
	out << "用户输入：";
}

void GameOne::Position()
{
	if (Tempi == 100)
	{
		CT_y += 3, CT_x = 0;
		UT_y += 3, UT_x = 0;
		//跳转到计算机输出文本的位置
		SetConsoleTextAttribute(handle, 7);
		Tempi = 0;//另单次计数的Tempi=0
		Tempj++;//矩阵行数加一
		GotoPosition(CT_x, CT_y);
		Product();
		cout << computerOutputT;//重新写文本
		//跳转到用户输入文本的位置
		GotoPosition(UT_x, UT_y);
		SetConsoleTextAttribute(handle, 7);
	}

}

void GameOne::JudgeAction()
{
	if (!JudgeWords(computerOutputT[Tempi]))
	{
		//若不正确将在（90，0）处输出error
		GotoPosition(90, 0, false);
		cout << "error";
		//将用户输入的字符变成红色
		GotoPosition(UT_x - 1, UT_y, false);
		SetConsoleTextAttribute(handle, FOREGROUND_RED);
		cout << userInput;
		SetConsoleTextAttribute(handle, 7);
	}
	else
	{
		SetConsoleTextAttribute(handle, 7);//若出现错误，则重新纠正成白色
		cout << userInput;//若输入的字符与计算机输出的字符一致，则输出
	}
}

void GameOne::DeleteWord()
{
	cout << '\b';
	EarseWords();
	cout << '\b';
	UT_x--, Tempi--;
	//清除输出的error
	GotoPosition(90, 0);
	cout << "       ";
	//返回用户输入界面
	GotoPosition(UT_x, UT_y);
}

void GameOne::UserInput(int key)
{
	userInputSave[Tempj][Tempi] = userInput = char(key); UT_x++;
}

void GameOne::CoutVelocity()
{
	system("CLS");
	GotoPosition(30, 15, false);
	if (Tempi == 0 && Tempj == 0)
		cout << "只有测试之后才能知道成绩呢！" << endl;
	else
		cout << "你的打字速度为： " << double(game_Time) / correctNum << "s/字；"
		<< "另外，也可换算为：" << correctNum / double(game_Time) << "字/s" << endl;
	cout << "                              ";
	cout << "输入了" << Tempj * 100 + Tempi << "个字，"
		<< "其中，对了" << correctNum << "个字" << endl;
	cout << "                              ";
	cout << "请在此处查看详情：";	system("echo %cd%");
}
