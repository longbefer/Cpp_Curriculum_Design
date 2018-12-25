#include "Tools.h"



Tools::Tools()
{
	cout << "正在初始化工具类..." << endl;
}


Tools::~Tools()
{
	out.close();
	in.close();
}

void Tools::SetRoll()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coor.X = 120;
	coor.Y = 100;
	SetConsoleScreenBufferSize(handle, coor);
	// 设置窗口大小(单位:字符数)
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = 120;
	Rect.Bottom = 30;
	Rect.Right -= 1; Rect.Bottom -= 1;
	SetConsoleWindowInfo(handle, TRUE, &Rect);

}

void Tools::GotoPosition(int x, int y, bool Visible)
{
	coor.X = x;
	coor.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;//隐藏光标
	GetConsoleCursorInfo(handle, &cci);
	cci.bVisible = Visible;//赋1为显示，赋0为隐藏
	SetConsoleCursorInfo(handle, &cci);
	SetConsoleCursorPosition(handle, coor);
}

void Tools::GetInput(char key)
{
	if (!out)
		cout << "Failed to create file1...\n";
	else
		out << key;
}

void Tools::OutText()
{
	if (!in)
		cout << "Failed to create file2...\n";
}
