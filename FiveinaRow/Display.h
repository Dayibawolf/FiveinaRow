#pragma once
#include "Chess.h"
#include "Player.h"
#include <string>
class Display
{
public:
	void stone(int x, int y, int shape);  //根据棋子（广义）位置获得形状
	void drawboard(Chess &c);  //画出棋盘
	void gameinfo();  //显示游戏信息
	void playinfo(Player &p);  //显示玩家信息
	void inerror();  //显示输入错误
	void wfirst();  //显示询问信息，谁先落子
	void gameover(string player, string color);  //显示游戏结束信息
	Display();
	~Display();
};

