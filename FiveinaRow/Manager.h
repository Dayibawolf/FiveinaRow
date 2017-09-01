#pragma once
#include <string>
#include "Player.h"

class Manager
{
private:
	int model;  //游戏模式
	Player player;
	string player1, player2;  //玩家名称
	string color1, color2;  //玩家棋子颜色
	int turn = -1;  //玩家轮换标志，1：player1 -1：player2
	int win;

public:
	void initial();  //初始化游戏相关信息
	void turns(Player &p, Player &p1, Player &p2);
	void rungame();  //运行游戏
	void gameover(int win);
	Manager();
	~Manager();
};

