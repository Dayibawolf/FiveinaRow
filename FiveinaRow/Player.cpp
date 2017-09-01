#include "Player.h"
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;


void Player::getposition()
{
	string str;
	char ch;
	cout << "请根据棋盘行列标号输入落子位置（行号 列号）：";
	while ((ch = getchar()) != '\n')
	{
		str += ch;
	}
	int t;
	while (t = str.find(' ', 0), t != str.npos)
	{
		str.erase(t, 1);
	}
	if (str.length() == 2)
	{
		P_x = int(str.at(0)) - 48;
		P_y = int(toupper(str.at(1))) - 64;
	}
	if (str.length() == 3)
	{
		P_x = int(str.at(0)) - 48;
		P_x = P_x * 10 + int(str.at(1)) - 48;
		P_y = int(toupper(str.at(2))) - 64;
	}
}

Player::Player()
{
}

Player::Player(string N_name, string N_color)
{
	P_name = N_name;
	P_color = N_color;
	P_x = 0;
	P_y = 0;
}

Player::Player(Player & p)
{
	P_name = p.P_name;
	P_color = p.P_color;
	P_x = p.P_x;
	P_y = p.P_y;
}


Player::~Player()
{
}
