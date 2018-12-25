#pragma once
#include "CountTime.h"
class CharTrain :public CountTime
{
public:
	CharTrain();
	~CharTrain();
public:
	char RandomWords();//随机生成文本
	bool JudgeWords(char &T);//判断文本
	void TransformWords();//转换文本
	void EarseWords();//擦出文本
	void PauseGame();//暂停游戏
	void StatisticGame();//统计字符
public:
	int is_pause_again;
	static int Tempi;
	static int Tempj;
	static int correctNum;//输入正确的数目
protected:
	char userInput;//用户输入的字符
	char userInputSave[11][100];//用户输入字符储存
	char computerOutput;//电脑随机输出的字符
	char computerOutputT[101];//电脑随机输出字符保存
	char computerOutputSave[11][100];//电脑输出字符储存
};
