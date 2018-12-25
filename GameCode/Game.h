#pragma once
#include <iostream>
using namespace std;
class Game
{
public:
	Game();
	virtual ~Game();
public:
	virtual void InitialGame() = 0;
	virtual void RunGame() = 0;
};
