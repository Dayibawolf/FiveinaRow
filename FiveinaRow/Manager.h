#pragma once
#include <string>
#include "Player.h"

class Manager
{
private:
	int model;  //��Ϸģʽ
	Player player;
	string player1, player2;  //�������
	string color1, color2;  //���������ɫ
	int turn = -1;  //����ֻ���־��1��player1 -1��player2
	int win;

public:
	void initial();  //��ʼ����Ϸ�����Ϣ
	void turns(Player &p, Player &p1, Player &p2);
	void rungame();  //������Ϸ
	void gameover(int win);
	Manager();
	~Manager();
};

