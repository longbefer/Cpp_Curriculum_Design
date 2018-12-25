#pragma once
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream> 
#include <iostream>
using namespace std;
class Tools
{
public:
	Tools();
	~Tools();
public:
	void SetRoll();//设置滚动控制台
	void GotoPosition(int x, int y, bool Visible = true);//光标位置，光标是否可见
	void GetInput(char key);
	void OutText();
protected:
	COORD coor;
	HANDLE handle;
	ofstream out;
	ifstream in;
	int CT_x, CT_y;//电脑在控制台输出的坐标
	int UT_x, UT_y;//用户在控制台输出的坐标
};
