#include "Display.h"
#include <iostream>
#include <cstdlib>
using namespace std;



void Display::stone(int x, int y, int shape)  // x y 为棋子的位置坐标；shape为广义棋子形状
{
	switch (shape)  //无棋子时画出棋盘
	{
	case 0:
		if (x == 1)
		{
			if (y == 1)
			{
				cout << "╔";
			}
			else if (y == 15)
			{
				cout << "╗" << endl;
			}
			else
			{
				cout << "╤";
			}
		}
		else if (x == 15)
		{
			if (y == 1)
			{
				cout << "╚";
			}
			else if (y == 15)
			{
				cout << "╝" << endl;
			}
			else
			{
				cout << "╧";
			}
		}
		else
		{
			if (y == 1)
			{
				cout << "╟";
			}
			else if (y == 15)
			{
				cout << "╢" << endl;
			}
			else
			{
				cout << "┼";
			}
		}
		break;

	case 1:  //玩家使用黑子
		cout << "●";
		if (y == 15) cout << endl;
		break;

	case 2:   //玩家使用白子
		cout << "○";
		if (y == 15) cout << endl;
		break;

	default :
		break;
	}
}

//*********************************************************************************

void Display::drawboard(Chess &c)   //画出棋盘
{
	system("cls");
	cout << endl << "             *********》》五子棋《《**********" << endl;
	for (int i = 1; i <= 15; i++)
	{
		if (i < 7)          //首先画出第一列棋盘标号
		{
			cout << (16 - i);
		}
		else
		{
			cout << " " << (16 - i); //标号为各位时，首先输出空格
		}
		for (int j = 1; j <= 15; j++)
		{
			if (j > 1 && j <= 15)
			{
				if (i == 1 || i == 15)
				{
					cout << "═";
				}
				else
				{
					cout << "─";
				}

			}
			stone(i, j, c.board[i-1][j-1]);  //根据棋盘信息确定棋子形状
		}
		if (i < 15)
		{
			for (int j = 1; j <= 15; j++)
			{
				if (j == 1)
				{
					cout << "  ║ ";
				}
				else if (j == 15)
				{
					cout << " ║";
				}
				else
				{
					cout << " │ ";
				}
			}
			cout << endl;
		}
	}
	cout << "  A   B   C   D   E   F   G   H   I   J   K   L   M   N   O" << endl; //列标号用字母表示
}

void Display::gameinfo()  //显示游戏信息，提示玩家选择游戏模式
{
	system("color F0");
	cout << "       **********==Game edited by Tao==************" << endl;
	cout << "这是一个五子棋游戏，可以选择两种对战模式：" << endl;
	cout << "1：玩家 VS 玩家" << endl << "2：玩家 VS 电脑" << endl;
	cout << "请选择游戏模式：";
}

void Display::playinfo(Player & p)
{
	cout << "玩家：" << p.P_name<<"   ";
	if (p.P_color == "white")
		cout << "执子：" << "○" << endl;
	else
		cout << "执子：" << "●" << endl;
}

void Display::inerror()
{
	cout << "输入错误！！！请重新输入..." << endl;
}

void Display::wfirst()
{
	cout << "请选择 1：先手 2：后手：";
}

void Display::gameover(string player, string color)
{
	cout << "^_^ ^_^"<<"游戏结束！！！" << endl;
	cout << player << "获胜！" << endl;
}

Display::Display()
{
}


Display::~Display()
{
}
