#pragma once
#include <string>
using namespace std;


class Player
{
public:
	string P_name; //玩家名称
	string P_color; //玩家执子颜色
	int P_x, P_y; //玩家落子位置


	void getposition();  //获得玩家落子位置
	Player();
	Player(string N_name, string N_color);
	Player(Player &p);
	~Player();
};

