#include "GameTwo.h"



GameTwo::GameTwo()
{
	life = 5; level = 1;
	UT_x = 0, UT_y = 2; correctNum = 0;
	cout << "加载游戏二成功！！！" << endl;
	out.open("CharFall.txt");
}


GameTwo::~GameTwo()
{
	cout << "正在退出..." << endl;
}

void GameTwo::InitialGame()
{
	system("mode con cols=120 lines=30  ");
	system("TITLE Letters Party Game");
	cout << "游戏加载完成！！";
	system("CLS");
	GotoPosition(50, 0, false);
	cout << "LETTERS PARTY";
	GotoPosition(0, 0, false);
	cout << "关卡：";
	GotoPosition(80, 0, false);
	cout << "血量：";
	GotoPosition(90, 22, false);
	cout << "正确数：";
	GotoPosition(0, 22, false);
	cout << "依照落下的字母来按键盘，空格暂停，当血量为0时死亡" << endl;
	GotoPosition(0, 20);
	for (int i = 0; i < 120; i++)
		cout << "_";
	GotoPosition(0, 1);
	for (int i = 0; i < 120; i++)
		cout << "_";
}

void GameTwo::RunGame()
{
	int key = 0;
	InitTime();
	LettersProduct();
	Position();
	while (1)
	{
		GameLevel();
		ShowTime(110, 0);
		if (is_pause_again == -1)
			Move();
		if (life == 0)
			break;
		ShowLife();
		if (_kbhit())
		{
			key = _getch();
			if (key == VK_ESCAPE)//esc键
				break;
			if (key == VK_SPACE)//空格键
				PauseGameTwo();//暂停时间
			else
			{
				if (is_pause_again == 1)
					PauseGameTwo();
				EarseText();
				out << "用户输入：";
				GetInput(key);//存储在硬盘中
				out << '\n';
				JudgeAction(key);
				ShowTime(110, 0);
			}
		}
	}
	CoutNumTime();//输出结果
}

void GameTwo::LettersProduct()
{
	RandomWords();
	UT_x = rand() % 120, UT_y = 2;
	out << "电脑输出："; GetInput(computerOutput);
	out << '\n';
}

void GameTwo::LettersErase()
{
	GotoPosition(UT_x, UT_y, false);
	cout << "  ";
}

void GameTwo::Move()
{
	LettersErase(); UT_y++;
	Position();
	JudgePosite();
	Sleep(800 - 80 * level);
}

void GameTwo::Position()
{
	//选择随机掉落初始位置并向下运动
	GotoPosition(UT_x, UT_y, false);
	cout << computerOutput;
}

void GameTwo::PauseGameTwo()
{
	PauseGame();
	if (is_pause_again == 1)//若为1则暂停
	{
		//清除屏幕内容，防止作弊
		GotoPosition(UT_x, UT_y);
		cout << "  ";
		GotoPosition(55, 10);
		cout << "暂停" << endl;
	}
	else//不为一则继续
	{
		//出现内容
		GotoPosition(UT_x, UT_y, false);
		//cout << computerOutput;
		GotoPosition(55, 10);
		cout << "     " << endl;
	}
}

void GameTwo::JudgePosite()
{
	//判断是否碰壁
	if (UT_y >= 20)
	{
		GotoPosition(UT_x, UT_y, false);
		cout << "_";
		EarseText();
		GotoPosition(0, 25);
		cout << "碰壁";
		computerOutput = ' '; UT_y = 0; out << "用户未输入\n"; LettersProduct(); Position();
		life--;
		ShowLife();
	}
}

void GameTwo::JudgeAction(int key)
{
	this->userInput = char(key);
	if (JudgeWords(computerOutput))
	{
		correctNum++;
		GotoPosition(UT_x, UT_y, false);
		cout << " ";
		computerOutput = ' '; UT_y = 0; LettersProduct(); Position();
	}
	else
	{
		GotoPosition(0, 25);
		cout << "输入错误" << endl;
		life--;
	}
	JudgePosite();
}

void GameTwo::EarseText()
{
	GotoPosition(0, 25);
	cout << "          ";//擦除碰壁
	GotoPosition(90, 25);
	cout << "                     "; //擦除输入错误
}

void GameTwo::ShowLife()
{
	//显示生命
	Sleep(50);
	EarseLife();
	for (int i = 0; i < life; i++)
	{
		GotoPosition(86 + i, 0, false);//位置、光标不可见
		cout << "*";
	}
}

void GameTwo::EarseLife()
{
	//擦除生命
	for (int i = 0; i <= life; i++)
	{
		GotoPosition(86 + i, 0, false);//位置、光标不可见
		cout << " ";
	}
}

void GameTwo::GameLevel()
{
	GotoPosition(8, 0, false);
	cout << level;//输出等级
	GotoPosition(100, 22, false);
	cout << correctNum;//输出正确的个数
	if (correctNum == 10 * level * level)//等级与分数之间的关系
	{
		if (level < 10)
		{
			level++; life++;
			GotoPosition(90, 25);
			cout << "升级了！！！" << endl;
		}
		else
		{
			GotoPosition(90, 25);
			cout << "大神，你已满级了！！" << endl;
		}
	}
}

void GameTwo::CoutNumTime()
{
	GotoPosition(40, 15);
	cout << "You're Failed!!!";
	GotoPosition(40, 16);
	cout << "Total using time: " << game_Time << "s";
	GotoPosition(40, 17);
	cout << "A total of " << correctNum << " you're right!";
	GotoPosition(0, 26);
	cout << "See the log in: ";	system("echo %cd%");
}
