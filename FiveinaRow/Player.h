#pragma once
#include <string>
using namespace std;


class Player
{
public:
	string P_name; //�������
	string P_color; //���ִ����ɫ
	int P_x, P_y; //�������λ��


	void getposition();  //����������λ��
	Player();
	Player(string N_name, string N_color);
	Player(Player &p);
	~Player();
};

