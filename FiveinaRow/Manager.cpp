#include "Manager.h"
#include <iostream>
#include "Player.h"
#include "Display.h"
#include "Chess.h"
#include "T_tools.h"
#include "AI.h"
using namespace std;
using namespace Tts;

void Manager::initial()
{
	Display display;
	display.gameinfo();  //显示游戏信息
	bool istrue;
	do
	{
		istrue = false;
		cint >> model;  //输入游戏模式，并判断输入是否正确
		if (model != 1 && model != 2)
		{
			istrue = true;
			display.inerror();
		}
	} while (istrue);

	if (model == 1)  //人人对战模式
	{
		player1 = "human_1";
		color1 = "black";
		player2 = "human_2";
		color2 = "white";
	}
	else  //人机对战模式
	{
		int wfirst;
		display.wfirst();
		do
		{
			istrue = false;
			cint >> wfirst;  //选择先后顺序
			if (wfirst != 1 && wfirst != 2)
			{
				istrue = true;
				display.inerror();
			}
		} while (istrue);
		if (wfirst == 1)  //人先手
		{
			player1 = "Human";
			color1 = "black";
			player2 = "PC";
			color2 = "white";
		}
		else  //电脑先手
		{
			player1 = "PC";
			color1 = "black";
			player2 = "Human";
			color2 = "white";
		}
	}
}

void Manager::turns(Player &p, Player & p1, Player & p2)
{
	turn = -1 * turn;
	if (turn == 1) p = p1;
	else p = p2;
}

void Manager::rungame()
{
	initial();  //初始化

	Player player1(player1, color1);   //定义管理对象
	Player player2(player2, color2);
	Display display;
	Chess chess;
	AI ai;

	display.drawboard(chess);  //画出空棋盘
	while ((win = ai.judger(chess)) == 0)
	{
		turns(player, player1, player2);  //交换棋手
		display.playinfo(player);  //展示玩家信息

		if (player.P_name != "PC")  //如果玩家不是电脑
		{
			player.getposition();
			while (!chess.istrue(player))  //检查玩家落子是否正确
			{
				display.inerror();
				player.getposition();
			}
			chess.putstone(player);  //更新棋盘
		}
		else  //电脑玩家下子
		{
			ai.computer(player, chess);
			chess.putstone(player);  //更新棋盘
		}

		display.drawboard(chess);  //画出棋盘
	}  

	gameover(win);
}

void Manager::gameover(int win)
{
	Display display;
	if (win == 1)
		display.gameover(player1, color1);
	else
		display.gameover(player2, color2);
}

Manager::Manager()
{
}


Manager::~Manager()
{
}
