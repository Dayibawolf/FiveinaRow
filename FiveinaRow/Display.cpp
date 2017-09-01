#include "Display.h"
#include <iostream>
#include <cstdlib>
using namespace std;



void Display::stone(int x, int y, int shape)  // x y Ϊ���ӵ�λ�����ꣻshapeΪ����������״
{
	switch (shape)  //������ʱ��������
	{
	case 0:
		if (x == 1)
		{
			if (y == 1)
			{
				cout << "�X";
			}
			else if (y == 15)
			{
				cout << "�[" << endl;
			}
			else
			{
				cout << "�h";
			}
		}
		else if (x == 15)
		{
			if (y == 1)
			{
				cout << "�^";
			}
			else if (y == 15)
			{
				cout << "�a" << endl;
			}
			else
			{
				cout << "�k";
			}
		}
		else
		{
			if (y == 1)
			{
				cout << "�c";
			}
			else if (y == 15)
			{
				cout << "�f" << endl;
			}
			else
			{
				cout << "��";
			}
		}
		break;

	case 1:  //���ʹ�ú���
		cout << "��";
		if (y == 15) cout << endl;
		break;

	case 2:   //���ʹ�ð���
		cout << "��";
		if (y == 15) cout << endl;
		break;

	default :
		break;
	}
}

//*********************************************************************************

void Display::drawboard(Chess &c)   //��������
{
	system("cls");
	cout << endl << "             *********���������塶��**********" << endl;
	for (int i = 1; i <= 15; i++)
	{
		if (i < 7)          //���Ȼ�����һ�����̱��
		{
			cout << (16 - i);
		}
		else
		{
			cout << " " << (16 - i); //���Ϊ��λʱ����������ո�
		}
		for (int j = 1; j <= 15; j++)
		{
			if (j > 1 && j <= 15)
			{
				if (i == 1 || i == 15)
				{
					cout << "�T";
				}
				else
				{
					cout << "��";
				}

			}
			stone(i, j, c.board[i-1][j-1]);  //����������Ϣȷ��������״
		}
		if (i < 15)
		{
			for (int j = 1; j <= 15; j++)
			{
				if (j == 1)
				{
					cout << "  �U ";
				}
				else if (j == 15)
				{
					cout << " �U";
				}
				else
				{
					cout << " �� ";
				}
			}
			cout << endl;
		}
	}
	cout << "  A   B   C   D   E   F   G   H   I   J   K   L   M   N   O" << endl; //�б������ĸ��ʾ
}

void Display::gameinfo()  //��ʾ��Ϸ��Ϣ����ʾ���ѡ����Ϸģʽ
{
	system("color F0");
	cout << "       **********==Game edited by Tao==************" << endl;
	cout << "����һ����������Ϸ������ѡ�����ֶ�սģʽ��" << endl;
	cout << "1����� VS ���" << endl << "2����� VS ����" << endl;
	cout << "��ѡ����Ϸģʽ��";
}

void Display::playinfo(Player & p)
{
	cout << "��ң�" << p.P_name<<"   ";
	if (p.P_color == "white")
		cout << "ִ�ӣ�" << "��" << endl;
	else
		cout << "ִ�ӣ�" << "��" << endl;
}

void Display::inerror()
{
	cout << "������󣡣�������������..." << endl;
}

void Display::wfirst()
{
	cout << "��ѡ�� 1������ 2�����֣�";
}

void Display::gameover(string player, string color)
{
	cout << "^_^ ^_^"<<"��Ϸ����������" << endl;
	cout << player << "��ʤ��" << endl;
}

Display::Display()
{
}


Display::~Display()
{
}
