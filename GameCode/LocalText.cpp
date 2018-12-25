#include "LocalText.h"



LocalText::LocalText()
{
	cout << "正在加载LocalText游戏类..." << endl;
	All_Right = true;
	CT_y = 3, CT_x = 0;
	UT_y = CT_y + 1, UT_x = 0;
	for (int i = 0; i < 4000; i++)
		TextLine[i] = Temp[i] = '\0';
	for (int i = 0; i < 110; i++)
		Word[i] = '\0';
	in.open("LocalText.txt");
	in.getline(Temp, 4000, 0);
	TextLineLen = 0;
	LineLen = 0;
	TextLen = strlen(Temp);
}


LocalText::~LocalText()
{
}

void LocalText::ShowText()
{
	CleanWord();
	int j = 0;
	for (int i = TextLineLen; i < TextLen; i++)
	{
		TextLine[i] = Temp[i];
		//对于每一行来说，如果到行尾，输出
		if (Temp[i] == '\n')
			break;
		LineWord[j] = TextLine[i];
		j++;
		//使每一百个字符之后换行
		CT_x++;
		if (CT_x == 100)
			break;
	}
	GotoPosition(0, CT_y);
	cout << LineWord;

	if (TextLineLen < TextLen)
		CT_y += 3;
	GotoPosition(UT_x, UT_y);
}

void LocalText::CalculateText()
{
	TextLineLen = strlen(TextLine);
}

void LocalText::JudgeWord()
{
	All_Right = true;
	LineLen = strlen(LineWord);
	for (int i = 0; i < LineLen; i++)
	{
		if (Word[i] != LineWord[i])
		{
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			GotoPosition(i, UT_y);
			for (int j = i; j <= i + 1; j++)
				cout << Word[j]; i++;//在Windows10的控制台上似乎没办法输出这个错误的字符，只能是问号！！？
			SetConsoleTextAttribute(handle, 7);
			GotoPosition(0, UT_y);
			All_Right = false;
		}
	}
}

void LocalText::CleanWord()
{
	for (int i = 0; i < 110; i++)
		LineWord[i] = Word[i] = '\0';
	CT_x = 0, UT_x = 0, UT_y = CT_y + 1;
}

void LocalText::EnterLine()
{
	if (strlen(Word) == strlen(LineWord))
	{
		JudgeWord();
		if (All_Right)//全对则换行输入另一段文本
		{
			ShowText();
			CalculateText();
		}
	}
	else
	{
		//由于没有输完就回车了，故word[110]要重写，故只有清空全部输入的再重新输入。
		GotoPosition(105, CT_y - 3);
		SetConsoleTextAttribute(handle, FOREGROUND_RED);
		cout << "请输入完再回车";
		SetConsoleTextAttribute(handle, 7);
		GotoPosition(UT_x, UT_y);
		for (int i = 0; i <= LineLen; i++)
			cout << " ";
		GotoPosition(UT_x, UT_y);
		for (int i = 0; i < 110; i++)
			Word[i] = '\0';
	}
}

void LocalText::CleanErroText()
{
	if (!All_Right)
		for (int i = 0; i < LineLen; i++)
			cout << "  ";
	GotoPosition(0, UT_y);
}
