#pragma once
#include "Chess.h"
#include "Player.h"
#include <string>
class Display
{
public:
	void stone(int x, int y, int shape);  //�������ӣ����壩λ�û����״
	void drawboard(Chess &c);  //��������
	void gameinfo();  //��ʾ��Ϸ��Ϣ
	void playinfo(Player &p);  //��ʾ�����Ϣ
	void inerror();  //��ʾ�������
	void wfirst();  //��ʾѯ����Ϣ��˭������
	void gameover(string player, string color);  //��ʾ��Ϸ������Ϣ
	Display();
	~Display();
};

