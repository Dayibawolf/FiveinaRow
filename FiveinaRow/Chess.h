#pragma once
#include "Player.h"
class Chess
{
public:
	int board[15][15];  //棋盘矩阵
	int count = 0;  //棋子总个数
	int last_x, last_y;  //最新落子位置

	bool istrue(Player &p);
	void putstone(Player &p);
	Chess();
	~Chess();
};

