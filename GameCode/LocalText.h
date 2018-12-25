#pragma once
#include "CountTime.h"
class LocalText :public CountTime
{
public:
	LocalText();
	~LocalText();
public:
	void ShowText();//重新载入下一行
	void CalculateText();//每次判断输入到哪一行
	void JudgeWord();//判断输入的东西是否正确
	void CleanWord();//清除句子，避免下次重复
	void EnterLine();//判断是否可以回车载入下一行
	void CleanErroText();//清除错误内容
public:
	char Word[110];//用户输入
protected:
	char LineWord[110];//计算机读取	
	int TextLineLen;//接近文本的长度
	int LineLen;//单行文本长度
	int TextLen;//文本总长
	bool All_Right;
private:
	char Temp[4000];//将文件中的文本传入Temp
	char TextLine[4000];//依次给TextLine赋值，确认到了哪一行
};
