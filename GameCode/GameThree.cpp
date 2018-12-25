#include "GameThree.h"
time_t GameThree::totalTime = 0;
void Info();
void Winner();

GameThree::GameThree()
{
	cout << "加载游戏三成功！！！" << endl;
}


GameThree::~GameThree()
{
	cout << '\n';
	cout << "正在退出..." << endl;
}

void GameThree::InitialGame()
{
	system("cls");
	system("TITLE LocalText");
	SetRoll();//设置成可以滚动，节约屏幕空间
	Info();//展现注意事项
	cout << "中文输入，输入完成后请回车，若要退出请先按Enter键等待1S后再按ESC键" << endl;
	for (int i = 0; i < 120; i++)
		cout << "_";
	ShowText();
	CalculateText();
}

void GameThree::RunGame()
{
	while (1)
	{
		if (!in)
		{
			system("cls");
			cout << "没有LocalText.txt文件，请创建此文件在："; system("echo %cd%");
			cout << "请仔细阅读开头的“注意事项”";
			system("pause>nul");
			break;
		}
		if (!All_Right)//对输入错误的处理
		{
			Sleep(2000);//将错误展示2s
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			GotoPosition(105, CT_y - 3);
			cout << "输入错误";//以红色字体输出“输入错误”
			SetConsoleTextAttribute(handle, 7);
			GotoPosition(0, UT_y);
			CleanErroText();//清除掉输入错误的文本，重新给word输入
		}
		InitTime();//初始化时间
		cin.getline(Word, 110, '\n');//将输入的字符传入Word，输入\n时停止输入
		GotoPosition(103, UT_y);//以下为输出时间
		cout << "用时："; ShowTime(110, UT_y);
		totalTime += game_Time;//最后结果时间
		if (TextLineLen == TextLen)//对输入完的处理
		{
			Winner();
			break;
		}
		CleanWarnText();//清除掉“输入错误”“请输入完再回车”文本
		EnterLine();//判断是否可以回车输出下一行文本
		Sleep(1000);//等待1s
		if (_kbhit())
			if (_getch() == VK_ESCAPE)//esc键
				break;
	}
	Winner();
}

void GameThree::CleanWarnText()//清除掉“输入错误”“请输入完再回车”文本
{
	GotoPosition(105, CT_y - 3);
	for (int i = 0; i < 15; i++)
		cout << " ";
	GotoPosition(UT_x, UT_y);
}

void Info()//可以将注意事项写成文本，但太麻烦
{
	cout << '\n' << endl;
	for (int i = 0; i < 56; i++)
		cout << " ";
	cout << "注意事项";
	for (int i = 0; i < 56; i++)
		cout << " ";
	cout << '\a';//提示警告音，可怕！！！
	cout << '\n' << endl;//一长串注意事项
	cout << "    因为中文的特殊性，文本可能存在编码问题；尽管我尽力使文本不出现格式问题，但是依然不能避免问题的出现。\n" << '\n'
		<< "    其次，本程序会自动检测是否含有LocalText.txt文件，如果你未包含此文件，那么程序将不会运行；"
		<< "当然，你可以创建一个这样的同名文件在本程序下；但要注意请在此文件中包含你所需要的文本内容，程序将会自动把文本输出。"
		<< "同时，请注意，由于中文与英文所包含字节不同，文本中请勿包含英文字符及其标点，否则可能导致中文文件读取错误。\n" << '\n'
		<< "    并且，由于中文文本的读取方式，故，若你需要退出程序，你需要先按回车键结束文本输入，等待1秒后再按ESC键退出程序！！！"
		<< "若你在1s内未按ESC键，程序将自动进入文本输入环节，届时你需要重复回车等待一秒按ESC键的操作！！\n" << endl;
	system("pause");
	system("cls");
}

void Winner()
{
	system("CLS");
	cout << "恭喜，完成输入!!!" << endl;;
	cout << "总用时：" << int(GameThree::totalTime / 60) << " : " << GameThree::totalTime % 60;
	system("pause>nul");
}
