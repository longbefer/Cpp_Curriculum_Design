#include "CharTrain.h"



CharTrain::CharTrain()
{
	cout << "正在加载Char游戏类..." << endl;
	srand((unsigned)time(NULL));//产生随机种子
	is_pause_again = -1;
}


CharTrain::~CharTrain()
{
}

char CharTrain::RandomWords()
{
	computerOutput = char(rand() % 57 + 65);
	while (computerOutput >= 91 && computerOutput <= 96)
		computerOutput = rand() % 57 + 65;
	return computerOutput;
}

bool CharTrain::JudgeWords(char &T)
{
	if (userInput == T)
		return true;
	else return false;
}

void CharTrain::TransformWords()
{
	for (int i = 0; i < 100; i++)
		computerOutputSave[Tempj][i] = computerOutputT[i];
}

void CharTrain::EarseWords()
{
	cout << " ";
}

void CharTrain::PauseGame()
{
	//1时暂停，-1为继续
	is_pause_again = -is_pause_again;
	if (is_pause_again == 1)//若为1则暂停
		PauseTime();
	else StartTime();
}

void CharTrain::StatisticGame()
{
	for (int i = 0; i <= Tempj; i++)
	{
		if (i == Tempj)//等于行数时，由于存在未完整输完的情况，故分情况讨论
		{
			for (int j = 0; j < Tempi; j++)
				if (computerOutputSave[i][j] == userInputSave[i][j])
					correctNum++;
		}
		else
		{
			for (int j = 0; j < 100; j++)
				if (computerOutputSave[i][j] == userInputSave[i][j])
					correctNum++;
		}
	}
}
