#pragma once
#include "Player.h"
class Chess
{
public:
	int board[15][15];  //���̾���
	int count = 0;  //�����ܸ���
	int last_x, last_y;  //��������λ��

	bool istrue(Player &p);
	void putstone(Player &p);
	Chess();
	~Chess();
};

