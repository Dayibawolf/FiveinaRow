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
	display.gameinfo();  //��ʾ��Ϸ��Ϣ
	bool istrue;
	do
	{
		istrue = false;
		cint >> model;  //������Ϸģʽ�����ж������Ƿ���ȷ
		if (model != 1 && model != 2)
		{
			istrue = true;
			display.inerror();
		}
	} while (istrue);

	if (model == 1)  //���˶�սģʽ
	{
		player1 = "human_1";
		color1 = "black";
		player2 = "human_2";
		color2 = "white";
	}
	else  //�˻���սģʽ
	{
		int wfirst;
		display.wfirst();
		do
		{
			istrue = false;
			cint >> wfirst;  //ѡ���Ⱥ�˳��
			if (wfirst != 1 && wfirst != 2)
			{
				istrue = true;
				display.inerror();
			}
		} while (istrue);
		if (wfirst == 1)  //������
		{
			player1 = "Human";
			color1 = "black";
			player2 = "PC";
			color2 = "white";
		}
		else  //��������
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
	initial();  //��ʼ��

	Player player1(player1, color1);   //����������
	Player player2(player2, color2);
	Display display;
	Chess chess;
	AI ai;

	display.drawboard(chess);  //����������
	while ((win = ai.judger(chess)) == 0)
	{
		turns(player, player1, player2);  //��������
		display.playinfo(player);  //չʾ�����Ϣ

		if (player.P_name != "PC")  //�����Ҳ��ǵ���
		{
			player.getposition();
			while (!chess.istrue(player))  //�����������Ƿ���ȷ
			{
				display.inerror();
				player.getposition();
			}
			chess.putstone(player);  //��������
		}
		else  //�����������
		{
			ai.computer(player, chess);
			chess.putstone(player);  //��������
		}

		display.drawboard(chess);  //��������
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
