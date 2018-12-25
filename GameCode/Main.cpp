#include "GameOne.h"
#include "GameTwo.h"
#include "GameThree.h"
#include "Game.h"
//以下为静态成员函数
int CharTrain::Tempi = 0;
int CharTrain::Tempj = 0;
int CharTrain::correctNum = 0;
//以下为函数声明
void CharInputFun();
void CharFallFun();
void LocalTextFun();
void MainMenu();
int main()
{
	//system("color 70");
	MainMenu();
	return 0;
}

void CharInputFun()
{
	system("cls");
	Game *G1 = new GameOne;
	G1->InitialGame(); G1->RunGame();
	delete G1, G1 = NULL;
	system("pause>nul");
	MainMenu();
}

void CharFallFun()
{
	system("cls");
	Game *G2 = new GameTwo;
	G2->InitialGame(); G2->RunGame();
	delete G2, G2 = NULL;
	system("pause>nul");
	MainMenu();
}

void LocalTextFun()
{
	system("cls");
	Game *G3 = new GameThree;
	G3->InitialGame(); G3->RunGame();
	delete G3, G3 = NULL;
	system("pause>nul");
	MainMenu();
}

void MainMenu()
{
	system("TITLE MainMenu");
	Tools T;
	system("echo 主菜单加载完成!!!");
	system("CLS");
	int key = 0;
	cout << "————————————————————————————" << endl;
	cout << "               请输入你要选择的功能                     " << endl;
	cout << "————————————————————————————" << endl;
	cout << "————————————————————————————" << endl;
	cout << "||                                                    ||" << endl;
	cout << "||   1————————————————随机英文练习    ||" << endl;
	cout << "||   2————————————————单个英文练习    ||" << endl;
	cout << "||   3—————————————————中文练习      ||" << endl;
	cout << "||   4——————————————————退出        ||" << endl;
	cout << "||                                                    ||" << endl;
	cout << "————————————————————————————" << endl;
	cout << "————————————————————————————" << endl;
	cout << "请输入你的选择：";
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			cout << char(key);
			Sleep(200);
			T.GotoPosition(0, 14, false);
			cout << "           ";
			switch (key)
			{
			case '1':CharInputFun(); break;
			case '2':CharFallFun(); break;
			case '3':LocalTextFun(); break;
			case '4':exit(0);
			case VK_ESCAPE:exit(0);
			default:
				T.GotoPosition(0, 14, false);
				cout << "此输入无效";
				T.GotoPosition(16, 12);
				cout << " " << '\b';
				break;
			}
		}
	}
	cout << endl;
	system("CLS");
}
